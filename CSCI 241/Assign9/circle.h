/******************************************
Program: Assignment9: Inheritance Program

Author: Mason Greig

ZID: z1768935

Due date: 11/29/16

Purpose: contains the class definition needed for the circle derived class
******************************************/
#ifndef CIRCLE_H					//beinging of header definition 
#define CIRCLE_H

#include "shape.h"
#include <iostream>
#include <string>					//libraries and file to include
#include <cstdlib>

using namespace std;

class Circle : public Shape				//circle is a derived class of the base class shape
{
        private:
                int radius;				//private data member that differentiates the circle from other shapes
        public:
                Circle(const string& CircleColor, int newRadius);
                ~Circle();
		virtual void print()const;		//an overided method and a defined pure virtual method 
                virtual double get_area() const;
};
#endif							//end of the header file definition
