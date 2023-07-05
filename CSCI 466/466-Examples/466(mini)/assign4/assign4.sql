/*
Basic SQL 
assign 4
section: 	CSCI466-2
TA:		Kartheek Chintalapati
due:		Feb 20, 2017 

May-Myo Khine
z1785954
*/


use BabyName;	#choose the database to work

1)mysql>	describe BabyName;									#show table and structure of BabyName database
2)mysql>	select distinct year from BabyName where name = "May" limit 15;				#list the years where "May" is on list
3)mysql>	select distinct name from BabyName where year = "1995" limit 15;			#list the names of the year 1995
4)mysql>	select name, gender, place, count, year from BabyName where name LIKE "%May%" group by name,year limit 15;	#list all info about the name similar to May
5)mysql>	select count(*) from BabyName;								#count how many rows are in the table
6)mysql>	select count(name) from BabyName where year = "1995";					#count how many names are on 1995
7)mysql>	select distinct name from BabyName where year = "1995" and name LIKE "M%";		#list all name from 1995 and which starts with "M"
8)mysql>	select count(name),gender from BabyName where year = "1965" group by gender;		#list the count of the name by gender from 1965


/*
I used limit 15 for command 2,3,and 4 in order to make the output easier for TA to check.
*/
 
