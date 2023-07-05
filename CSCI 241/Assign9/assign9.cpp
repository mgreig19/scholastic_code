/******************************************
Program: Assignment9: Inheritance Program

Author: Mason Greig

ZID: z1768935

Due date: 11/29/16

Purpose: contains the driver program for assignment 9
******************************************/

#include <iostream>
#include <iomanip>
#include <string>			//libraries to include
#include <cstdlib>
#include <vector>

#include "shape.h"
#include "circle.h"
#include "rectangle.h"			//header files to include
#include "triangle.h"

using namespace std;

int main()
{
	vector<Shape *> shapes(6);	//creates six pointers to shape objects that are stored in a vector

	shapes[0] = new Circle("green", 10);
	shapes[1] = new Circle("orange", 5);
	shapes[2] = new Rectangle("red", 8, 6);
	shapes[3] = new Rectangle("blue", 3, 7);	//initializing the vector spaces to the different shape objects with passed in values
	shapes[4] = new Triangle("yellow", 8, 4);
	shapes[5] = new Triangle("black", 4, 10);

	cout << "Printing all shapes...\n" << endl;	//prints a title for the first section of information

	for(unsigned int i = 0; i < shapes.size(); i++)
		{
			shapes[i]->print();		//prints all objects located in the vector
		}

	cout << "\nPrinting only triangles...\n" << endl;	//prints a title for the second information section

	for(unsigned int i = 0; i < shapes.size(); i++)
		{
			Triangle* triPtr = dynamic_cast<Triangle *>(shapes[i]);	//downcasts the shape object in vector in order to check for a triangle shape

			if(triPtr != nullptr)
				{
					shapes[i]->print();	//prints all triangle shapes
				}
		}
	for(unsigned int i = 0; i < shapes.size(); i++)
		{
			delete shapes[i];			//deletes the stored information in the vector
		}
	return 0;						//end program
}
