/******************************************
Program: Assignment 4: Overloading operators

Author: Mason Greig

ZID: z1768935

Due date: 10/13/16

Purpose: contains the definitions of the friend functions and class methods that are defined in the Vector 3 class
******************************************/
#include "Vector3.h"

/******************************
Function: Vector3::Vector3(double newVector[3] = {0.0}

Use: Class constructor

Arguments: double: these are the new values to be stored in their respective places within the array

Returns: nothing
******************************/
Vector3::Vector3(double valueX, double valueY, double valueZ)
{
	vector[0] = valueX;
	vector[1] = valueY;						//vector values being assigned to array subscripts
	vector[2] = valueZ;
}
/*******************************
Function: friend ostream& operator<<(ostream& lhs, const Vector3& rhs)

Use: overloads the << operator to send a Vector3 object to the standard output

Arguments: ostream&: reference to an ostream object
	   const Vector&: a reference to a constant vector object

Returns: ostream&: the necessary wrapping cout statement place holder for cascading cout statements
********************************/
ostream& operator<<(ostream& lhs, const Vector3& rhs)
{
        lhs << "(" << rhs.vector[0] << ", " << rhs.vector[1] << ", " << rhs.vector[2] << ")";	//overloads the cout operator to work with the vector class and prints a vector object
        return lhs;
}
/*******************************
Function: Vector3 Vector3::operator+(const Vector3& rhs)const

Use: overloads the plus sign operator to allow for use with vector object

Arguments: const Vector3&:reference to the values kept in the private data members

Returns: Vector3: the sum of the two Vector3 objects
********************************/
Vector3 Vector3::operator+(const Vector3& rhs)const
{
        Vector3 newVector = *this;
	for (int i = 0; i < 3; i++)
		{
			newVector.vector[i] += rhs.vector[i];					//a loop to overload the + operator to work with the vector class by adding up each individual vector value from two vector objects and returning a new sum vector object
		}
	return newVector;
}
/*******************************
Function: Vestor3 Vector3::operator-(const Vector3& rhs)const

Use: overloads the minus sign operator to allow for use with the vector object

Arguments: const Vector3&: reference to the values stored in the vector object being passed

Returns: Vector3: the difference between the two Vector3 objects
********************************/
Vector3 Vector3::operator-(const Vector3& rhs)const
{
	Vector3 newVector = *this;
	for (int i = 0; i < 3; i++)
		{
			newVector.vector[i] -= rhs.vector[i];			//function that overloads the minus operator and loops through the vector object subscripts and putting the difference from two subscripts into a new vector object 
		}
	return newVector;
}
/*******************************
Function: double Vector3::operator*(const Vector3& rhs)const

Use: overloads the multiplication operator to allow for use with the vector object

Arguments: const Vector3&: reference to the values stored in the vector object being passed

Returns: double: the scalar product of the two objects
********************************/
double Vector3::operator*(const Vector3& rhs)const
{
	Vector3 lhs = *this;
	double scalProduct[3];
	double scalTotal;
	for (int i = 0; i < 3; i++)						//loops through each subscripts of the two vector objects and multiplies each pair of subscripts values to get a new vector value to be stored in a new vector object
		{
			scalProduct[i] = lhs.vector[i] * rhs.vector[i];
		}
	scalTotal = scalProduct[0] + scalProduct[1] + scalProduct[2];		// the sum of the subscripts from the scalProduct array
	return scalTotal;
}
/*******************************
Function: Vector3 Vector3::operator*(double num)const

Use: overloads the multiplication operator to allow for use with the vector object

Arguments: double: a constant number to multiply an object by

Returns: the product of the Vector3 object and a double
********************************/
Vector3 Vector3::operator*(double num)const
{
	Vector3 newVector = *this;
	for (int i = 0; i < 3; i++)
		{
			newVector[i] *= num;					//assigns the product of a number and an array subscript to the same array subscript
		}
	return newVector;
}
/*******************************
Function: Vector3 operator*(double num, const Vector3&)

Use: overloads the multiplication operator to allow for use with the vector object

Arguments: const Vector3&: reference to the values stored in the vector object being passed
           double: a constant number to multiply an object by

Returns: Vector3: the product of the Vector3 object and a double
********************************/
Vector3 operator*(double num, const Vector3& rhs)
{
        Vector3 newVector = rhs;
	for (int i = 0; i < 3; i++)
		{
        		newVector[i] *= num;					//a loop to put the product of a number and an array subscript into a new array subscript
		}
        return newVector;
}
/*******************************
Function: double Vector3::operator[](int sub)const

Use: overloads the [] operator in order to use it with reading the vector class

Arguments: int sub: the subscript number of the vector class object

Returns: 
********************************/
double Vector3::operator[](int sub)const
{
	return vector[sub];							//returns the value of the subscript in array
}
/*******************************
Function: double Vector3::operator[](int sub)

Use: overloads the [] operator in order to use it with writting to the vector class

Arguments: int sub: the subscript number of the vector class object to be changed

Returns: 
********************************/
double& Vector3::operator[](int sub)
{
	return vector[sub];							//assigns a new value to the subscript of the array
}
/*******************************
Function: bool Vector3::operator==(const Vector3& rhs)const

Use: overloads the equivalent operator to allow for use with the vector object

Arguments: const Vector3&: reference to the values stored in the vector object being passed

Returns: boolean: whether the two vector objects are equal
********************************/
bool Vector3::operator==(const Vector3& rhs)const
{
	return (vector[0] == rhs.vector[0] and vector[1] == rhs.vector[1] and vector[2] == rhs.vector[2]);	//compares to vector objects and returns whether of not they are equivalent
}
