#include "Book.h"
#include <cstring>
#include <iomanip>
#include <cstdlib>

using namespace std;

/*******************************
Function:Book::Book();

Use: Default constructor

Arguments: none

Returns: none
********************************/
Book::Book()
{
}
/*******************************
Function: Book::Book(char[] newISBN, char[] newTitle, double newPrice, int newQuantity);

Use: Alternate Constructor

Arguments:char[]: takes an array for the newISBN number to be put in bookID
		char[]: takes an array for the new Title of a book and puts it in bookTitle
		double: takes a double value newPrice and inputs it into the set method to set a new book price
		int: takes a int which represents the new quantity for quantityAvl 

Returns: none
********************************/
Book::Book(char newISBN[], char newTitle[], double newPrice, int newQuantity)
{
	strcpy(bookID, newISBN);
	strcpy(bookTitle, newTitle);
	setPrice(newPrice);
	setQuantity(newQuantity);
}
/*******************************
Function:Book::getISBN()

Use:accessor method

Arguments:none

Returns: char*: value(s) in the data member bookID
********************************/
char* Book::getISBN()
{
	return bookID;
}
/*******************************
Function:Book::getTitle()

Use:accessor method

Arguments:none

Returns:char*: value(s) in the data member bookTitle
********************************/
char* Book::getTitle()
{
	return bookTitle;
}
/*******************************
Function:Book::getPrice()

Use:accessor method

Arguments:none

Returns:double: value in data member bookPrice
********************************/
double Book::getPrice()
{
	return bookPrice;
}
/*******************************
Function:Book::getQuantity()

Use:accessor method

Arguments:none

Returns:int: value of data member quantityAvl
********************************/
int Book::getQuantity()
{
	return quantityAvl;
}
/*******************************
Function:Book::setPrice(double newPrice)

Use:set method

Arguments:double : value to be set in bookPrice

Returns:nothing
********************************/
void Book::setPrice(double newPrice)
{
	if (newPrice <= 0)
		bookPrice = newPrice;
	else
		bookPrice = 0;
}
/*******************************
Function:Book::setQuantity(int newQuantity)

Use: set method

Arguments: int: value to be set in quantityAvl

Returns:nothing
********************************/
void Book::setQuantity(int newQuantity)
{
	if (newQuantity >= 0)
		quantityAvl = newQuantity;
	else
		quantityAvl = 0;
}
/*******************************
Function: Book::fulFillOrder(int bookOrder)

Use:checks the order amount of a specific isbn and subtracts that amount, if available, from quantityAvl and sets the new quantity to the solution of the equation

Arguments:int : the number of books to be ordered for a specific isbn

Returns:int: the amount of books to ship to customer
********************************/
int Book::fulFillOrder(int bookOrder)
{
	int shipped;
	if (bookOrder < 0)
		{
			cout << endl << "Error! Quantity not allowed!" << endl;	// checks to see if book order is a negative number and prints error message if true
			return 0;
		}
	else if (bookOrder <= quantityAvl)
		{
			setQuantity(quantityAvl - bookOrder);			// checks to confirm book order num is less than or equal to the quantity available in the  book object
			return bookOrder;					//sets the quantity to the amount left after a order is subtracted and returns the num to be shipped
		}
	else
		{
			shipped = quantityAvl;					// if order num is larger than the quantity available then set quantity to 0 and return the number to be shipped
			setQuantity(0);
			return shipped;
		}
}
/*******************************
Function: Book::BookPrint()

Use: prints a book object

Arguments:none

Returns:none
********************************/
void Book::BookPrint()
{
	cout << left << setw(14) << bookID;
	cout << left << setw(44) << bookTitle;
	cout << right << fixed << setprecision(2) << setw(5) << bookPrice;
	cout << right << setw(6) << quantityAvl << endl;
}
