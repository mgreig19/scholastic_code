drop table RFQ;
drop table SalesQuote;
drop table InventoryPart;
drop table CustomerAccount;

create table CustomerAccount(account_id mediumint not null auto_increment primary key, company_name char(30), street_address char(30), city char(30), state char(30), zip_code char(10), rep_first_name char(20), rep_last_name char(20), rep_email char(50), rep_phone_number char(20), quote_type char(20), sales_manager_email char(50), sales_manager_phone char(20), password varchar(25) not null);
create table InventoryPart(part_id mediumint not null auto_increment primary key, part_name char(30), barcode_id mediumint  not null, part_description varchar(50), quantity mediumint , price double , manufacturer_name char(30), comments varchar(100));
create table RFQ(account_id mediumint, part_id mediumint, quantity mediumint, require_by_date varchar(25), foreign key (account_id) references CustomerAccount(account_id), foreign key (part_id) references InventoryPart(part_id));
create table SalesQuote(quote_id mediumint not null auto_increment primary key, company_name char(30), account_id mediumint , quote_date varchar(25), part_id mediumint  not null, provide_by_date varchar(25), unit_price double , total_price double , experation_date varchar(25), status char(20), order_number mediumint , accepted_date varchar(25), require_by_date varchar(25), foreign key (part_id) references InventoryPart(part_id), foreign key (account_id) references CustomerAccount(account_id));

insert into CustomerAccount Values (1, "Bayer", "123 Fake Ave", "Springfield", "IL", "61000", "Marcus", "Jackson", "z1768935@something.edu", "(915)293-2134", "Manual", "salesmanager@fake.com", "(123)456-7890", "xxxxxxxxxxxx");
insert into CustomerAccount Values (2, "Johnson", "12 Fake St", "Spring", "IA", "61005", "Max", "Ion", "more@something.edu", "(915)762-2134", "Auto", "salesmanager2@fake.com", "(123)456-7891", "xxxxxxxxxxxx");
insert into CustomerAccount Values (3, "Stuff Inc.", "123 Box Car", "Train Tracks", "NY", "61030", "Mack", "Jr", "moretoo@something.edu", "(915)293-1854", "Auto", "salesmanager3@fake.com", "(123)456-7893", "xxxxxxxxxxxx");
insert into CustomerAccount Values (4, "Deschain Inc.", "19 Rose Court", "Toren", "NY", "61919", "Roland", "Deschain", "darktoren@something.edu", "(915)293-1919", "Manual", "salesmanager4@fake.com", "(123)456-7893", "xxxxxxxxxxxx");
insert into CustomerAccount Values (5, "Somebody", "Flags Circle", "Valencia", "CA", "69000", "Eddy", "Stone", "bored@something.edu", "(915)293-0984", "Manual", "salesmanager5@fake.com", "(123)456-7895", "xxxxxxxxxxxx");
insert into CustomerAccount Values (6, "The Dixie Pig", "123 Fresh Cut", "Deserted", "NV", "61390", "Merlin", "Grim", "quip@something.edu", "(915)903-5134", "Manual", "salesmanager6@fake.com", "(123)456-7896", "xxxxxxxxxxxx");
insert into CustomerAccount Values (7, "Gummies R Us", "927 Mountain St", "Boulder", "CO", "611732", "Evan", "Jade", "sleepy@something.edu", "(915)293-8972", "Auto", "salesmanager7@fake.com", "(123)456-7897", "xxxxxxxxxxxx");
insert into CustomerAccount Values (8, "Childrens Toys", "123 Still Going Ave", "Long Beach", "MN", "61290", "Ryan", "Anderson", "wow@something.edu", "(915)342-2134", "Auto", "salesmanager8@fake.com", "(123)456-9821", "xxxxxxxxxxxx");
insert into CustomerAccount Values (9, "We Float Here!", "123 Inflated", "Balloon", "WI", "c137-b", "Rick", "Sanchez", "showmewhtugot@something.edu", "(915)293-7123", "Manual", "salesmanager9@fake.com", "(123)456-8722", "xxxxxxxxxxxx");
insert into CustomerAccount Values (10, "Cop Out", "123 Finally", "Done", "CA", "61232", "Mason", "Whaleson", "laughing@something.edu", "(915)293-9999", "Auto", "salesmanager10@fake.com", "(123)456-9990", "xxxxxxxxxxxx");

insert into InventoryPart Values (1, "Wrench", "00000001", "This tool tightens and lossens stuff! Wow!", 50, 7.99, "Black & Decker", "I couldn't add pictures");
insert into InventoryPart Values (2, "Hammer", "00000002", "This tool smashes stuff! Wow!", 35, 3.99, "Man Power", "I couldn't add pictures");
insert into InventoryPart Values (3, "Saw", "00000003", "This tool cuts stuff fast! Wow!", 30, 9.99, "Tools Inc.", "I couldn't add pictures");
insert into InventoryPart Values (4, "Multi-Purpose Battery", "00000004", "This tool powers stuff! Wow!", 56, 19.99, "Batteries Plus", "I couldn't add pictures");
insert into InventoryPart Values (5, "Metal Sheet", "00000005", "This is heavy metal! Wow!", 20, 59.99, "Fabricator Inc.", "I couldn't add pictures");
insert into InventoryPart Values (6, "Drill", "00000006", "This tool screws stuff fast! Wow!", 30, 29.99, "Tools Inc.", "I couldn't add pictures");

insert into SalesQuote Values (1, "Bayer", 1, "11/20/2017", 1, "12/25/2017", 7.99, 39.95, "11/15/2017", "Pending", 1, "11/10/2017", "12/31/2017");
insert into SalesQuote Values (2, "Deschain Inc.", 4, "11/25/2017", 4, "12/25/2017", 19.99, 39.98, "11/15/2017", "Approved", 2, "11/10/2017", "12/31/2017");
insert into SalesQuote Values (3, "We Float Here!", 9, "11/25/2017", 6, "12/25/2017", 29.99, 29.99, "11/15/2017", "Cancelled", 3, "11/10/2017", "12/31/2017");
insert into SalesQuote Values (4, "Somebody", 5, "11/25/2017", 2, "12/25/2017", 3.99, 19.95, "11/15/2017", "Pending", 4, "11/10/2017", "12/31/2017");
insert into SalesQuote Values (5, "The Dixie Pig", 6, "11/25/2017", 3, "12/25/2017", 9.99, 19.98, "11/15/2017", "Approved", 5, "11/10/2017", "12/31/2017");
insert into SalesQuote Values (6, "Cop Out", 10, "11/25/2017", 5, "12/25/2017", 59.99, 59.99, "11/15/2017", "Pending", 6, "11/10/2017", "12/31/2017");

insert into RFQ (account_id, part_id, quantity, require_by_date) Values (1, 2, 13,"12/25/2017");
insert into RFQ (account_id, part_id, quantity, require_by_date) Values (5, 3, 30,"12/10/2017");
insert into RFQ (account_id, part_id, quantity, require_by_date) Values (8, 5, 9,"11/05/2017");
insert into RFQ (account_id, part_id, quantity, require_by_date) Values (7, 1, 17,"12/19/2017");
insert into RFQ (account_id, part_id, quantity, require_by_date) Values (9, 4, 25,"11/25/2017");


