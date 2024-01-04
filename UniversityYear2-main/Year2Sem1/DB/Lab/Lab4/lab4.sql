-- USE Lab4;

/*
	
*/

-- get columns will create a string containing the name of the columns as they should be passed to the insert statement
-- we take every column and insert it into the string, if it is not an identity column(for me -"self numbered")

CREATE OR ALTER PROCEDURE GetColumns
	@table_name varchar(150),
	@table_columns varchar(2000) OUTPUT,
	@table_values varchar(2000) OUTPUT
AS
	PRINT('Creating the columns and values string');
	SET @table_columns = ''
	SET @table_values = ''
	DECLARE @colum_name varchar(150), @data_type varchar(150)
	DECLARE @schema_table_name varchar(150) = CONCAT('dbo.', @table_name)
	--
	DECLARE C CURSOR LOCAL
	FOR SELECT COLUMN_NAME, DATA_TYPE FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME=@table_name ORDER BY COLUMN_NAME ASC;
	OPEN C
	FETCH NEXT FROM C INTO @colum_name, @data_type
	WHILE @@FETCH_STATUS = 0
		BEGIN
			IF COLUMNPROPERTY(OBJECT_ID(@schema_table_name), @colum_name, 'IsIdentity') = 0
			BEGIN
				SET @table_columns = (CONCAT(@table_columns, '[' + @colum_name + '], '))
			END
			FETCH NEXT FROM C INTO @colum_name, @data_type
		END
	CLOSE C
	DEALLOCATE C
	--
	SET @table_columns = SUBSTRING(@table_columns, 1, LEN(@table_columns) - 1)

	PRINT('Finished creating the columns and values string');
GO

-- we check if a column is a forein key
-- we check if the fk-constraint contains the name of the column
-- we use fk system table in order to check the column name
CREATE OR ALTER PROCEDURE ColumnIsForeignKey
	@colum_name varchar(150),
	@table_name varchar(150)
AS	
	DECLARE @isForeignKey int = 0
	SET @isForeignKey = (SELECT COUNT(*)
				FROM (SELECT [name] AS Foreign_Key  
						FROM sys.foreign_keys
						WHERE parent_object_id = OBJECT_ID(@table_name)
				) AS FKs
				WHERE CHARINDEX(@colum_name, FKs.Foreign_Key) > 0
	)

	PRINT(STR(@isForeignKey))
	IF @isForeignKey > 0
		RETURN 1
	RETURN 0
GO

-- radom number between min and max
CREATE OR ALTER PROCEDURE RangeRand
	@min int,
	@max int
AS
	RETURN (SELECT FLOOR(RAND())) * (@max - @min + 1) + @min;
GO
-- we get a valid random value for a column that is a fk using the data from the referenced column
-- we get the names of the table and the column that is referenced by the @cloumn_name
CREATE OR ALTER PROCEDURE GetRandomColumnForeignKey
	@table_name varchar(150),
	@colum_name varchar(150)
AS
	DECLARE @ref_table varchar(150)
	DECLARE @RefColumn varchar(150)
	DECLARE ForeignKeyCursor CURSOR FOR 
		SELECT OBJECT_NAME(referenced_object_id), ColumnName = (
			SELECT C.Column_Name from
			INFORMATION_SCHEMA.TABLE_CONSTRAINTS T,
			INFORMATION_SCHEMA.CONSTRAINT_COLUMN_USAGE C
			WHERE
				C.Constraint_Name = T.Constraint_Name 
				AND C.Table_Name = T.Table_Name
				AND Constraint_Type = 'PRIMARY KEY'
				AND C.Table_Name = OBJECT_NAME(referenced_object_id)
			)
		FROM sys.foreign_keys as FK
		WHERE parent_object_id = OBJECT_ID(@table_name) AND CHARINDEX(@colum_name, FK.[name]) > 0

	OPEN ForeignKeyCursor

	FETCH ForeignKeyCursor
	INTO @ref_table, @RefColumn
	-- we take the min and the max from the searched table and we get a random value between min and max
	CLOSE ForeignKeyCursor
	DEALLOCATE ForeignKeyCursor
	DECLARE @minimum int
	DECLARE @SqlCommandMin nvarchar(100) = N'SET @minimum = (SELECT MIN(' + @RefColumn + ') FROM ' + @ref_table + ')'
	EXECUTE sp_executesql @SqlCommandMin, N'@minimum int OUTPUT', @minimum = @minimum OUTPUT;
	DECLARE @maximum int
	DECLARE @SqlCommandMax nvarchar(100) = N'SET @maximum = (SELECT MAX(' + @RefColumn + ') FROM ' + @ref_table + ')'
	EXECUTE sp_executesql @SqlCommandMax, N'@maximum int OUTPUT', @maximum = @maximum OUTPUT;

	DECLARE @Value int
	EXEC @Value = RangeRand @min = @minimum, @max = @maximum;
	PRINT(' ' + CAST(@Value AS VARCHAR(100)) + ' ' + CAST(@minimum AS VARCHAR(100)) + ' ' + CAST(@maximum AS VARCHAR(100)))
	RETURN CAST(@Value AS VARCHAR(100))
