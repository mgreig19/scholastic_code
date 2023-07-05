/******************************************
Program: Assignment8: Sorting Algorythms

Author: Mason Greig

ZID: z1768935

Due date: 11/17/16

Purpose: contains the definitions of the methods that are to be used within a template
******************************************/
#ifndef SORTS_H									//beginning of the header file definition
#define SORTS_H

#include <iostream>
#include <vector>								//libraries to include for the program
#include <fstream>

using namespace std;

template <class T> void buildList(vector<T>&, const char*);			//method prototypes
template <class T> void printList(const vector<T>&, int, int);
/******************************
Function: void buildList(vector<T>& set, const char* fileName)

Use: reads in the data for the vector object of data type T

Arguments: vector<T>&: a reference to vector object of data type T
	   const char* fileName: the name of the file from which the information is being read

Returns: nothing
******************************/
template <class T>
void buildList(vector<T>& set, const char* fileName)
{
	T item;
	ifstream inFile;
	inFile.open(fileName);									//opens the passed in data file
	if(!inFile)
		{
			std::cout << "Error! " << fileName << " did not open properly.";		//if you are not in the file then print an error message
			exit(1);
		}
	inFile >> item;											//read in items from the data file
	while(inFile)
		{
			set.push_back(item);								//while there is data in the file, call the push method for the vector object and pass in the next item being read in from the data file
			inFile >> item;									//read in next piece of data
		}
	inFile.close();											//close the file
}
/******************************
Function: void printList(const vector<T>& set, int itemWidth, int numPerLine)

Use: prints the information stored in the vector object

Arguments: const vector<T>& set: the vector object to be printed
	   int itemWidth: the length each item can occupy
	   int numPerLine: the number of data items that may be printed per line

Returns: nothing
******************************/
template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
	int i = 0;
	while(i < (int) set.size())						//while i is less then the size of the vector object
		{
			cout << setw(itemWidth) << set[i] << ' ';		//print the value stored at i with a space after it and increment i
			i++;
			if(i % numPerLine == 0)
				{
					cout << endl;				//print a newline character whenever i divided by the number of things per line value gives a remainder of zero 
				}
		}
		if (i % numPerLine != 0)
			{
				cout << endl;					//print a newline character whenever i divided by the number of things per line value gives a non zero remainder
			}
}
/******************************
Function: bool lessThan(const T& item1, const T& item2)

Use: the lessThan method used to compare two data type T items from a vector object

Arguments: const T& item1: T data type value to be compared with the other value passed in
	   const T& item2: T data type value to be compared with the other value passed in

Returns: bool: whether of not the first item is less than the second item
******************************/
template <class T>
bool lessThan(const T& item1, const T& item2)
{
	return (item1 < item2);								//return the result of the comparison between two vector data type T objects
}
/******************************
Function: bool greaterThan(const T& a, const T& b)

Use: the greater Than method used to compare two data type T items from a vector object

Arguments: const T& item1: T data type value to be compared with the other value passed in
           const T& item2: T data type value to be compared with the other value passed in

Returns: whether of not the a item is greater than the b item
******************************/
template <class T>
bool greaterThan(const T& a, const T& b)
{
	return (a > b);									//return the result of the comparison between two vector data type T objects
}
#endif											//end of the header file definition
