use Spopple_Music
go


--insert that violates foreign key constraint integrity
insert into Song_Artist(Song_id,Artist_id)
values(200,200);

insert into Song(Song_name,Song_duration) values ('Lonely',2.29),('Intentions',3.33);
insert into Playlist(Playlist_name) values ('Hype'),('NF Real Music'),('Trap'),('Hit That Beat'),('I know, right?');
insert into Category(Name_type) values ('Classic');



--update  nr_1 we will use '=' & 'and'
update Song
set Song_name = 'Nate'
where Song_duration =3.02  and Song_name = 'Green Lights';


--update nr_2 we will use 'IS NOT NULL' & 'and' & 'berween'
update Band
set Band_name ='The Beatles'
where Band_name is not null and Band_name between 15 and 25;

--update  nr_3 we will use 'OR' and 'LIKE' 
update Artist
set Artist_name = 'NF-Real Music'
where Artist_name like 'N%' or Artist_name like '%F';

-- delete nr_1 we wil use <
delete from Band
where Nr_of_albums < 5;


--delete nr_2 we will use "IN"
delete from Category
where Name_type in('Rock','Jazz','House');

--a
-- if i don't write as and the name of the column it will give no column name
-- the actual id is 4 but we add 500 to that 4 and it will be 504

-- we get all song id from song and song_artist in which  songs have duration smaller then2 and song_id=4 or artist_id =3
--union(toate din a cu toate din b)
select Song_id + 500 as 'Song_id'
from Song
where Song_duration < 2
union
select Song_id + 500 as 'Song_id'
from Song_Artist
where Song_id  = 4 or Artist_id = 3;

--we get all artist id where artist_id  = 1  and Song_artist_1 =1 or SongArtist_id=2
--union(toate din a cu toate din b)fara duplicates
select Artist_id
from Artist
where Artist_id = 1
union 
select Artist_id
from Song_Artist
where Song_Artist_id = 1 or Song_Artist_id = 2;

--b

--playlists and album that have incommon a song
--intersect(ce ii in amandoua)
select Song_id
from Album_Song
where Song_id = 2
intersect
select Song_id
from Song_Playlist
where Song_id = 1 or Song_id = 2;

--we get all songs_id that are in a playlist and that are in Song_Category(as in the example)
select Song_id
from Song_Playlist
where Song_id in (1,7)
intersect
select Song_id
from Song_Category
where Song_id in (1,2,3,4,5,7);


--c
--we get all album_id that have songs and are  made by artist_id 1,2
-- it has a double negation so we get all the astist_id that are in 1,2
--except( ce ii in a,dar nu in b)
select Album_id
from Album_Song
except
select Album_id
from Album
where Artist_id not in(1,2);

--we get all artists that have songs and have don't have a name different from NF or eminem
-- we get the artist id that has songs and it's name is nf and eminem( or anonim author )
select Artist_id
from Song_Artist
except
select Artist_id
from Artist
where Artist_name not in('NF','Eminem');

--d 

--3 tables 
-- makes the connection from song,song_category, category
--inner join we get all song names and the category name
select DISTINCT Song_name,C.Name_type
from Song as S
inner join Song_Category as SC on S.Song_id = SC.Song_id 
inner join Category as C on SC.Category_id = C.Category_id;

--we get the result from song and maching rows from album
--left join we get the album in witch every song is
select Song_name,Album_id
from Song as S
left join Album_Song as A_S on A_S.Song_id = S.Song_id; 

--we show all songs, if there are in a playlist it will showa number else null
--right join get all the song from a playlist
select Song_name,Playlist_id
from Song_Playlist as SP
right join Song as  S on S.Song_id = SP.Playlist_id; 

