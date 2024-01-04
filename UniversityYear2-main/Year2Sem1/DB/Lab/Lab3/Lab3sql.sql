--a
CREATE OR ALTER PROCEDURE USP_modify_type
AS
	ALTER TABLE test
	ALTER COLUMN firstc varchar(17);
GO
--undo
CREATE OR ALTER PROCEDURE USP_modify_type_undo
AS
	ALTER TABLE test
	ALTER COLUMN firstc int;
GO

--b-add
CREATE OR ALTER PROCEDURE USP_add
AS
	ALTER TABLE test
	ADD secondc int;
GO
--undo
CREATE OR ALTER PROCEDURE USP_add_undo
AS
	ALTER TABLE test
	DROP COLUMN secondc;
GO

--b-remove
CREATE OR ALTER PROCEDURE USP_remove
	
AS
	ALTER TABLE test
	DROP COLUMN thirdc;
	
GO
--undo
CREATE OR ALTER PROCEDURE USP_remove_undo
AS
	ALTER TABLE test
	ADD thirdc int;
GO
--c-add
CREATE OR ALTER PROCEDURE USP_add_default_constraint
AS
	ALTER TABLE test
	ADD CONSTRAINT default_Fourth
	DEFAULT 'Nothing' FOR fourthc;
	
GO
--undo
CREATE OR ALTER PROCEDURE USP_add_default_constraint_undo

AS
	ALTER TABLE test
	DROP CONSTRAINT default_fourth;
GO
--c-remove
CREATE OR ALTER PROCEDURE USP_remove_default_constraint

AS
	ALTER TABLE test
	DROP CONSTRAINT default_fifth;
GO
--undo
CREATE OR ALTER PROCEDURE USP_remove_default_constraint_undo
AS
	ALTER TABLE test
	ADD CONSTRAINT default_fifth
	DEFAULT 'Something' FOR fifthc;
GO
--d-add
CREATE OR ALTER PROCEDURE USP_add_pk
AS
	ALTER TABLE Test
	ADD CONSTRAINT pk_sixth PRIMARY KEY (sixthc);
	
GO
--undo
CREATE OR ALTER PROCEDURE USP_add_pk_undo
AS
	ALTER TABLE test
	DROP CONSTRAINT pk_sixth;
GO
--d-remove
CREATE OR ALTER PROCEDURE USP_remove_pk
AS
	ALTER TABLE test
	DROP CONSTRAINT pk_seventh;
GO
--undo
CREATE OR ALTER PROCEDURE USP_remove_pk_undo
AS
	ALTER TABLE test
	ADD CONSTRAINT pk_seventh PRIMARY KEY (seventhc);
GO
--e-add
CREATE OR ALTER PROCEDURE USP_add_candkey
	
AS
	ALTER TABLE test
	ADD CONSTRAINT ck_eighth UNIQUE (eighthc);
	
GO
--undo
CREATE OR ALTER PROCEDURE USP_add_candkey_undo
AS
	ALTER TABLE test
	DROP CONSTRAINT ck_eighth;
GO
--e-remove
CREATE OR ALTER PROCEDURE USP_remove_candkey
	
AS
	ALTER TABLE test
	DROP CONSTRAINT candidatekey_ninth;
	
GO
--undo
CREATE OR ALTER PROCEDURE USP_remove_candkey_undo
AS
	ALTER TABLE test
	ADD CONSTRAINT candidatekey_ninth UNIQUE (ninthc);
GO
--f-add
CREATE OR ALTER PROCEDURE USP_add_fk
	
AS
	ALTER TABLE test
	ADD CONSTRAINT fk_tenth FOREIGN KEY (tenthc) REFERENCES Test_addfk(id);
	
GO
--undo
CREATE OR ALTER PROCEDURE USP_add_fk_undo
AS
	ALTER TABLE test
	DROP CONSTRAINT fk_tenth;
GO
--f-remove
CREATE OR ALTER PROCEDURE USP_remove_fk
	
AS
	ALTER TABLE test
	DROP CONSTRAINT fk_eleventh;
	
GO
--undo
CREATE OR ALTER PROCEDURE USP_remove_fk_undo
AS
	ALTER TABLE test
	ADD CONSTRAINT fk_eleventh FOREIGN KEY (eleventhc) REFERENCES test_removefk(id);
GO

--g-create
CREATE OR ALTER PROCEDURE USP_create
AS
	CREATE TABLE create_test (
		fake_id int
	);
GO
--undo
CREATE OR ALTER PROCEDURE USP_create_undo
AS
	DROP TABLE IF EXISTS create_test;
GO
--g-drop
CREATE OR ALTER PROCEDURE USP_drop
	
AS
	DROP TABLE IF EXISTS drop_test;
