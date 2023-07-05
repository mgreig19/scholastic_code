/******************************************
Program: Assignment 5: Overloading operators and dynamic memory allocation

Author: Mason Greig

ZID: z1768935

Due date: 10/25/16

Purpose: contains the header file that defines the VectorN class
******************************************/
#ifndef VECTORN_H                                                       //start of header file definition
#define VECTORN_H
#include <iostream>
#include <string>                                                       //libraries included for program
#include <cstdlib>
#include <stdexcept>

using std::ostream;                                                     //ostream class included for << overloading
using std::out_of_range;						//out_of_range included to write at methods

class VectorN
{
        friend ostream& operator<<(ostream& lhs, const VectorN& rhs);           //stand alone functions that have access to the private data members of the class
        friend VectorN operator*(double num, const VectorN& rhs);

        private:
                double* vectorN = nullptr;
		size_t vCapacity = 0;                                       //the data members to hold the vectorN class values
        public:
		~VectorN();
		VectorN();
		VectorN(const VectorN& other);
                VectorN(const double newValues[], size_t newCapacity);
		VectorN& operator=(const VectorN& other);
                VectorN operator+(const VectorN& rhs)const;
                VectorN operator-(const VectorN& rhs)const;
                VectorN operator*(double num)const;
                double operator*(const VectorN& rhs)const;                      //method prototypes for all methods used in program
                double operator[](int sub)const;
                double& operator[](int sub);
		double at(int sub) const;
		double& at(int sub);
                bool operator==(const VectorN& rhs)const;
		size_t size()const;
		void clear();
};
#endif										//end of the header file
