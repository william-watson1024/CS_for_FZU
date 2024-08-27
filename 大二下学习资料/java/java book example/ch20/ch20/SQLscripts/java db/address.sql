DROP DATABASE IF EXISTS address;
CREATE DATABASE address;
USE address;

CREATE TABLE Addresses
(
	AddressID INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
	FirstName VARCHAR (15) NOT NULL,
	LastName VARCHAR (30) NOT NULL,
	Email VARCHAR (30) NOT NULL,
	PhoneNumber VARCHAR (15) NOT NULL
);
INSERT INTO Addresses (FirstName,LastName,Email,PhoneNumber)
	VALUES ('Mike','Green','demo1@deitel.com','555-5555'),
	('Mary','Brown','demo2@deitel.com','555-1234');