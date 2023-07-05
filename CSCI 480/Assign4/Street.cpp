/*****************************************************************
 FILE:      Street.cpp
 AUTHOR:    Mason Greig
 ID:        grei
 DUE DATE:  5/03/2018

 PURPOSE:   Contains the method definitions for the Street.h (class)
*****************************************************************/
#include "Street.h"
#include <iostream>

/****************************************************************
 Default Constructor

 Arguments: None

 Reuturns: N/A

*****************************************************************/
Street::Street(){
}
/****************************************************************

 Constructor

 Arguments: int number: the street number of the street
	    string name: the name of the street
	    string direction: the direction of traffic 
	    string firstSec: the section of intersection which the traffic goes through first
	    string secondSec: the section of intersection which the traffic goes through second
 
 Use: Builds a street object

 Returns: nothing, just adds a new element to the map

****************************************************************/
Street::Street(int number, string name, string direction, string firstSec, string secondSec)
	{

		setStreetNumber(number);
		setStreetName(name);
		setTravelDirection(direction);
		setFirstSection(firstSec);
		setSecondSection(secondSec);

	}
/****************************************************************

 Method(s): Accessor methods for the street class

 Arguments: int: an int to set a new street number
	    string: strings to set new values for the private members of the street class

 Returns: int: the street number of street object
	  string: the string values of the private data members

****************************************************************/
void Street::setStreetNumber(int newNumber){

	streetNumber = newNumber;
}

int Street::getStreetNumber(){

	return streetNumber;

}

void Street::setStreetName(string newName){

        streetName = newName;
}

string Street::getStreetName(){

        return streetName;

}

void Street::setTravelDirection(string newDirection){

	travelDirection = newDirection;

}

string Street::getTravelDirection(){

	return travelDirection;
}

void Street::setFirstSection(string newSection){

	firstSection = newSection;
}
string Street::getFirstSection(){

	return firstSection;
}

void Street::setSecondSection(string newSection){

	secondSection = newSection;
}

string Street::getSecondSection(){

	return secondSection;
}
