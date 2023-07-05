/******************************************
Program: Assignment9: Inheritance Program

Author: Mason Greig

ZID: z1768935

Due date: 11/29/16

Purpose: contains the class definition needed for the triangle derived class
******************************************/
#ifndef TRIANGLE_H			//begining of the header file
#define TRIANGLE_H

#include "shape.h"
#include <iostream>
#include <string>			//file and libraries to include
#include <cstdlib>

using namespace std;

class Triangle : public Shape		//triangle is a derived class of the base class shape
{
        private:
                int base, height;	//private data members that differentiate the triangle object from other shapes
        public:
                Triangle(const string& TriColor, int newHeight, int newBase);
                ~Triangle();
		virtual void print()const;	//method prototypes
                virtual double get_area() const;
};
#endif					//end of the header file definition



