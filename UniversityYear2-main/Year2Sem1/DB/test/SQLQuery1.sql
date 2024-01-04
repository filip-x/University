CREATE  DATABASE practic
use practic;

create table R
(
FK1 int,
Fk2 int,
C1 varchar(200),
C2 varchar(200),
C3 int,
C4 int,
C5 varchar(10),
PRIMARY KEY(Fk1,Fk2)
)

insert into R values
(1, 1, 'Pisica pe acoperisul fierbinte', 'Tennessee Williams', 100, 20, 'AB'),
(1, 2, 'Conul Leonida fata cu reactiunea', 'Ion Luca Caraglale', 50, 50, 'CQ'),
(1, 3, 'Concert din muzica de Bach Hortensia', 'Papadat-Bengescu', 50, 10, 'QC'),
(2, 1, 'Fata babei si fata mosneagului', 'Ion Creanga', 100, 100, 'QM'),
(2, 2, 'Frumosii nebuni ai marilor orase', 'Fanus Neasu', 10, 10, 'BA'),
(2, 3, 'Frumoasa calatorie a ursilor panda povestita de un saxofonist care avea o iubita la Frankfurt', 'Matei Visniec' ,100, 20, 'MQ'),
(3, 1, 'Mansarda la Paris cu vedere spre moarte', 'Matei Visniec', 200, 10, 'PQ'),
(3, 2, 'Richard al III-lea interzice sau Scene din vlata lul Meyerhold', 'Matel Vlsniec', 100, 50,'PQ'),
(3, 3, 'Masinaria Cehov. Nina sau despre fragilitatea pescarusilor impaiati', 'Matei Visniec',100, 100, 'AZ'),
(4, 1, 'Omul de zapada care voia sa intalneasca soarele', 'Matei Visniec', 100, 100, 'CP'),
(4, 2, 'Exctraterestrul care isi dorea ca amintire o pljama', 'Matei Visniec', 50, 10, 'CO'),
(4, 3, 'O femeie draguta cu o floare si ferestre spre nord', 'Edvard Radzinski', 10, 100, 'CP'),
(4, 4, 'Trenul din zori nu mai opreste aici', 'Tennessee Williams', 200, 200, 'MA')

DELETE FROM R
SELECT *
FROM 
  (SELECT FK1, FK2, C3+C4 TotalC3C4
  FROM R
  WHERE FK1 = FK2) r1 
    INNER JOIN 
  (SELECT FK1, FK2, C5
  FROM R
  WHERE C5 LIKE '%Q%') r2 ON r1.FK1 = r2.FK1 AND r1.FK2 = r2.FK2


 CREATE OR ALTER TRIGGER TrOnUpdate
  ON R
  FOR UPDATE
AS
  DECLARE @total INT = 0
  SELECT @total = SUM(i.C3 - d.C3)
  FROM deleted d INNER JOIN inserted i ON d.FK1 = i.FK1 AND d.FK2 = i.FK2
  WHERE d.C3 < i.C3
  PRINT @total

  UPDATE R
SET C3 = 300
WHERE FK1 < FK2 

SELECT C2, SUM(C3) TotalC3, AVG(C3) AvgC3
FROM R
WHERE C3 > = 100 OR C1 LIKE '%Pisica%'
GROUP BY C2
HAVING SUM(C3) > 100




create database bautura
use bautura

create table Bars
(
	id int primary key identity,
	[Name] varchar(20)
)

create table Customers
(
	id int primary key identity,
	[Name] varchar(20)
)

create table Beers
(
	id int primary key identity,
	[Name] varchar(20),
	Producer_Price int,
	Beer_Category varchar(20)
)

create table Beer_Bar
(
	id_Beer_Bar int primary key identity,
	id_Beer int foreign key references Beers(id),
	id_Bar int foreign key references Bars(id),
	price int
)

create table Customers_Bars
(
	id_Customer_Bars int primary key identity,
	id_Customer int foreign key references Customers(id),
	id_Bars int foreign key references Bars(id),
	time_stemp datetime
)
create table Customers_Beer
(
	id_Customer_Beer int primary key identity,
	id_Customer int foreign key references Customers(id),
	id_Beer int foreign key references Beers(id)
)


