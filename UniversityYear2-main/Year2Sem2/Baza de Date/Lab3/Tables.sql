create table Song(
id int identity(1,1) primary key,
songName varchar(50),
)
create table Artist(
id int identity(1,1) primary key,
artistName varchar(50),
idInstrument int foreign key references Instrument(id) not null
)

create table Instrument(
id int identity(1,1) primary key,
instrumentName varchar(50),
)

create table SongArtist(
id int identity(1,1) primary key,
idSong int foreign key references Song(id),
idArtist int foreign key references Artist(id),
)

create table Logger(
id int identity(1,1) primary key,
messageLogger varchar(1000),
timeLogger datetime default getdate(),
)
