//*****************************************************************
// FILE:      Book.h
// AUTHOR:    your name
// LOGON ID:  your z-ID
// DUE DATE:  due date of assignment
// 
// PURPOSE:   Contains the declaration for the Book class.
//*****************************************************************
#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <iostream>

class Book
{
	private:
		char bookID[11] = {};
		char bookTitle[41] = {};
		double bookPrice = 0;
		int quantityAvl = 0;
	public:
		Book();
		Book(char newISBN[], char newTitle[], double newPrice, int newQuantity);
		char* getISBN();
		char* getTitle();
		double getPrice();
		int getQuantity();
		void setPrice(double newPrice);
		void setQuantity(int newQuantity);
		int fulFillOrder(int bookOrder);
		void BookPrint();

};
#endif
