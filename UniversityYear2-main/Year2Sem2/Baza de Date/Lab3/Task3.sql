use Sem2Lab3
go

-- READ = a select
-- WRITE = upate, insert, delete

-- READ -> shared lock (can read from multiple transactions but cannot write)
-- WRITE -> exclusive lock (can not operate on the locked rows from other transactions)
----------------
-- Dirty reads

-- Only happens on ISOLATION LEVEL READ UNCOMMITED
SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED

-- Fix by using any other isolation level, such as ISOLATION LEVEL READ COMMITED
SET TRANSACTION ISOLATION LEVEL READ COMMITTED

INSERT INTO Song (songName) VALUES ('TestSong Initial');
DELETE FROM Song WHERE songName LIKE 'TestSong%';

-- File 1
BEGIN TRANSACTION __DirtyRead1
	UPDATE Song
	SET songName = 'TestSong Modified'
	WHERE songName = 'TestSong Initial'
-- Rollback later
ROLLBACK TRANSACTION __DirtyRead1

-- File 2
BEGIN TRANSACTION __DirtyRead2
	SELECT * FROM Song -- shared lock
-- Continue running after rollbacking
	SELECT * FROM Song
COMMIT TRANSACTION __DirtyRead2 

-- End of dirty reads
-----------------------



-------------------------
-- Non repeatable reads

-- Can only happen at the isolation levels READ COMMITED and READ UNCOMMITED
SET TRANSACTION ISOLATION LEVEL READ COMMITTED

-- Use any other level to fix this
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ

-- File 1
INSERT INTO Song (songName) VALUES ('TestRepRead Initial');
DELETE FROM Song WHERE songName LIKE 'TestRepRead%';

BEGIN TRANSACTION __NonRepeatableRead1
	SELECT * FROM Song -- shared lock

	SELECT * FROM Song
COMMIT TRANSACTION __NonRepeatableRead1

DELETE FROM Song WHERE songName LIKE 'TestRepRead%'

-- File 2
BEGIN TRANSACTION __NonRepeatableRead2
	UPDATE Song
	SET songName = 'TestRepRead Modified'
	WHERE songName = 'TestRepRead Initial'
COMMIT TRANSACTION __NonRepeatableRead2

-- End non repeatable reads
-----------------------------


------------------
-- Phantom reads

-- Can only happen at isolation levels READ UNCOMMITED, READ COMMITED, REPEATABLE READ
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ

-- Fix: Use isolation level SERIALIZABLE
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE

-- INSERT INTO Song (songName) VALUES ('PhantomReadStays');
DELETE FROM Song WHERE songName = 'PhantomReadNew'
-- File 1
BEGIN TRANSACTION __PhantomRead1
	SELECT * FROM Song
	WHERE songName LIKE 'PhantomRead%'

	SELECT * FROM Song
	WHERE songName LIKE 'PhantomRead%'
COMMIT TRANSACTION __PhantomRead1

-- File 2
BEGIN TRANSACTION __PhantomRead2
	INSERT INTO Song (songName) VALUES  ('PhantomReadNew')
COMMIT TRANSACTION __PhantomRead2

-- End phantom reads
----------------------





-------------
-- Deadlock

-- Occurs when 2 transactions try to acquire exclusive locks over the same resource

-- Can't totally prevent them, but can manage them using the following command:
SET DEADLOCK_PRIORITY HIGH
SET DEADLOCK_PRIORITY LOW
SET DEADLOCK_PRIORITY MEDIUM
-- The transaction with the least priority will be chosen as a victim and be rollbacked

INSERT INTO Song (songName) VALUES ('Deadlock1Initial');
INSERT INTO Artist (artistName, idInstrument) VALUES ('Deadlock2Initial', 1);
DELETE FROM Song WHERE songName LIKE 'Deadlock%';
DELETE FROM Artist WHERE artistName LIKE 'Deadlock%';

-- File 1
BEGIN TRANSACTION __Deadlock1
	UPDATE Song SET songName = 'Deadlock1Modified' WHERE songName = 'Deadlock1Initial'

	UPDATE Artist SET artistName = 'Deadlock2Modified' WHERE artistName = 'Deadlock2Initial'
COMMIT TRANSACTION __Deadlock1

-- File 2
BEGIN TRANSACTION __Deadlock2
	UPDATE Artist SET artistName = 'Deadlock2Modified' WHERE artistName = 'Deadlock2Initial'
	
	UPDATE Song SET songName = 'Deadlock1Modified' WHERE songName = 'Deadlock1Initial'
COMMIT TRANSACTION __Deadlock2

-- End deadlock
-----------------

