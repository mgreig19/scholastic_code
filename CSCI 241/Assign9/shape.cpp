/******************************************
Program: Assignment9: Inheritance Program

Author: Mason Greig

ZID: z1768935

Due date: 11/29/16

Purpose: contains the method definitions needed for the shape base class
******************************************/

#include "shape.h"
#include <iostream>
#include <string>		//libraries and file to include
#include <cstdlib>

using namespace std;

/******************************
Function: Shape(const string& newColor)

Use: class constructor that sets the color of the shape to the vaule passed into the constructor

Arguments: const string& newColor: the new color of the shape being created by the shape constructor

Reutrns: nothing
******************************/
Shape::Shape(const string& newColor)
{
        ShapeColor = newColor;			//the passed in string gets stored in the Shape color variable
}
/******************************
Function: virtual ~Shape();

Use: virutal class destructor

Arguments:none

Reutrns:nothing
******************************/
Shape::~Shape()
{
}
/******************************
Function: virtual void print();

Use: prints out the color of the shape

Arguments:none

Reutrns:nothing
******************************/
void Shape::print() const
{
        cout << ShapeColor;			//print the string stored in ShapeColor
}

