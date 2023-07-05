/******************************************
Program: Assignment5: Dynamic Memory Allocation

Author: Mason Greig

ZID: z1768935

Due date: 10/25/16

Purpose: contains the definitions of the friend functions and class methods that are defined in the Vector N class
******************************************/
#include "VectorN.h"

/******************************
Function: VectorN::VectorN()

Use: Class default constructor

Arguments: none

Returns: nothing
******************************/
VectorN::VectorN()
{
	vCapacity = 0;			//default constructor which sets the initial capacity to 0 and initializes vectorN array to nullptr(this creates an empty vectoN object)
	vectorN = nullptr;
}
/******************************
Function: VectorN::VectorN(const double newValues[], size_t capacity }

Use: Class constructor

Arguments: const double newValues[]: an array of new values to be set in the dynamic vector array
	   size_t capacity: the number of elements in the dynamic array
Returns: nothing
******************************/
VectorN::VectorN(const double newValues[], size_t newCapacity)
{
	vCapacity = newCapacity;							// set the capacity of the new array object to the capacity of a passed in object
	if (vCapacity > 0)
		{
			vectorN = new double[vCapacity];				 // if the capacity of the array is greater than 0 then initialize the array to dynamically hold the number of values passed into the function
		}
	else
		{
			vectorN = nullptr;						//if the capacity is less than or equal to 0 then set the array value to nullptr
		}
	for (size_t i = 0; i < vCapacity; i++)
		{
			vectorN[i] = newValues[i];					//copy the values from the other object into the new vectorN object
		}
}
/******************************
Function: VectorN::VectorN(const VectorN& other)

Use: Class copy constructor

Arguments: const VectorN&: a vector N object being passed by reference

Returns: nothing
******************************/
VectorN::VectorN(const VectorN& other)
{
	vCapacity = other.vCapacity;							// set the capacity of the new array object to the capacity of a passed in object
	if (vCapacity > 0)
		{
			vectorN = new double[vCapacity];				// if the capacity of the array is greater than 0 then initialize the array to dynamically hold the number of values passed into the function
		}
	else
		{
			vectorN = nullptr;						//if the capacity is less than or equal to 0 then set the array value to nullptr
		}
	for (size_t i = 0; i < vCapacity; i++)
		{
			vectorN[i] = other.vectorN[i];					//copy the values from the other object into the new vectorN object
		}
}
/******************************
Function: VectorN::VectorN()

Use: Class destructor

Arguments: none

Returns: nothing
******************************/
VectorN::~VectorN()
{
	clear();										// calls the clear() method
}
/******************************
Function: VectorN& VectorN::operator=(const VectorN& other)

Use: overloads the = operator to assign one VectorN object to another

Arguments: const VectorN&: the VectorN object containing the values which are to be assigned to a new VectorN object

Returns: vectorN: object which contains the values of another object
******************************/
VectorN& VectorN::operator=(const VectorN& other)
{
	if (this != &other)
		{
			delete[] vectorN;							 // delete the old vectorN array and set the capacity of the new array object to the capacity of a passed in object
			vCapacity = other.vCapacity;
			if (vCapacity > 0)
				{
					vectorN = new double[vCapacity];			// if the capacity of the array is greater than 0 then initialize the array to dynamically hold the number of values passed into the function
				}
			else
				{
					vectorN = nullptr;					//if the capacity is less than or equal to 0 then set the array value to nullptr
				}
			for (size_t i = 0; i < vCapacity; i++)
                		{
                        		vectorN[i] = other.vectorN[i];				//copy the values from the other object into the new vectorN object
                		}
		}
	return *this;										//return the object
}
/*******************************
Function: void VectorN::clear()

Use: deallocates and deletes the vectorN dynamic array (creates an empty array object)

Arguments: none

Returns: nothing
********************************/
void VectorN::clear()
{
	delete[] vectorN;
	vectorN = nullptr;								//deletes the vectorN array and sets the vectorN object values to that of an empty or NULL array
	vCapacity = 0;
}
/*******************************
Function: size_t VectorN::size()const

Use: gets the value stored in vCapacity

Arguments: none

Returns: returns the current size of the dynamic memory array
********************************/
size_t VectorN::size()const
{
	return vCapacity;								// returns the value stored in capacity
}
/*******************************
Function: friend ostream& operator<<(ostream& lhs, const Vector3& rhs)

Use: overloads the << operator to send a VectorN object to the standard output

Arguments: ostream&: reference to an ostream object
           const Vector&: a reference to a constant vector object

Returns: ostream&: the necessary wrapping cout statement place holder for cascading cout statements
********************************/
ostream& operator<<(ostream& lhs, const VectorN& rhs)
{
	size_t count = 0;
	if (rhs.vCapacity <= 0)
		{
			lhs << "()";							//overloads the << operator to print a vectorN object
		}
	else
		{
			lhs << "(";
			for (size_t i = 0; i < rhs.vCapacity - 1; i++)
				{
					lhs << rhs.vectorN[i] << ", ";
					count++;
				}
			lhs <<  rhs.vectorN[count++] << ")";
        	}
	return lhs;
}
/*******************************
Function: VectorN VectorN::operator+(const VectorN& rhs)const

Use: overloads the plus sign operator to allow for use with vectorN object

Arguments: const VectorN&:reference to the values kept in the private data members

Returns: result: object which contains the sum of the two VectorN objects
********************************/
VectorN VectorN::operator+(const VectorN& rhs)const
{
        VectorN lhs = *this;
	VectorN result;
	if(lhs.vCapacity > rhs.vCapacity)
		{
			result.vCapacity = rhs.vCapacity;						 //checks which array has a larger capacity and assigns the smaller capcity to a new object
		}
	else
		{
			result.vCapacity = lhs.vCapacity;
		}
	result.vectorN = new double[result.vCapacity];							 //makes the result object array empty and ready to recieve values
	for(size_t i = 0; i < result.vCapacity; i++)
		{
			result.vectorN[i] = lhs.vectorN[i] + rhs.vectorN[i];				//stores the sum of two objects into a new vectorN object
		}
        return result;
}
/*******************************
Function: VestorN VectorN::operator-(const VectorN& rhs)const

Use: overloads the minus sign operator to allow for use with the vectorN object

Arguments: const VectorN&: reference to the values stored in the vectorN object being passed

Returns: VectorN: the difference between the two VectorN objects
********************************/
VectorN VectorN::operator-(const VectorN& rhs)const
{
        VectorN lhs = *this;
        VectorN result;
        if(lhs.vCapacity > rhs.vCapacity)
                {
                        result.vCapacity = rhs.vCapacity;						//checks which array has a larger capacity and assigns the smaller capcity to a new object
                }
        else
                {
                        result.vCapacity = lhs.vCapacity;
                }
	result.vectorN = new double[result.vCapacity];							//makes the result object array empty and ready to recieve values
        for(size_t i = 0; i < result.vCapacity; i++)
                {
                        result.vectorN[i] = lhs.vectorN[i] - rhs.vectorN[i];				//stores the difference of two objects into a new vectorN object
                }
        return result;
}
/*******************************
Function: double VectorN::operator*(const VectorN& rhs)const

Use: overloads the multiplication operator to allow for use with the vectorN object

Arguments: const VectorN&: reference to the values stored in the vector object being passed

Returns: double: the scalar product of the two objects
********************************/
double VectorN::operator*(const VectorN& rhs)const
{
        VectorN lhs = *this;
	VectorN result;
	double scalTotal = 0;
	if(lhs.vCapacity > rhs.vCapacity)
                {
                        result.vCapacity = rhs.vCapacity;						//checks which array has a larger capacity and assigns the smaller capcity to a new object
                }
        else
                {
                        result.vCapacity = lhs.vCapacity;
                }
	result.vectorN = new double[result.vCapacity];						//makes the result object array empty and ready to recieve values
        for (size_t i = 0; i < result.vCapacity; i++)                                             //loops through the dynamic array to get the product of two objects and then to take each product and add it to the scalar product variable
                {
                        result.vectorN[i] = lhs.vectorN[i] * rhs.vectorN[i];
			scalTotal += result.vectorN[i];
                }
        return scalTotal;
}
/*******************************
Function: VectorN VectorN::operator*(double num)const

Use: overloads the multiplication operator to allow for use with the vectorN object

Arguments: double: a constant number to multiply an object by

Returns: VectorN: the product of the VectorN object and a double
********************************/
VectorN VectorN::operator*(double num)const
{
        VectorN result = *this;
        for (size_t i = 0; i < result.vCapacity; i++)
                {
                        result.vectorN[i] *= num;                                    //assigns the product of a number and a vector object to a new vectorN object
                }
        return result;
}
/*******************************
Function: VectorN operator*(double num, const VectorN&)

Use: overloads the multiplication operator to allow for use with the vector object

Arguments: const VectorN&: reference to the values stored in the vector object being passed
           double: a constant number to multiply an object by

Returns: VectorN: the product of the VectorN object and a double
********************************/
VectorN operator*(double num, const VectorN& rhs)
{
	VectorN result(rhs);
        for (size_t i = 0; i < result.vCapacity; i++)
                {
                        result.vectorN[i] *= num;                                    //a loop to put the product of a num and an object into a result object
                }
        return result;
}
/*******************************
Function: double VectorN::operator[](int sub)const

Use: overloads the [] operator in order to use it with reading the vector class

Arguments: int sub: the subscript number of the vector class object

Returns: double: the value stored at the given subscript
********************************/
double VectorN::operator[](int sub)const
{
        return vectorN[sub];                                                     //returns the value of the subscript value of the array
}
/*******************************
Function: double VectorN::operator[](int sub)

Use: overloads the [] operator in order to use it with writting to the vector class

Arguments: int sub: the subscript number of the vector class object to be changed

Returns: double: a number representing the value stored at the subscript number given to the array
********************************/
double& VectorN::operator[](int sub)
{
        return vectorN[sub];                                                     //assigns a new value to the subscript of the array which calls the function
}
/*******************************
Function: double VectorN::at(int sub) const

Use: subscript error checking

Arguments: int sub: a number which represents the subscript of the array

Returns: double: the value stored at the given subscript of the array
********************************/
double VectorN::at(int sub) const
{
	if (sub < 0 or sub >= vCapacity)
		{
			throw out_of_range("subscript out of range!");		//if the subscript of the array is less than 0 or greater than or equal to the array capacity then throw an exception to prevent crash/ returns subscript array value
		}
	return vectorN[sub];
}
/*******************************
Function: double& VectorN::at(int sub)

Use: subscript error checking(write version)

Arguments: int sub: a number which represents the subscript of the array

Returns: double: the value stored at the given subscript of the array
********************************/
double& VectorN::at(int sub)
{
	if (sub < 0 or sub >= vCapacity)
                {
                        throw out_of_range("subscript out of range!");		 //if the subscript of the array is less than 0 or greater than or equal to the array capacity then throw an exception to prevent crash/ returns subcript array value 
                }
        return vectorN[sub];
}
/*******************************
Function: bool VectorN::operator==(const VectorN& rhs)const

Use: overloads the equivalent operator to allow for use with the vector object

Arguments: const VectorN&: reference to the values stored in the vector object being passed

Returns: boolean: whether the two vector objects are equal
********************************/
bool VectorN::operator==(const VectorN& rhs)const
{
	VectorN lhs = *this;
	size_t count = 0;
        if(lhs.vCapacity > rhs.vCapacity or rhs.vCapacity > lhs.vCapacity)		//if the left capacity is greater than the right or if the right side capacity is greater than the left then return false
		{
			return false;
		}
	for(size_t i = 0; i < vCapacity; i++)
		{
			if (lhs.vectorN[i] == rhs.vectorN[i])				//if the left and right array values are equal then increment count to keep track of the number of equivalent values
				{
					count++;
				}
			else
				{
					return false;					//if the left and right array values are not equal then return false
				}
		}
	if (count == vCapacity)
		{
			return true;							//if the number of equivalent values is equal to the capacity of the array then return true
		}
	return true;
}

