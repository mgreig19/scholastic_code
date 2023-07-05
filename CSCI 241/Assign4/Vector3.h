/******************************************
Program: Assignment 4: Overloading operators

Author: Mason Greig

ZID: z1768935

Due date: 10/13/16

Purpose: contains the header file that defines the Vector 3 class
******************************************/
#ifndef VECTOR3_H							//start of header file definition
#define VECTOR3_H
#include <iostream>
#include <string>							//libraries included for program
#include <cstdlib>

using std::ostream;							//ostream class included for << overloading

class Vector3
{
	friend ostream& operator<<(ostream& lhs, const Vector3& rhs);		//stand alone functions that could not be created as methods
	friend Vector3 operator*(double num, const Vector3& rhs);

	private:
		double vector[3] = {0.0};					//the data member to hold the vector values of the class
	public:
		Vector3(double valueX = 0.0, double valueY = 0.0, double valueZ = 0.0);
                Vector3 operator+(const Vector3& rhs)const;
                Vector3 operator-(const Vector3& rhs)const;
		Vector3 operator*(double num)const;
		double operator*(const Vector3& rhs)const;			//method prototypes for the operator overload methods and the constructor class has default argument values of 0
		double operator[](int sub)const;
		double& operator[](int sub);
		bool operator==(const Vector3& rhs)const;
};
#endif									//end of header definition
