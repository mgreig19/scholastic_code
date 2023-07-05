/*******************************************
Assignment 7
CSCI466
Georgia Brown
Section 1

Mason Greig
z1768935

Function: These queries answer the questions 
		given for assignment 7.
********************************************/

/*
 1.Dropping/deleting all the tables/views which will be created. 
*/

drop view Pet_Owners;
drop table Pet;
drop table Owner;

/*
 2.Creates a table (owner) with an owner id and a name. Owner id is a primary key and will be auto-incremented.
*/

create table Owner(owner_id mediumint unsigned not null auto_increment primary key, owner_name char(40));

/*
 3.Puts 5 records into the table. 
*/

insert into Owner (owner_name) values ('Josh Smith'), ('Alex Parish'), ('John Edwards'), ('Candy Jones'), ('Kyndra Deschain');

/*
 4.Shows all records of owner table.  
*/

select * from Owner;

/*
 5.Creates a table (pet) with a pet id (primary key, auto-incremented), pet name and owner id (foreign key into owner).  
*/

create table Pet(pet_id mediumint unsigned not null auto_increment primary key, pet_name char(20), owner_id mediumint unsigned not null, foreign key (owner_id) references Owner(owner_id));

/*
 6.Puts 5 records into the table with at least 2 pets owned by the same owner. 
*/

insert into Pet (pet_name,owner_id) Values ('Spot',1),('Spike',2),('Bruce',3),('Tank',3),('Garfield',4),('Oliver',5);

/*
 7.Shows all records of the pet table. 
*/

select * from Pet;

/*
 8.Adds a column to the pet table (type: dog, cat, fish). 
*/

alter table Pet add pet_type char(20);

/*
 9.Update several rows to include pet type. 
*/

update Pet set pet_type = 'dog' where owner_id = 2 or owner_id = 1;
update Pet set pet_type = 'cat' where owner_id = 4 or owner_id = 5;
update Pet set pet_type = 'fish' where owner_id = 3;

/*
10.Show all records in the pet table.
*/

select * from Pet;

/*
11.Creates a view which contains a statement that shows all owners and their pet's names.
*/

create view Pet_Owners as select owner_name as 'Owner', pet_name as 'Pet' from Owner o, Pet p where o.owner_id = p.owner_id; 

/*
12.Shows all the records for the previously created view. 
*/

select * from Pet_Owners;
