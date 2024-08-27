

CREATE DATABASE books;

USE books;

CREATE TABLE Authors
(
   AuthorID int NOT NULL AUTO_INCREMENT PRIMARY KEY,
   FirstName varchar(30) NOT NULL,
   LastName varchar(30) NOT NULL
)                 ;
CREATE TABLE Titles
(
   ISBN varchar(20) NOT NULL PRIMARY KEY,
   Title varchar(100) NOT NULL,
   EditionNumber int NOT NULL,
   Copyright varchar(4) NOT NULL
)             ;

CREATE TABLE AuthorISBN
(
   AuthorID int NOT NULL,
   ISBN varchar(20) NOT NULL,
   FOREIGN KEY (AuthorID) REFERENCES Authors(AuthorID),
   FOREIGN KEY (ISBN) References Titles(ISBN)
)            ;

INSERT INTO Authors (FirstName,LastName) VALUES ('Harvey','Deitel')           ;
INSERT INTO Authors (FirstName,LastName) VALUES ('Paul','Deitel')     ;
INSERT INTO Authors (FirstName,LastName) VALUES ('Andrew','Goldberg')    ;
INSERT INTO Authors (FirstName,LastName) VALUES ('David','Choffnes')     ;


INSERT INTO Titles (ISBN,Title,EditionNumber,Copyright) VALUES ('0131869000','Visual Basic 2005 How to Program',3,'2006')          ;
INSERT INTO AuthorISBN (AuthorID,ISBN) VALUES (1,'0131869000')     ;
INSERT INTO AuthorISBN (AuthorID,ISBN) VALUES (2,'0131869000') ;
INSERT INTO Titles (ISBN,Title,EditionNumber,Copyright) VALUES ('0131525239','Visual C# 2005 How to Program',2,'2006')  ;
INSERT INTO AuthorISBN (AuthorID,ISBN) VALUES (1,'0131525239')      ;
INSERT INTO AuthorISBN (AuthorID,ISBN) VALUES (2,'0131525239')      ;

INSERT INTO Titles (ISBN,Title,EditionNumber,Copyright) VALUES ('0132222205','Java How to Program',7,'2007')   ;
INSERT INTO AuthorISBN (AuthorID,ISBN) VALUES (1,'0132222205')                                               ;
INSERT INTO AuthorISBN (AuthorID,ISBN) VALUES (2,'0132222205')                                       ;

INSERT INTO Titles (ISBN,Title,EditionNumber,Copyright) VALUES ('0131857576','C++ How to Program',5,'2005')     ;
INSERT INTO AuthorISBN (AuthorID,ISBN) VALUES (1,'0131857576')                                                  ;
INSERT INTO AuthorISBN (AuthorID,ISBN) VALUES (2,'0131857576')                                                 ;

INSERT INTO Titles (ISBN,Title,EditionNumber,Copyright) VALUES ('0132404168','C How to Program',5,'2007')     ;
INSERT INTO AuthorISBN (AuthorID,ISBN) VALUES (1,'0132404168')                                             ;
INSERT INTO AuthorISBN (AuthorID,ISBN) VALUES (2,'0132404168')                                       ;

INSERT INTO Titles (ISBN,Title,EditionNumber,Copyright) VALUES ('0131450913','Internet & World Wide Web How to Program',3,'2004')    ;
INSERT INTO AuthorISBN (AuthorID,ISBN) VALUES (1,'0131450913')                                                                 ;
INSERT INTO AuthorISBN (AuthorID,ISBN) VALUES (2,'0131450913')                                            ;
INSERT INTO AuthorISBN (AuthorID,ISBN) VALUES (3,'0131450913')                                   ;

INSERT INTO Titles (ISBN,Title,EditionNumber,Copyright) VALUES ('0131828274','Operating Systems',3,'2004')        ;
INSERT INTO AuthorISBN (AuthorID,ISBN) VALUES (1,'0131828274')                                                    ;
INSERT INTO AuthorISBN (AuthorID,ISBN) VALUES (2,'0131828274')                                                    ;
INSERT INTO AuthorISBN (AuthorID,ISBN) VALUES (4,'0131828274')                                                    ;