GO
--undo
CREATE OR ALTER PROCEDURE USP_drop_undo
AS
	CREATE TABLE drop_test (
		fake_id int
	);
GO
--################################################

CREATE OR ALTER PROCEDURE USP_execute
	@command varchar(100)
AS
	EXEC @command
	INSERT INTO versions VALUES ((SELECT [value] FROM last_v_nr),@command);
	UPDATE last_v_nr SET [value] = [value] + 1;
	PRINT @command
go

CREATE OR ALTER PROCEDURE USP_return_prev_versions
	@return_v int
AS
	DECLARE @count int
	DECLARE @version_nr int
	DECLARE @undo_command varchar(100)
	DECLARE @redo_command varchar(100)
	DECLARE @command varchar(100)

	SET @count = (SELECT COUNT(*) FROM versions);

	IF @return_v > @count OR @return_v < 0
	BEGIN     
		PRINT 'Cannot return to that version!'
	END
	ELSE
	BEGIN
		DECLARE @current_version_nr int = (SELECT [value] FROM last_v_nr)
		IF @return_v < @current_version_nr
		BEGIN -- CASE FOR UNDOING
			DECLARE version_cursor CURSOR FOR  
			SELECT * FROM versions WHERE version_nr < @current_version_nr ORDER BY version_nr desc;  
  
			OPEN version_cursor;  
			FETCH NEXT FROM version_cursor INTO @version_nr, @command;
			WHILE @@FETCH_STATUS = 0 AND @version_nr > @return_v
			BEGIN  
				SET @undo_command = CONCAT(@command,'_undo')
				EXEC @undo_command
				UPDATE last_v_nr SET [value] = [value] - 1;
				PRINT @undo_command
				FETCH NEXT FROM version_cursor INTO @version_nr, @command;
			END
			PRINT 'Returned succesfully to the specified version number'
			--DELETE FROM Versions WHERE VersionNumber > @ReturnVersion;
			CLOSE version_cursor;
			DEALLOCATE version_cursor;
		END
		ELSE
		BEGIN -- CASE FOR REDOING
			DECLARE version_cursor CURSOR FOR  
			SELECT * FROM versions WHERE version_nr >= @current_version_nr ORDER BY version_nr asc;  
  
			OPEN version_cursor;  
			FETCH NEXT FROM version_cursor INTO @version_nr, @command;
			WHILE @@FETCH_STATUS = 0 AND @version_nr <= @return_v
			BEGIN
				SET @redo_command = @command
				EXEC @redo_command 
				UPDATE last_v_nr SET [value] = [value] + 1;
				PRINT @redo_command
				FETCH NEXT FROM version_cursor INTO @version_nr, @command;
			END
			PRINT 'Returned succesfully to the specified version number'
			--DELETE FROM Versions WHERE VersionNumber > @ReturnVersion;
			CLOSE version_cursor;
			DEALLOCATE version_cursor;
		END
	END
GO

EXEC USP_execute 'USP_modify_type'
EXEC USP_execute 'USP_add'
EXEC USP_execute 'USP_remove'
EXEC USP_execute 'USP_add_default_constraint'
EXEC USP_execute 'USP_remove_default_constraint'
EXEC USP_execute 'USP_remove_pk'
EXEC USP_execute 'USP_add_pk'
EXEC USP_execute 'USP_add_candkey'
EXEC USP_execute 'USP_remove_candkey'
EXEC USP_execute 'USP_add_fk'
EXEC USP_execute 'USP_remove_fk'
EXEC USP_execute 'USP_create'
EXEC USP_execute 'USP_drop'

EXEC USP_return_prev_versions 27


CREATE TABLE test_removefk(
	id int PRIMARY KEY
);
CREATE TABLE test_addfk(
	id int PRIMARY KEY
);
CREATE TABLE drop_test(
	fake_id int PRIMARY KEY
);
CREATE TABLE test (
	firstc int,
	thirdc int,
	fourthc varchar(30),
	fifthc varchar(30) CONSTRAINT default_fifth DEFAULT 'Something',
	sixthc int NOT NULL,
	seventhc int NOT NULL CONSTRAINT pk_seventh PRIMARY KEY,
	eighthc int,
	ninthc int CONSTRAINT candidatekey_ninth UNIQUE,
	tenthc int,
	eleventhc int CONSTRAINT fk_eleventh FOREIGN KEY REFERENCES test_removefk(id),
);
CREATE TABLE versions(
	version_nr int PRIMARY KEY,
	command varchar(100)
);
CREATE TABLE last_v_nr(
	[value] int,
);
DELETE last_v_nr
INSERT INTO last_v_nr VALUES(1);
DROP TABLE test;
UPDATE last_v_nr SET [value] = 1;
DELETE FROM versions;

use TEST

