/*
DDL
assign 6
section:        CSCI466-2
TA:             Kartheek Chintalapati
Due:		Mar 6, 2017

May-Myo Khine
z1785954
*/

/*
1. use znnnnnn;
*/
use z1785954;

/*
2.(a)
A table called instrument. It should have an instrument-id
          (an auto-increment number, which is the primary key), an
          instrument type(15 characters), a maker name(25
          characters), and the 4-digit year it was made.
*/
CREATE TABLE instrument (instrument_id MEDIUMINT UNSIGNED NOT NULL AUTO_INCREMENT,
instrument_type CHAR(15) NOT NULL, maker_name CHAR(25) NOT NULL, made_year CHAR(4)
NOT NULL, PRIMARY KEY (instrument_id));


/*
2.(b)
A table called player. It should have a player-id that is
          an auto-increment number and the primary key. A 15
          character last name, and a 15 character first name. And
          finally a salary. The salary field should be able to hold
          up to 65,000.00 (dollars and cents).
*/
CREATE TABLE player ( player_id MEDIUMINT UNSIGNED NOT NULL AUTO_INCREMENT,
last_name CHAR(15) NOT NULL, first_name CHAR(15) NOT NULL, salary DECIMAL(7,2) NOT NULL,
PRIMARY KEY ( player_id));



/*
2.(c)
A table called plays. It has a combined key of the
          instrument id and player id (which are each foreign keys
          into their respective tables, and a rating of A,B,C,D
          (which indicates how well they play that particular
          instrument, with A being best). Obviously this means each
          player can play multiple instruments.
*/
CREATE TABLE plays (instrument_id MEDIUMINT UNSIGNED NOT NULL AUTO_INCREMENT,
player_id MEDIUMINT UNSIGNED NOT NULL,rating ENUM('A','B','C','D') NOT NULL,
PRIMARY KEY(instrument_id),FOREIGN KEY(player_id) REFERENCES player (player_id));

/*
3.Insert at least five records into each table.
INSERT INTO instrument VALUES('001','Violin', 'May','1995');
INSERT INTO instrument VALUES('002','Guiter', 'Ada','1996');
INSERT INTO instrument VALUES('003','Piano', 'Chit','1997');
INSERT INTO instrument VALUES('004','Drum', 'Su','2000');
INSERT INTO instrument VALUES('005','Saxophone', 'Khine','2015');

INSERT INTO player VALUES('001','Khine','May','65000.00');
INSERT INTO player VALUES('002','Su','Chit','989.55');
INSERT INTO player VALUES('003','Khine','Khine','2100.02');
INSERT INTO player VALUES('004','Myo','May','1100.55');
INSERT INTO player VALUES('005','Loynvros','Ada','1234.56');

INSERT INTO plays VALUES('001','001','A');
INSERT INTO plays VALUES('002','002','B');
INSERT INTO plays VALUES('003','003','C');
INSERT INTO plays VALUES('004','004','D');
INSERT INTO plays VALUES('005','005','A');
*/
INSERT INTO instrument VALUES(' ','Violin', 'May','1995');
INSERT INTO instrument VALUES(' ','Guiter', 'Ada','1996');
INSERT INTO instrument VALUES(' ','Piano', 'Chit','1997');
INSERT INTO instrument VALUES(' ','Drum', 'Su','2000');
INSERT INTO instrument VALUES(' ','Saxophone', 'Khine','2015');

INSERT INTO player VALUES(' ','Khine','May','65000.00');
INSERT INTO player VALUES(' ','Su','Chit','989.55');
INSERT INTO player VALUES(' ','Khine','Khine','2100.02');
INSERT INTO player VALUES(' ','Myo','May','1100.55');
INSERT INTO player VALUES(' ','Loynvros','Ada','1234.56');

INSERT INTO plays VALUES(' ','001','A');
INSERT INTO plays VALUES(' ','002','B');
INSERT INTO plays VALUES(' ','003','C');
INSERT INTO plays VALUES(' ','004','D');
INSERT INTO plays VALUES(' ','005','A');


/*
4.Do a select statement on each table to show all the rows.
*/
SELECT * FROM instrument;
SELECT * FROM player;
SELECT * FROM plays;


/*
5.Add an attribute start-date to the player table, which is the
     year the player started with the orchestra and set it to 2010
     for every player.
Is there any other way to add start_date and update the table at the same time?
ALTER TABLE player ADD start_date CHAR(4);
UPDATE player SET start_date = '2010';
*/
ALTER TABLE player ADD start_date int DEFAULT 2010;

/*
6.Do a select on that table to show all of the rows.
*/
SELECT * FROM player;

/*
7.Change the start-date to 2015 for 2 of the rows in the player table.
*/
UPDATE player SET start_date = '2015' WHERE player_id = '001';
UPDATE player SET start_date = '2015' WHERE player_id = '003';


/*
8.Do a select on that table to show all of the rows.
*/
SELECT * FROM player;


/*
9.Remove one of the rows from one of your tables.
Is there any other way to delect from a table with primary key which is also forgein key???
*/
DELETE FROM plays WHERE instrument_id='005';


/*
10.Do a select on that table to show all of the rows.
*/
SELECT * FROM plays;


/*
11.Describe each of the tables.
*/
DESCRIBE instrument;
DESCRIBE player;
DESCRIBE plays;
