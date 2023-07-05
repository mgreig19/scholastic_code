
/******************************************
Program: Assignment9: Inheritance Program

Author: Mason Greig

ZID: z1768935

Due date: 11/29/16

Purpose: contains the class definition needed for the rectangle derived class
******************************************/
#ifndef RECTANGLE_H				//begining of the header file
#define RECTANGLE_H

#include <iostream>
#include <string>
#include <cstdlib>				//file and libraries to include
#include "shape.h"

using namespace std;

class Rectangle : public Shape			//rectangle is a derived class of the abstract class shape
{
        private:
                int height, width;		//private data members that differentiate a rectangle object from other shapes
        public:
                Rectangle(const string& RectColor, int newHeight, int newWidth);
                ~Rectangle();
		virtual void print()const;	//method prototypes
                virtual double get_area() const;
};
#endif						//end of the header file deifinition

