create database Tracker
use Tracker





CREATE TABLE Banks
(
    BankID INT PRIMARY KEY,
    BankName VARCHAR(100),
	SwiftCode INT,
	WebsitrUrl varchar(100),
	MajorShareCountry varchar(50)
)


CREATE TABLE Atm
(
    AtmID INT PRIMARY KEY,
    AtmAddress VARCHAR(50),
    deposits VARCHAR(50),
    BankID INT REFERENCES Banks(BankID)
)

CREATE TABLE Customers
(
    CustomerID INT PRIMARY KEY,
    CustomerName VARCHAR(50),
    CustomerType varchar(50)
)

CREATE TABLE Cards
(
    CardID INT PRIMARY KEY,
    ExpirationDate DATE,
	Number int,
	BankID INT REFERENCES Banks(BankID),
	CustomerID INT REFERENCES Customers(CustomerID)

)

CREATE TABLE Transactions
(
    TransactionID INT PRIMARY KEY,
    Amount INT,
	WithdrawalType varchar(50),
	AtmID INT REFERENCES Atm(AtmID),
	CardID INT REFERENCES Cards(CardID),
	DateAndTime datetime
)


insert into Banks values(1,'Bank1,',1,'www.hello','Ro'),(2,'Bank2,',2,'www.hello2','US')
insert into Atm values(1,'here','yes',1),(2,'here','yes',2)
insert into Customers values(1,'Filip','legal'),(2,'Me','legal')
INSERT INTO Cards VALUES (1, '1-1-2022', 50012,1,1), (2, '1-1-2023', 10292, 2,2)
INSERT INTO Transactions VALUES (1,100, 'Deposit', 1,1,'1-1-2021'), (2,200, 'Deposit', 2,1,'2-1-2021'),(3,300, 'Deposit', 2,2,'2-2-2021')

SELECT * FROM Transactions
SELECT * FROM Cards