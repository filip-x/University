USE Sem2Lab3;
GO


CREATE OR ALTER PROCEDURE ValidateString
	@String varchar(100)
AS
BEGIN
	DECLARE @Length int = LEN(@String);
	IF @Length = 0
		RAISERROR('Invalid string was sent as a parameter!', 11, 1)
	ELSE
		RETURN 0
END
GO

CREATE OR ALTER PROCEDURE LoggerProcedure
	@mesLoger varchar(1000)
AS
BEGIN  
	PRINT(@mesLoger);
	INSERT INTO Logger(messageLogger) VALUES (@mesLoger);
END; 
GO

CREATE OR ALTER PROCEDURE ClearInsertWithRollback
AS
BEGIN
	DELETE FROM SongArtist;
	DELETE FROM Song;
	DELETE FROM Artist;
	
	EXEC LoggerProcedure'Cleared the tables Song, Artist, SongArtist';
END
GO


CREATE OR ALTER PROCEDURE InsertWithRollBack
	@artistName varchar(50),
	@songName varchar(50),
	@instrumentName varchar(50)
AS
	BEGIN TRY
		EXEC LoggerProcedure'Validating the Song name...';
		EXEC ValidateString @songName;
		EXEC LoggerProcedure'Validating the Artist name...';
		EXEC ValidateString @artistName;
		EXEC LoggerProcedure'Validating the Instrument name...';
		EXEC ValidateString @instrumentName;
		EXEC LoggerProcedure'All parameters have passed validation!';
		EXEC LoggerProcedure'Beginning to insert...';
		BEGIN TRANSACTION __Transaction
			BEGIN TRY
				-- Insert into Song
				EXEC LoggerProcedure'Inserting the Song...';
				INSERT INTO Song(SongName)
				Values (@songName);

				-- Insert into Artist
				EXEC LoggerProcedure'Inserting the Artist...';
				INSERT INTO Artist (artistName,idInstrument)
				VALUES (
					@artistName, 
					(SELECT id FROM Instrument WHERE instrumentName = @instrumentName)
				);


				EXEC LoggerProcedure'Inserting the pairs into the SongArtist...';
				-- Insert into SongArtist
				INSERT INTO SongArtist(idSong,idArtist)
				VALUES (
					(SELECT id FROM Song WHERE songName = @songName), 
					(SELECT id FROM Artist WHERE artistName = @artistName)
					);
				EXEC LoggerProcedure'Succesfully inserted everything!';
				COMMIT TRANSACTION __Transaction
			END TRY
			BEGIN CATCH
				DECLARE @messageError varchar(1000);
				SELECT @messageError = ERROR_MESSAGE();
				EXEC LoggerProcedure @messageError;
				EXEC LoggerProcedure'Something went wrong... Rolling back...';
				ROLLBACK TRANSACTION __Transaction
			END CATCH
	END TRY
	BEGIN CATCH
		DECLARE @messageError2 varchar(1000);
		SELECT @messageError2 = ERROR_MESSAGE();
		EXEC LoggerProcedure @messageError2;
		EXEC LoggerProcedure'Failed to validate all of the parameters! Invalid parameter discovered!';
	END CATCH
GO


-- Should execute succesfully
EXEC InsertWithRollBack  'The Motans','Maraton','Pian';
EXEC ClearInsertWithRollback;

-- Should not execute succesfully
EXEC InsertWithRollBack  'The Motans', 'Maraton', '.';
EXEC ClearInsertWithRollback;

SELECT * FROM Song;
SELECT * FROM Artist;
SELECT * FROM SongArtist;