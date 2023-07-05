//*****************************************************************
// FILE:      Street.h
// AUTHOR:    Mason Greig
// ID:        grei
// DUE DATE:  5/03/2018
//
// PURPOSE:   Contains the declaration of the Street class
//*****************************************************************
//begin header guard
#ifndef STREET_H
#define STREET_H
#include <string>

using namespace std;

//start of Street class declaration
class Street{

	//private data members
	private:

		string streetName = "";
		int streetNumber = 0;
		string travelDirection = "";
		string firstSection = "";
		string secondSection = "";

	//public class functions
	public:

		Street();
		Street(int number, string name, string direction, string firstSec, string secondSec); 
		void setStreetNumber(int number);
		int getStreetNumber();
		void setStreetName(string newName);
		string getStreetName();
		void setTravelDirection(string direction);
		string getTravelDirection();
		void setFirstSection(string newSection);
		string getFirstSection();
		void setSecondSection(string newSection);
                string getSecondSection();
};

#endif
//end header guard