GO

-- we add a random row in a table 
-- we go trought columns and we generate random values and we use dynamic queries to insert the row 
-- it's dynamic bcs it's a string
CREATE OR ALTER PROCEDURE AddRow
	@table_name varchar(150),
	@table_columns varchar(2000)
AS
	DECLARE @table_values varchar(2000) = ''
	DECLARE @colum_name varchar(150), @data_type varchar(150)
	DECLARE @schema_table_name varchar(150) = CONCAT('dbo.', @table_name)
	DECLARE @IsForeignKey int
	DECLARE @Value varchar(150)
	PRINT(@table_columns + ' -> ' + @table_values);
	--
	DECLARE C CURSOR LOCAL
	FOR SELECT COLUMN_NAME, DATA_TYPE FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME=@table_name ORDER BY COLUMN_NAME ASC;
	OPEN C
	FETCH NEXT FROM C INTO @colum_name, @data_type
	WHILE @@FETCH_STATUS = 0
		BEGIN
			EXEC @IsForeignKey = ColumnIsForeignKey @colum_name=@colum_name, @table_name=@table_name
			PRINT(@data_type)
			IF COLUMNPROPERTY(OBJECT_ID(@schema_table_name), @colum_name, 'IsIdentity') = 0 AND @IsForeignKey = 0
			BEGIN
				IF @data_type = 'int'
					SET @table_values = CONCAT(@table_values, CAST(RAND() AS VARCHAR(100)) + ', ')
				ELSE
					IF (@data_type = 'nvarchar' OR @data_type = 'nchar' OR @data_type = 'varchar' OR @data_type = 'char')
						SET @table_values = CONCAT(@table_values, '''' + CAST(RAND() AS VARCHAR(100)) + ''', ')
					ELSE 
						SET @table_values = CONCAT(@table_values, 'CAST('''' AS ' + @data_type + '), ') 
			END
			
			IF @IsForeignKey = 1
			BEGIN
				EXEC @Value = GetRandomColumnForeignKey @table_name=@table_name, @colum_name=@colum_name
				PRINT('FOREIGN')
				SET @table_values = CONCAT(@table_values, @Value + ', ')
			END
			FETCH NEXT FROM C INTO @colum_name, @data_type
		END
	CLOSE C
	DEALLOCATE C
	--
	SET @table_values = SUBSTRING(@table_values, 1, LEN(@table_values) - 1)
	PRINT(@table_columns + ' -> ' + @table_values);
	EXEC ('INSERT INTO ' + @table_name + ' (' + @table_columns + ') VALUES (' + @table_values + ')');
GO

/*
we fill the test  tables with the data passed as params 
we split the strings to get the data 
*/
CREATE OR ALTER PROCEDURE PrepareTest
	@info_table varchar(2000),
	@view_info varchar(2000),
	@test_name varchar(100)
AS
	-- Adding the tables
	PRINT('Preparing the test tables...');
	DECLARE @table_name varchar(100)
	DECLARE @NoRows int
	DECLARE @Pos int
	DECLARE @ShouldStop int = 0
	DECLARE @TableId int = 0
	DECLARE @Position int = 1
	INSERT INTO Tests ([Name]) VALUES(@test_name)
	DECLARE @TestID int = SCOPE_IDENTITY();
	WHILE @ShouldStop = 0
	BEGIN
		SET @Pos = CHARINDEX(' ', @info_table)
		SET @table_name = SUBSTRING(@info_table, 1, @Pos - 1)
		SET @info_table = SUBSTRING(@info_table, @Pos + 1, 9999);
		SET @Pos = CHARINDEX(' ', @info_table)
		IF @Pos = 0
		BEGIN
			SET @Pos = 99999
			SET @ShouldStop = 1
		END
		SET @NoRows = CAST(SUBSTRING(@info_table, 1, @Pos) AS INT)
		PRINT(@table_name)
		PRINT(@NoRows)
		IF @ShouldStop = 0
		BEGIN
			SET @Pos = CHARINDEX(' ', @info_table)
			SET @info_table = SUBSTRING(@info_table, @Pos + 1, 9999);
		END
		-- Got the table name and no of rows;
		-- inserting table if doesn't exist already
		IF (SELECT Count(*) FROM [Tables] WHERE [Name]=@table_name) = 0
			INSERT INTO [Tables] ([Name]) VALUES(@table_name)
		SET @TableId = (SELECT TableID FROM [Tables] WHERE [Name]=@table_name)
		INSERT INTO TestTables (TestID, TableID, NoOfRows, Position) VALUES (@TestID, @TableId, @NoRows, @Position);
		SET @Position = @Position + 1
	END
	PRINT('Preparing the test views...');
	-- Adding the views
	DECLARE @ViewName varchar(100)
	DECLARE @ViewId int
	SET @ShouldStop = 0
	WHILE @ShouldStop = 0
	BEGIN
		SET @Pos = CHARINDEX(' ', @view_info)
		IF @Pos = 0
		BEGIN
			SET @Pos = 99999
			SET @ShouldStop = 1
		END
		SET @ViewName = SUBSTRING(@view_info, 1, @Pos - 1)
		PRINT(@ViewName)
		IF @ShouldStop = 0
		BEGIN
			SET @Pos = CHARINDEX(' ', @view_info)
			SET @view_info = SUBSTRING(@view_info, @Pos + 1, 9999);
		END
		IF (SELECT Count(*) FROM [Views] WHERE [Name]=@ViewName) = 0
			INSERT INTO [Views] ([Name]) VALUES(@ViewName)
		SET @ViewId = (SELECT ViewID FROM [Views] WHERE [Name]=@ViewName)
		INSERT INTO TestViews (TestID, ViewID) VALUES (@TestID, @ViewId);
	END
	PRINT('Finished preparing the test tables...');
	RETURN @TestId
GO
-- we generate a number of random rows with the help of the function add row 
CREATE OR ALTER PROCEDURE GenerateRandomRows
	@table_name varchar(100),
	@Count int
AS
	DECLARE @table_columns varchar(1000)
	DECLARE @table_values varchar(1000) = ''
	DECLARE @NextVal int = 1
	--
	EXEC dbo.GetColumns @table_name = @table_name, @table_columns = @table_columns OUTPUT, @table_values = @table_values OUTPUT;
	--
	PRINT('Adding rows...');
	PRINT(@table_columns)
	WHILE @NextVal <= @Count
	BEGIN
		--DECLARE @Replaced varchar(1500) = (SELECT REPLACE(@table_values, '[[@Value]]', STR(@NextVal)));
		--EXEC ('INSERT INTO ' + @table_name + ' (' + @table_columns + ') VALUES (' + @Replaced + ')');
		EXEC AddRow @table_name = @table_name, @table_columns = @table_columns
		SET @NextVal = @NextVal + 1
		PRINT('Inserting rows in ' + @table_name + '. Added ' + CAST(@NextVal AS varchar(100)) + ' so far');
	END
GO
-- runs the actual test 
-- we create a row in test runs and for each table in each of the test tables (same for views) and we see how long it takes them to execute (to fill them with random rows) using the sysdatetime function
CREATE OR ALTER PROCEDURE RunTest
	@info_table varchar(2000),
	@view_info varchar(2000),
	@test_name varchar(100)
AS
	DECLARE @TestId int
	EXEC @TestId = PrepareTest @info_table = @info_table, @view_info = @view_info, @test_name = @test_name
	DECLARE @TableId int, @NoOfRows int, @Name varchar(150)
	DECLARE @Start datetime2, @End datetime2;
	--
	INSERT INTO TestRuns (Description, StartAt, EndAt) VALUES(STR(@TestID), SYSDATETIME(), '');
	DECLARE @TestRunID int = SCOPE_IDENTITY();
	--
	DECLARE C CURSOR LOCAL
	FOR SELECT T.TableId, NoOfRows, T.[Name] AS TableName
	FROM TestTables AS TT
	INNER JOIN [Tables] AS T ON T.TableId = TT.TableId
	WHERE TestID = @TestID 
	ORDER BY Position ASC;
	OPEN C
	FETCH NEXT FROM C INTO @TableId, @NoOfRows, @Name
	WHILE @@FETCH_STATUS = 0
		BEGIN
			EXEC ('DELETE FROM ' + @Name);
			SET @Start = SYSDATETIME()
			EXEC GenerateRandomRows @table_name = @Name, @Count = @NoOfRows
			SET @End = SYSDATETIME()
			INSERT INTO TestRunTables (TestRunID, TableID, StartAt, EndAt) VALUES(@TestRunID, @TableId, @Start, @End);
			FETCH NEXT FROM C INTO @TableId, @NoOfRows, @Name
		END
	CLOSE C
	DEALLOCATE C
	--
	DECLARE @ViewId int
	DECLARE C CURSOR LOCAL
	FOR SELECT V.Name, V.ViewID
	FROM TestViews AS TV
	INNER JOIN [Views] AS V ON V.ViewID = TV.ViewID
	WHERE TestId = @TestID;
	OPEN C
	FETCH NEXT FROM C INTO @Name, @ViewId
	WHILE @@FETCH_STATUS = 0
		BEGIN
			SET @Start = SYSDATETIME()
			EXEC ('SELECT * FROM ' + @Name);
			SET @End = SYSDATETIME()
			INSERT INTO TestRunViews (TestRunID, ViewID, StartAt, EndAt) VALUES(@TestRunID, @ViewId, @Start, @End);
			FETCH NEXT FROM C INTO @Name, @ViewId
		END
	CLOSE C
	DEALLOCATE C
	--
	UPDATE TestRuns SET EndAt = SYSDATETIME() WHERE TestRunID = @TestRunID;
GO

CREATE TABLE FirstTable (
	F1Column int PRIMARY KEY IDENTITY,
	F2Column varchar(30),
	F3Column datetime,
);

CREATE TABLE SecondTable (
	S1Column int PRIMARY KEY IDENTITY,
	S2Column int,
	S3Column datetime,
	CONSTRAINT FK_S2Column FOREIGN KEY (S2Column) REFERENCES FirstTable(F1Column) ON DELETE CASCADE
);

CREATE TABLE ThirdTable (
	T1Column int IDENTITY,
	T2Column nchar(30),
	T3Column datetime2,
	PRIMARY KEY (T1Column, T2Column)
);

CREATE VIEW FirstView AS
SELECT * FROM FirstTable;

CREATE VIEW SecondView AS
SELECT FT.F1Column, SC.S3Column
FROM FirstTable AS FT
INNER JOIN SecondTable AS SC ON FT.F1Column = SC.S2Column

CREATE OR ALTER VIEW ThirdView AS
SELECT F.[Date], COUNT(*) AS 'Count'
FROM (
	SELECT T1Column AS [Number], T3Column AS [Date]
	FROM ThirdTable AS TT
	UNION 
	SELECT S2Column AS [Number], S3Column AS [Date]
	FROM SecondTable AS ST
) AS F
GROUP BY F.Date

INSERT INTO [Views] ([Name]) VALUES ('FirstView'), ('SecondView'), ('ThirdView');
INSERT INTO [Tables] ([Name]) VALUES ('FirstTable'), ('SecondTable'), ('ThirdTable');
INSERT INTO Tests ([Name]) VALUES ('First test'), ('Second test');
INSERT INTO Tests ([Name]) VALUES ('Third test');
INSERT INTO TestViews (ViewID, TestID) VALUES (1, 1);
INSERT INTO TestViews (ViewID, TestID) VALUES (2, 2);
INSERT INTO TestViews (ViewID, TestID) VALUES (3, 3);
INSERT INTO TestTables (TestID, TableID, NoOfRows, Position) VALUES (1, 1, 10000, 1), (1, 2, 10000, 2), (2, 3, 15000, 1), (3, 1, 100000, 1);
EXEC RunTest @TestID = 1;

USE Lab4;
DELETE FROM TestRunTables;
DELETE FROM TestRunViews;
DELETE FROM TestViews;
DELETE FROM TestTables;
DELETE FROM [Tables];
DELETE FROM [Views];
DELETE FROM Tests;
DELETE FROM TestRuns;
EXEC RunTest @info_table='FirstTable 100 SecondTable 100 ThirdTable 100', @view_info='FirstView SecondView', @test_name='The Test';
/*

- extra procedure impelmented with runtest
- use random data from the system catalog having the same data type 
- extra description

*/

-- string split

SELECT * FROM [Tables];











