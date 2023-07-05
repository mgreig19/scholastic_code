/******************************************
Program: Assignment6: Array based queue adt

Author: Mason Greig

ZID: z1768935

Due date: 11/01/16

Purpose: contains the class definition of the queue class and all associated methods/functions 
******************************************/
#ifndef QUEUE_H				//beginning of class definition
#define QUEUE_H
#include <iostream>
#include <cstdlib>
#include <string>			//libraries required for program
#include <stdexcept>

using std::ostream;
using std::underflow_error;

class Queue
{
	friend ostream& operator<<(ostream& lhs, const Queue& rhs);	//friend function which overloads the << operator

	private:
		int* queue = nullptr;
		size_t qCapacity = 0;
		size_t qSize = 0;					//private data members that hold values of the queue object
		int qFront = 0, qBack = qCapacity - 1;

	public:
		~Queue();
		Queue();
		Queue(const Queue& other);
		Queue& operator=(const Queue& other);
		void clear();
		void push(int queueValue);				//constructors/destructor and method prototypes to be used with the class object
		void pop();
		void reserve(size_t newCapacity);
		size_t size()const;
		size_t capacity()const;
		int front()const;
		int back()const;
		bool empty()const;
};
#endif									//end of class definition

