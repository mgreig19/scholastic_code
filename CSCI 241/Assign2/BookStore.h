#include "Book.h"
#include <fstream>
//*****************************************************************
// FILE:      Book.h
// AUTHOR:    your name
// LOGON ID:  your z-ID
// DUE DATE:  due date of assignment
//
// PURPOSE:   Contains the declaration for the Book class.
//*****************************************************************
#ifndef BOOKSTORE_H
#define BOOKSTORE_H

class BookStore
{
        private:
		Book library[30];
		int libQuantity = 0;
        public:
                BookStore();
                BookStore(const char* newLibrary);
		void BookStorePrint();
		void sortByISBN();
		int searchForISBN(char searchISBN[]);
		void processOrders(const char* Order);
};
#endif

