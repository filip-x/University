create database eLearning
use eLearning;

create table Courses
(
    id_cours int primary key identity,
    title varchar(20),
    [language] varchar(20),
    price int,
    discount int,
    lectures int

)

create table Companies
(--company has a name, turnover, description, and can offer several courses.
    id_company int primary key identity,
    [name] varchar(50),
    turnover int,
    deescription varchar(200),
    course_id int foreign key references Courses(id_cours)
)

create table company_course (
    id_cc int primary key identity,
    id_course int foreign key references Courses(id_cours),
    id_company int foreign key references Companies (id_company)
)

create table Topics
(--can be represented in multple courses
    id_topic int primary key identity,
    [name] varchar(50)
)

create table topics_course
(
    tc int primary key identity,
    id_topic int foreign key references Topics(id_topic),
    id_cours int foreign key references Courses(id_cours)
)
create table Lectures
(--lectures belong to the cours, title, colection of resources: files containg lecrues notes,quizzes etc 
    id_lecture int primary key identity,
    title varchar(20),
    cours_id int foreign key references Courses(id_cours)

)

create table Resources
(
    id_resources int primary key identity,
    [url] varchar(200)
)