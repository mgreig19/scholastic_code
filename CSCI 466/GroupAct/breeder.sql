drop table if exists dog;
drop table if exists rfid_dog;
drop table if exists breed;
drop table if exists breeder;
drop table if exists breed_breeder;

CREATE TABLE dog
(
  id int(11) NOT NULL auto_increment,
  name varchar(255),
  descr text,
  size enum('small','medium','large'),
  date timestamp,
  PRIMARY KEY (id)
);

INSERT INTO dog (name,descr,size,date) VALUES('Max','Its distinctive appearance and deep foghorn voice make it stand out in a crowd.','medium',NOW());
INSERT INTO dog (name,descr,size,date) VALUES('Jake','It loves human companionship and being part of the group.','medium',NOW());
INSERT INTO dog (name,descr,size,date) VALUES('Buster','Short-legged but surprisingly strong and agile.','small',NOW());
INSERT INTO dog (name,descr,size,date) VALUES('Billie','Fast and very crazy.','medium',NOW());


CREATE TABLE rfid_dog
(
  dog_id int(11) NOT NULL,
  bar_code varchar(128) NOT NULL,
  notes text,
  iso_compliant enum('y','n') DEFAULT 'n',
  date timestamp,
  PRIMARY KEY (dog_id)
);

INSERT INTO rfid_dog (dog_id,bar_code,notes,iso_compliant,date) VALUES('1','234k34340ll2342323022','This is a RFID tag for the Max','y',NOW());
INSERT INTO rfid_dog (dog_id,bar_code,notes,iso_compliant,date) VALUES('2','09383638920290397d829','This is a RFID tag for the Jake','y',NOW());
INSERT INTO rfid_dog (dog_id,bar_code,notes,iso_compliant,date) VALUES('3','30id8383837210jndal20','This is a RFID tag for the Buster','y',NOW());
INSERT INTO rfid_dog (dog_id,bar_code,notes,iso_compliant,date) VALUES('4','30id8385867210jydal20','This is a RFID tag for the Billie','y',NOW());

CREATE TABLE breed
(
  id int(11) NOT NULL auto_increment,
  name varchar(255),
  descr text,
  date timestamp,
  PRIMARY KEY (id)
);

INSERT INTO breed (name,descr,date) VALUES('Hounds','One of the oldest groups of dog originating thousands of years ago.',NOW());
INSERT INTO breed (name,descr,date) VALUES('Terrier','A tough, no-nonsense, rabbiting and badgering dog.',NOW());
INSERT INTO breed (name,descr,date) VALUES('Border Collie','One of the smartest of the herding dogs.',NOW());
INSERT INTO breed (name,descr,date) VALUES('Bulldog','A gentle breed that is very stubborn.',NOW());


ALTER TABLE dog
ADD breed_id int(11) AFTER date;

UPDATE dog SET breed_id = '1' WHERE id = '1';
UPDATE dog SET breed_id = '1' WHERE id = '2';
UPDATE dog SET breed_id = '2' WHERE id = '3';
UPDATE dog SET breed_id = '3' WHERE id = '4';

CREATE TABLE breeder
(
  id int(11) NOT NULL auto_increment,
  name varchar(255),
  address text,
  state varchar(10),
  city varchar(40),
  phone varchar(28),
  email varchar(28),
  date timestamp,
  PRIMARY KEY (id)
);

INSERT INTO breeder (name,address,state,city,phone,email,date) VALUES('Joe Bloggs','23 Smith St','NSW','Sydney','02 7875 4545','joe@email.com',NOW());
INSERT INTO breeder (name,address,state,city,phone,email,date) VALUES('Tom Smith','11 Tucker St','QLD','Brisbane','07 023 2343','tom@email.com',NOW());


CREATE TABLE breed_breeder 
(
  breed_id int(11) DEFAULT '0' NOT NULL,
  breeder_id int(11) DEFAULT '0' NOT NULL,
  PRIMARY KEY (breed_id, breeder_id)
);

INSERT INTO breed_breeder (breed_id,breeder_id) VALUES('1','1');
INSERT INTO breed_breeder (breed_id,breeder_id) VALUES('2','1');
INSERT INTO breed_breeder (breed_id,breeder_id) VALUES('1','2');
INSERT INTO breed_breeder (breed_id,breeder_id) VALUES('2','3');




