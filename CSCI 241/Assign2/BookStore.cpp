#include "BookStore.h"
#include "Book.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

/*******************************
Function:BookStore::BookStore();

Use:Default constructor

Arguments:none

Returns:none
********************************/
BookStore::BookStore()
{
}
/*******************************
Function:BookStore::BookStore(const char* newLibrary);

Use:Alternate constructor

Arguments: const char*:a new library to be read in from a txt file

Returns:nothing
********************************/
BookStore::BookStore(const char* newLibrary)
{
	ifstream inFile;										//creates the input file variable to hold the file input into the method argument 
	inFile.open(newLibrary, ios::binary);								//opens the input file
	if (inFile.fail())										//test for failure to open file
		{
			cerr << "Error! The input file did not open properly!" << endl;
			exit(-1);
		}
	else
		{
			inFile.read((char*) this, sizeof(BookStore));					//reads file into book store class object which creates book objects from the file information
		}
	inFile.close();											//closes input file
	sortByISBN();											//method to sort books in accending order within book store object
}
/*******************************
Function:BookStore::BookStorePrint()

Use:prints out a list of book objects

Arguments:none

Returns:none
********************************/
void BookStore::BookStorePrint()
{
	cout << "\nBook Inventory Listing\n" << endl;														//displays a heading and labeling for the book store info
	cout << left << setw(14) << "ISBN" << left << setw(44) << "Title" << right << setw(5) << "Price" << right << setw(6) << "Qty." << endl << endl;
	for (int i = 0; i < libQuantity; i++)
		{
			library[i].BookPrint();															// loop which prints out each book object of the book store object class
		}
}
/*******************************
Function:BookStore::searchForISBN(char searchISBN[])

Use:searches the book store object for a specific isbn 

Arguments: char: the isbn to be searched for in book store object

Returns:int: returns the isbn number of the book that was searched for
********************************/
int BookStore::searchForISBN(char searchISBN[])
{

	int low = 0;
	int high = (libQuantity - 1);
	int mid;

	while (low <= high)
    		{
      			mid = (low + high) / 2;

      			if (strcmp(searchISBN, library[mid].getISBN()) == 0)	// compares whether or not the isbn that the file is searching for is equal to or less than the isbn's located in the book store object library returns isbn if successful
         			return mid;
      			if (strcmp(searchISBN, library[mid].getISBN()) < 0)
         			high = mid - 1;
      			else
         			low = mid + 1;
    		}

   return -1;
}
/*******************************
Function: BookStore::sortByISBN()

Use:sorts the book objects in the book store object into accending order

Arguments:none

Returns:none
********************************/
void BookStore::sortByISBN()
{
   int i, j;
   Book bucket;

   for (i = 1; i < libQuantity; i++)									// loop which binary sorts the book objects within book store object library
      	{
      		bucket = library[i];

      		for (j = i; (j > 0) && (strcmp(library[j-1].getISBN(), bucket.getISBN()) > 0); j--)
         		{
				library[j] = library[j-1];
			}
      		library[j] = bucket;
      	}
}
/*******************************
Function:BookStore::processOrders(const char* Order)

Use:takes input from a file and gets the book information for that order

Arguments:const char*: the file to be opened and read by the method

Returns:nothing
********************************/
void BookStore::processOrders(const char* Order)
{
   ifstream inFile;
   char orderNumber[7];
   char isbn[11];
   int orderQuantity;
   int numShipped;

   inFile.open(Order);										//opens the file that is given through the argument Order
   if (inFile.fail())										// if the file fails to open display an error message
	{
		cout << "Error! Input file not opened properly!" << endl;
		exit(-1);
	}
   else
	{
		cout << "\nOrder Listing\n" << endl;						// labeling for list of book objects
   		inFile >> orderNumber;								// retrieve the orderNumber from the file
   		while (!inFile.eof())								//loops through body while not at the end of file
      			{
      				inFile >> isbn;							// retrieve the information in isbn
      				inFile >> orderQuantity;					//retrieve the information in orderQuantity

      				int index = searchForISBN(isbn);				//sets index to the found isbn from searchForISBN() method
      				if (index == -1)
         				{
						cout <<  "Order #" << orderNumber << ":" << " error - " << "ISBN " << isbn << " does not exist." << endl;	// if search is unsuccessful then print error message.
					}
      				else
         				{
         					int numShipped = library[index].fulFillOrder(orderQuantity);
         					cout << "Order #" << orderNumber << ":" << " ISBN " << isbn							//prints out the order details of the current order
						<< ", " << numShipped << " out of " << orderQuantity
						<< " shipped, order total = $" << (orderQuantity * (library[index].getPrice())) << endl;
         				}

      				inFile >> orderNumber;														// reinitiates loop
			}
	}

   inFile.close();																		// closes input file
}
