create database LAB5
USE LAB5
GO

CREATE TABLE Ta
(
	aid INT PRIMARY KEY IDENTITY,
	a2 INT UNIQUE,
	a3 INT
)

CREATE TABLE Tb
(
	bid INT PRIMARY KEY IDENTITY,
	b2 INT
)

CREATE TABLE Tc
(
	cid INT PRIMARY KEY IDENTITY,
	aid INT FOREIGN KEY REFERENCES Ta(aid),
	bid INT FOREIGN KEY REFERENCES Tb(bid)
)

SELECT * FROM Ta
SELECT * FROM Tb
SELECT * FROM Tc

--DROP TABLE Tc,Tb,Ta

GO
-- here we fill the tables
CREATE OR ALTER PROCEDURE fill_tables
	@row_count INT
AS
BEGIN
	DECLARE @value INT = 0
	SET NOCOUNT ON
	WHILE @value < @row_count
	-- filling tables Ta and Tb
	BEGIN
		INSERT INTO Ta (a2, a3) VALUES (@value, @value + 1000)
		INSERT INTO Tb (b2) VALUES (@value)
		SET @value = @value + 1
	END
	-- filling table Tc
	SET @value = 1
	DECLARE @second_value INT = 1
	WHILE @value < @row_count
	BEGIN
		SET @second_value = 1
		WHILE @second_value < @row_count
		BEGIN
			INSERT INTO Tc (aid,bid) VALUES (@value,@second_value)
			SET @second_value = @second_value + 1
		END
		SET @value = @value + 1
	END
END

EXEC fill_tables @row_count = 100


----------------------------------------------------A
GO
sp_helpindex Ta

--clustured index scan - all entries, sorted by aid, 

SELECT *
FROM Ta
ORDER BY aid

--clustured index seek 

SELECT *
FROM Ta
WHERE aid < 50

--nonclustured index scan

SELECT a2, aid
FROM Ta
ORDER BY a2

--nonclustered index seek

SELECT a2
FROM Ta
WHERE a2 > 55

--key lookup

SELECT a3
FROM Ta
WHERE a2 = 45 

----------------------------------------B
GO
sp_helpindex Tb

SELECT *
FROM Tb
WHERE b2 = 95

CREATE NONCLUSTERED INDEX IX_Tb_b2 ON Tb (b2)

DROP INDEX IX_Tb_b2 ON Tb




