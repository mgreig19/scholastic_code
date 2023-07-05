/******************************************
Program: Assignment9: Inheritance Program

Author: Mason Greig

ZID: z1768935

Due date: 11/29/16

Purpose: contains the method definitions needed for the triangle derived class
******************************************/

#include <iostream>
#include <string>				//libraries and file to include
#include <cstdlib>
#include "triangle.h"

using namespace std;

/******************************
Function: Triangle::Triangle(const string& TriColor, int newBase, int newHeight) : Shape(TriColor)

Use: the constructor for a triangle object derived from a shape class

Arguments: const string& TriColor: the color of the Triangle
           int newHeight: the new height of the object
           int newBase: the new base of the object

Reutrns: nothing
******************************/
Triangle::Triangle(const string& TriColor, int newHeight, int newBase) : Shape(TriColor)
{
        height = newHeight;
        base = newBase;				//the ints newHeight and newBase are stored in height and base respectively
}
/******************************
Function: ~Triangle();

Use: class destructor

Arguments:none

Reutrns:nothing
******************************/
Triangle::~Triangle()
{
}
/******************************
Function: void Triangle::print()

Use: prints the triangle object

Arguments: none

Reutrns: nothing
******************************/
void Triangle::print()const
{
        Shape::print();
        cout << " triangle, height " << height << ", base " << base << ", area " << get_area() << endl;
}
/******************************
Function: double Triangle::get_area()

Use: calculates and returns the area of the triangle object

Arguments: none

Reutrns: double: the area of the object
******************************/
double Triangle::get_area()const
{
        double area = 0.5 * base * height;		//calculates the area of a triangle
        return area;
}

