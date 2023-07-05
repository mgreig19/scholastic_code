/*
Interactive SQL 
assign 5
section: 	CSCI466-2
TA:		Kartheek Chintalapati
due:		Feb 27, 2017 

May-Myo Khine
z1785954
*/

1	select AuthorFirst, AuthorLast from Author order by AuthorFirst;

2	select distinct City from Publisher;	#List all the cities that have a publisher, list each city only once.

3	select count(Title) from Book;	#How many book titles are in the database?

4	select BranchName, sum(OnHand) from Branch, Inventory WHERE Branch.BranchNum=Inventory.BranchNum group by BranchName; #For each branch, list the branch name and the total number of books on hand.

5	select sum(NumEmployees) from Branch;	#How many employees total work at Henry Books?

6	select Title from Book, Wrote, Author where Book.BookCode = Wrote.BookCode and Wrote.AuthorNum = Author.AuthorNum and AuthorLast = "King" and AuthorFirst = "Stephen";	#List the titles of all of the books written by Stephen King.

7	select Title, Type, Price from Book where PaperBack = "Y";	#List title, type and price for all books that are paperback.

8	select distinct BranchName from Branch, Inventory where Branch.BranchNum = Inventory.BranchNum and OnHand >= 10;	#List the branch name for all branches that have at least one book that has at least 10 copies on hand.

9	select Title, AuthorFirst, AuthorLast from Book b, Author a, Wrote w where b.BookCode = w.BookCode and a.AuthorNum = w.AuthorNum order by Title desc;	#For each book, list the title, author first name and author last name. Print the list in reverse alphabetic order of the title.

10	select PublisherName, count(BookCode) from Book b, Publisher p where b.PublisherCode = p.PublisherCode group by PublisherName;	#List each publisher by name and how many books they published.

11	select count(BookCode) from Book where Price < "10";	#How many books cost less than $10.00?

12	select AuthorLast from Author a, Publisher p, Book b, Wrote w where a.AuthorNum = w.AuthorNum and p.PublisherCode = b.PublisherCode and b.BookCode = w.BookCode and PublisherName = "Simon and Schuster";	#List the author last names for all the authors published by Simon and Schuster.

13	select Type, count(BookCode) from Book group by Type;	#List each type of book and how many of each.

14	select sum(OnHand) from Branch b, Inventory i where b.BranchNum = i.BranchNum and BranchLocation = "Brentwood Mall";	#How many books are on hand at the Brentwood Mall location? 

15	select BranchLocation, NumEmployees, sum(OnHand) from Branch b, Inventory i where i.BranchNum = b.BranchNum group by BranchLocation;	#List each branch location, the number of employees and the number of books on hand.

16	select Title from (select Title from Wrote w, Book b where b.BookCode = w.BookCode and Sequence = "1")B;	#List the titles of all books who have a Sequence number of 1. You must use a nested select statement.

17	select PublisherName from Publisher where PublisherName LIKE "T%";	#List all the publishers whose name starts with T.

18	select * from Author where AuthorFirst LIKE "%ll%" or AuthorLast LIKE "%ll%";	#List all of the Author information for all authors that have a double l in their name (ll).

19	select Title from Book where BookCode = "079x" or "138x" or "669x";	#List all the book titles that have a book code of 079x, 138x or 669x.

20	select AuthorLast, Title, PublisherName from Author a, Book b, Publisher p, Wrote w where a.AuthorNum = w.AuthorNum and b.BookCode = w.BookCode and p.PublisherCode = b.PublisherCode order by PublisherName;	#List each author last name, book title and publisher name, in alphabetic order of the publisher.

/*
21

Choose any 2 of the above, and write the SQL statements differently. (10 points)
I choose no3 question and no16 question to rewrite.
*/

select count(BookCode) from Book;	#How many book titles are in the database?
select Title from Book, Wrote where Book.BookCode = Wrote.BookCode and Sequence = "1";	#List the titles of all books who have a Sequence number of 1. You must use a nested select statement.

/*
22

Looking at the tables, figure out another type of information
     a person who worked at Henry Books might be interested in. Write
     the question and the query and results to answer the question.
     (10 points)
I think it will be intresting to know the average price of book based on the author.
Question: Find the average price of book of each author
Ans:	  
*/
select avg(Price), AuthorLast, AuthorFirst from Author a, Book b, Wrote w where w.BookCode = b.BookCode and w.AuthorNum = a.AuthorNum group by Price;
