use Sem2Lab3
go

-- Update conflict can happen at a high isolation level such as 
-- snapshot because, in this isolation level, the present transaction
-- will not see changes done by other transactions, after it started.

ALTER DATABASE Sem2Lab3 SET ALLOW_SNAPSHOT_ISOLATION ON
ALTER DATABASE Sem2Lab3 SET ALLOW_SNAPSHOT_ISOLATION OFF
SET TRANSACTION ISOLATION LEVEL SNAPSHOT
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE

INSERT INTO Artist (artistName, idInstrument) VALUES ('UpdateConflictInitial', 1);
DELETE FROM Artist WHERE artistName LIKE 'UpdateConflict%';

-- File 1
BEGIN TRANSACTION __UpdateConflict1
	SELECT *
	FROM Artist
	WHERE artistName LIKE 'UpdateConflict%'

	UPDATE Artist
	SET artistName = 'UpdateConflictModifiedTwice'
	WHERE artistName LIKE 'UpdateConflict%'
COMMIT TRANSACTION __UpdateConflict1


-- File 2
BEGIN TRANSACTION __UpdateConflict2
	UPDATE Artist
	SET artistName = 'UpdateConflictModified'
	WHERE artistName LIKE 'UpdateConflict%'
COMMIT TRANSACTION __UpdateConflict2