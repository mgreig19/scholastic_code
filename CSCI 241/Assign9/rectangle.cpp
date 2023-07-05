/******************************************
Program: Assignment9: Inheritance Program

Author: Mason Greig

ZID: z1768935

Due date: 11/29/16

Purpose: contains the method definitions needed for the rectangle derived class
******************************************/
#include <iostream>
#include <string>				//libraries to include 
#include <cstdlib>

using namespace std;

#include "rectangle.h"				//file to include

/******************************
Function: Rectangle::Rectangle(const string& RectColor, int newHeight, int newWidth) : Shape(RectColor)

Use: the constructor for a rectangle object derived from a shape class

Arguments: const string& RectColor: the color of the rectangle
	   int newHeight: the new height of the object
	   int newWidth: the new width of the object

Reutrns: nothing
******************************/
Rectangle::Rectangle(const string& RectColor, int newHeight, int newWidth) : Shape(RectColor)
{
	height = newHeight;
	width = newWidth;		//the passed in arguments of newHeight and newWidth get stored in height and width respectively
}
/******************************
Function: ~Rectangle();

Use: class destructor

Arguments:none

Reutrns:nothing
******************************/
Rectangle::~Rectangle()
{
}
/******************************
Function: void Rectangle::print()

Use: prints the rectangle object

Arguments: none

Reutrns: nothing
******************************/
void Rectangle::print()const
{
	Shape::print();
	cout << " rectangle, height " << height << ", width " << width << ", area " << get_area() << endl;
}
/******************************
Function: double Rectangle::get_area()

Use: calculates and returns the area of the rectangle object

Arguments: none

Reutrns: double: the area of the object
******************************/
double Rectangle::get_area()const
{
	double area = width * height;			//calculates the area of a rectangle
	return area;
}