--we get all artist all songs and all category :))
--and show matches if there is more then 2 values on the same row
--many to many
--full join 
select DISTINCT Artist_name,SA.Song_id,SC.Category_id
from Artist as A
full join Song_Artist as SA on SA.Artist_id = A.Artist_id
full join Song_Category as SC on SC.Song_id = SA.Song_id;
-- it's one query but there are 2  many to many relations 
--e
--we get the song name of where a song is in a playlist and the playist name is NF Real Music
select DISTINCT Song_name
from Song
where Song_id in (
	select Song_id
	from Song_Playlist
	where Playlist_id =(
		select Playlist_id
		from Playlist
		where Playlist_name = 'NF Real Music'));

-- we get all song_name where category is POP
select Song_name
from Song
where Song_id in (
	select Song_id
	from Song_Category
	where Category_id =(
		select Category_id
		from Category
		where Name_type = 'Pop'));

--f
--we get the first 3 songs that don't exist in playlists orderd by the names 
select TOP 3 Song_name
from Song as Sg
where not exists (
	select *
	from Song_Playlist
	where Song_id = Sg.Song_id)
order by Song_name asc;

-- we get the first song that does not 'exist' in any album orderd by the song duration (desc)
select TOP 1 Song_name
from Song as Sg
where not exists (
	select *
	from Album_Song
	where Song_id = Sg.Song_id)
order by Song_duration desc;

--g
-- we get all bands that have more than 5 albums and starts with A
select Band_name
from (select Band_name,Nr_of_albums
	from Band
	where Band_name like 'A%') as Band_nr_albums
where Nr_of_albums >5;
--weget all types where category_id is div by 2 and name_type ends with p 
select Name_type
from (select Name_type
	from Category
	where Category_id%2=0) as Type_of_name
where Name_type like '%p';

--h
--we count how many song are in a category
select count(*) as 'Song in category',Category_id
from Song_Category
group by Category_id;

--we make the sum of the album_id's where the artist has more then 1 album 
select sum(Album_id) as 'Sum Album Id'
from Album
group by Artist_id 
having count(*)>1;

--we take the min song_id from song having the same duration where the song duration is smaller then the avg(song_duration)
select min(Song_id) + 1000 as 'First Song', Song_duration
from Song
group by Song_duration 
having Song_duration <(
	select avg(Song_duration) 
	from Song
	);
--the same thing as with min but wiith max and +1 to the song_duration
select max(Song_id) + 1000 as 'Last Song', Song_duration
from Song
group by Song_duration 
having Song_duration+1>(
	select avg(Song_duration) 
	from Song
	);

--i
--we get the song_name where the song is in category_id =1
select Song_name
from Song
where Song_id = any(
	select Song_id 
	from Song_Category
	where Category_id = 1);
--shows the albums from artists that start with letter N
select Album_name
from Album
where Artist_id = any(
	select Artist_id 
	from Artist
	where Artist_name like 'N%');
--we get all names of songs that have the duration smaller than  the durations of the song_id <=3
select Song_name
from Song
where Song_duration < all (
	select Song_duration
	from Song
	where Song_id <=3);

--we get all band name where the nr of albums is bigger then all nr of albums that have odd id number 
select Band_name
from Band
where Nr_of_albums > all (
	select Nr_of_albums
	from Band
	where Band_id % 2 = 1);


--we get the song_name where the song is in category_id =1
select Song_name
from Song
where Song_id in (
	select Song_id 
	from Song_Category
	where Category_id = 1);
--shows the albums from artists that start with letter N
select Album_name
from Album
where Artist_id in (
	select Artist_id 
	from Artist
	where Artist_name like 'N%');
--we get all names of songs that have the duration smaller than  the durations of the song_id <=3
select Song_name
from Song
where Song_duration < (
	select min(Song_duration)
	from Song
	where Song_id <=3);
--we get all band name where the nr of albums is bigger then all nr of albums that have odd id number 
select Band_name
from Band
where Nr_of_albums > (
	select max(Nr_of_albums)
	from Band
	where Band_id % 2 = 1);
