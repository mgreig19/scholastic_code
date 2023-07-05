/*********************************************************
Assignment 4
CSCI 466
Mason Greig
z1768935
Fall 2017 Section 1

Use:
SQL script which answers the questions about the database given on blackboard.

Output:
Tables which hold the information being queried for. 
Results of queries stored in z1768935.txt
*********************************************************/
/*
1.
Displays the names of the tables in the classicalmodels database and the number
*/
show tables;

/*
2.
The following commands show the details of each table within the database.
*/
describe Customers;

describe Employees;

describe Offices;

describe OrderDetails;

describe Orders;

describe Payments;

describe Products;

/*
3.A
Displays the number of customers currently in the database.
*/
select count(customerNumber) as 'Number of Customers' from Customers;

/*
3.B
Displays the number of customers who have orders.
*/
select count(distinct customerNumber) as 'Number of Customers with Orders' from Orders;

/*
4.A
Displays the number of products which are available.
*/
select count(productCode) as 'Number of Products' from Products;

/*
4.B
Shows all the details of 10 products.
*/
select * from Products limit 10;

/*
5.
Displays the customer names and total payment amounts paid for each customer.
*/
select customerName, round(sum(amount),2) as 'Payment Totals' from Customers c, Payments p where c.customerNumber = p.customerNumber group by customerName limit 15;

/*
6.
Displays the different cities which the offices are located at.
*/
select distinct city from Offices order by city;

/*
7.A
Displays the number of employees.
*/
select count(employeeNumber) as 'Number of Employees' from Employees;

/*
7.B
Displays the number of employees working at each office.
*/
select o.officeCode, count(employeeNumber) as 'Number of Employees' from Employees e, Offices o where e.officeCode = o.officeCode group by officeCode;

/*
8.A
Displays the number of orders.
*/
select count(orderNumber) as 'Number of Orders' from Orders;

/*
8.B
Displays the number of orders each customer currently has as long as the number of orders is greater than 5.
*/
select customerName, count(orderNumber) as 'Number of Orders' from Customers c, Orders o where c.customerNumber = o.customerNumber group by customerName having count(orderNumber) > 5;

/*
8.C
Displays the number of orders shipped.
*/
select count(orderNumber) as 'Number of Orders Shipped' from Orders where status = 'Shipped';

/*
8.D
Displays the different order statuses that are possible.
*/
select distinct status as 'Order Status Types' from Orders;

/*
9.
Displays the employee names in the format (Last Name, First Name) and orders them reverse alphabeticaly by last name.
*/
select concat(lastName, ', ', firstName) as 'Employee Names' from Employees order by lastName desc;

/*
10.
Displays the office employees who work in the London office; this is done through a single statement using one table.
*/
select *, (select city from Offices where city = 'London') as 'City' from Employees where officeCode = (select officeCode from Offices where city = 'London');
