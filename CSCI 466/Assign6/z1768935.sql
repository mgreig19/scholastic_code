/*******************************************
Assignment 6
CSCI466
Georgia Brown

Mason Greig
z1768935

Function: These queries answer the questions 
		given for assignment 6.
********************************************/

/*
1. The number of employees that work in each city, also displays city name
*/

select count(employeeNumber) as 'Number of Employees',city from Employees,Offices where Employees.officeCode = Offices.officeCode group by city;

/*
2. Lists employees and displays the employee's first and last name while also showing the number of customers for each employee.
*/

select concat(firstName,' ', lastName) as 'Employee', count(customerNumber) as 'Number of Customers' from Employees, Customers where salesRepEmployeeNumber = employeeNumber group by employeeNumber;

/*
3. Lists the first and last name of each employee and the person they report to.
*/

select concat(firstName, ' ', lastName) as 'Employee', (select concat(firstName, ' ', lastName) from Employees e where e.employeeNumber = e2.reportsTo) as 'Reports To' from Employees e2;

/*
4. List of the first 25 customers, displaying the contact's first and last name along with the total amount of payments. 
*/

select concat(contactFirstName,' ', contactLastName) as 'Customer', round(sum(amount),2) as 'Total Payments' from Customers c, Payments p where c.customerNumber = p.customerNumber group by c.customerNumber limit 25;

/*
5. The number of customers that live in the same city as their sales rep's work
*/

select count(customerNumber) as 'The Number of Customers Living in Same City as Rep' from Customers c, Employees e, Offices o where c.salesRepEmployeeNumber = e.employeeNumber and e.officeCode = o.officeCode and c.city = o.city; 

/*
5. The number of customers that live in the same city as their sales rep's work, listing the name of the city and the number of customers.
*/

select c.city as 'City Name', count(distinct customerNumber) as 'The Number of Customers Living in Same City as Rep' from Customers c, Employees e, Offices o where e.officeCode = o.officeCode and c.city = o.city group by c.city;

/*
7. The customer that has ordered the most expensive product, based on buy price. (Display customer name and product price)
*/

select customerName as 'Big Spenders' from Customers c, Orders o, OrderDetails d, Products p where c.customerNumber = o.customerNumber and o.orderNumber = d.orderNumber and d.productCode = p.productCode and p.buyPrice = (select max(buyPrice) from Products);

/*
8. The customer that has made the largest payment.
*/

select customerName as 'Customer with Largest Payment' from Customers c, Payments p where c.customerNumber = p.customerNumber and p.amount = (select max(amount) from Payments);

/*
9. List all of the product descriptions for products from Min Lin Diecast and Exoto Designs, Done in two different ways.
*/

select productDescription from Products where productVendor = 'Min Lin Diecast' or productVendor = 'Exoto Designs';

select productDescription from Products where productVendor in ('Min Lin Diecast','Exoto Designs');

/*
Extra Credit Questions
*/

/*
1. Lists the first 10 orders by order number with customer name and product names. Ordered by customer in ascending order.
*/

select o.orderNumber, customerName, productName from Orders o, Customers c, Products p, OrderDetails d where o.customerNumber = c.customerNumber and o.orderNumber = d.orderNumber and d.productCode = p.productCode group by o.orderNumber order by customerName limit 10;

/*
2. The average dollar amount for each order.
*/

select orderNumber, round(avg(priceEach * quantityOrdered),2) as 'Average Amount' from OrderDetails group by orderNumber;


