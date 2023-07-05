/******************************************
Program: Assignment9: Inheritance Program

Author: Mason Greig

ZID: z1768935

Due date: 11/29/16

Purpose: contains the method definitions needed for the circle derived class
******************************************/

#include "circle.h"
#include <iostream>
#include <string>			//libraries and file to include
#include <cstdlib>
#include <math.h>

#define _USE_MATH_DEFINES		//symbolic constant which allows use of math.h library constants

using namespace std;
/******************************
Function: Circle(const string& CircleColor, int newRadius);

Use: class constructor that passes the color of the shape to the base class constructor and sets the radius of the$

Arguments: const string& newColor: the new color of the circle being passed to the shape constructor for initializ$
           int radius: holds the value that is the radius of the circle
Reutrns: nothing
******************************/
Circle::Circle(const string& CircleColor, int newRadius) : Shape(CircleColor)
{
        radius = newRadius;		//the passed in int is stored in radius
}
/******************************
Function: ~Circle();

Use: class destructor

Arguments:none

Reutrns:nothing
******************************/
Circle::~Circle()
{
}
/******************************
Function: Circle::print();

Use: overode method which prints the circle object

Arguments: none

Reutrns: nothing
******************************/
void Circle::print() const
{
	Shape::print();
	cout << " circle, radius " << radius << ", " << "area " << get_area() << endl;
}
/******************************
Function: Circle::get_area();

Use: calculates and returns the area of the circle

Arguments: none

Reutrns: double: the area of the circle
******************************/
double Circle::get_area() const
{
	double area = (M_PI * (radius * radius));	//calculates the area of a circle
	return area;
}
