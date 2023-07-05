/******************************************
Program: Assignment9: Inheritance Program

Author: Mason Greig

ZID: z1768935

Due date: 11/29/16

Purpose: contains the class definition needed for the abstract shape base class
******************************************/
#ifndef SHAPE_H						//begin definition of the header file
#define SHAPE_H

#include <iostream>
#include <string>					//included libraries
#include <cstdlib>

using namespace std;

class Shape						//abstract base class
{
	private:
		string ShapeColor;			//private data member
	public:
		Shape(const string& color);
		virtual ~Shape();
		virtual void print() const;		//public methods which include virtual and pure virtual methos for the derived classes use
		virtual double get_area() const = 0;
};
#endif							//end definition of header file
