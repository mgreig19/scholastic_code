/******************************************
Program: Assignment6: Array based queue ADT

Author: Mason Greig

ZID: z1768935

Due date: 11/02/16

Purpose: contains the definitions of the friend functions and class methods that are necessary for the queue class
******************************************/
#include "Queue.h"
/******************************
Function: Queue::Queue()

Use: Class default constructor

Arguments: none

Returns: nothing
******************************/
Queue::Queue()
{
}
/******************************
Function: Queue::~Queue()

Use: Class destructor

Arguments: none

Returns: nothing
******************************/
Queue::~Queue()
{
	delete[] queue;		//deletes the array constructed by the queue class
}
/******************************
Function: Queue::Queue(const Queue& other);

Use: Class copy constructor

Arguments: const Queue& other: an object which is to be copied into a new queue object

Returns: Queue: a queue object with the values of the passed in other object
******************************/
Queue::Queue(const Queue& other)
{
	qCapacity = other.qCapacity;		//assign the capacity and size of the queue object passed in as other to the object pointed to by this 
	qSize = other.qSize;
        if (qCapacity > 0)
                {
                        queue = new int[qCapacity];	//if capacity is greater than 0 then allocate a dynamic array of int of size qCapacity
                }
        else
                {
                        queue = nullptr;		//if capacity is less then or equal to 0 then assign the value of nullptr to the queue array
                }
        for (size_t i = 0; i < qCapacity - 1; i++)
                {
                        queue[i] = other.queue[i];	//copy contents of other object into object pointed to by this
		}
	qFront = other.qFront;
	qBack = other.qBack;			//assign the positions of the old queue array to the new queue array
}
/******************************
Function: Queue& Queue::operator=(const Queue& other);

Use: overloading the assignment operator

Arguments: const Queue& other: the values of the passed in object to be assigned to a new object

Returns: the new object with the values of the other object
******************************/
Queue& Queue::operator=(const Queue& other)
{
	if (this != &other)
                {
                        delete[] queue;						//deletes the queue array that that is currently allocated dynamically 
                        qCapacity = other.qCapacity;				 //assign the capacity and size of the queue object passed in as other to the object pointed to by this
                        qSize = other.qSize;
			if (qCapacity > 0)
                                {
                                        queue = new int[qCapacity];		//if capacity is greater than 0 then allocate a dynamic array of int of size qCapacity
                                }
                        else
                                {
                                        queue = nullptr;			 //if capacity is less then or equal to 0 then assign the value of nullptr to the queue array
                                }
                        for (size_t i = 0; i < qCapacity - 1; i++)
                                {
                                        queue[i] = other.queue[i];		 //copy contents of other object into object pointed to by this
                                }
			qFront = other.qFront;
			qBack = other.qBack;					 //assign the positions of the old queue array to the new queue array
                }
        return *this;								//return queue object
}
/******************************
Function: ostream& operator<<(ostream& lhs, const Queue& rhs)

Use: overload of the ostream operator <<

Arguments: ostream& lhs: the << operator
	   const Queue& rhs: the object to be printed

Returns: a cascading << which allows for multiple print statements to be cascaded within a program 
******************************/
ostream& operator<<(ostream& lhs, const Queue& rhs)
{
	size_t current, i;
        for (current = rhs.qFront, i = 0; i < rhs.qSize; ++i)
        	{
                	lhs << rhs.queue[current] << " ";
                        current = (current + 1) % rhs.qCapacity;		//overloads the << operator to print out the contents of a queue ADT object
                }
        return lhs;
}
/******************************
Function: void Queue::clear()

Use: a method to set the queue valuse back to that of an empty queue array

Arguments: none

Returns: nothing
******************************/
void Queue::clear()
{
	qSize = 0;
	qFront = 0;
	qBack = qCapacity - 1;							//sets the valuse of the queue object back to default empty values
}
/******************************
Function: size_t Queue::size()

Use: accessor method

Arguments: none

Returns: qSize: the number of elements stored in the queue array
******************************/
size_t Queue::size()const
{
	return qSize;								//returns the size of a queue object (the number of elements currently stored in the array)
}
/******************************
Function: size_t Queue::capacity()

Use: accessor method

Arguments: none

Returns: qCapacity: the maximum number of elements allowed with the queue object
******************************/
size_t Queue::capacity()const
{
	return qCapacity;							//returns the maximum storage capacity of the queue array
}
/******************************
Function: bool Queue::empty()

Use: checks for whether or not a queue object is empty

Arguments: none

Returns: bool: whether or not the queue array is empty
******************************/
bool Queue::empty()const
{
	if (qSize == 0)
		{
			return true;						//if the size of the queue array is 0 then return true that the queue is empty otherwise return false
		}
	else
		{
			return false;
		}
}
/******************************
Function: int Queue::front()

Use: error checks for underflow and works as an accessor method to get the value of the front of the queue 

Arguments: none

Returns: int qFront: the value at the front of the queue array
******************************/
int Queue::front()const
{
	if (empty())
		{
			throw underflow_error("queue underflow on front()");		//if the queue is empty then throw an exception to avoid crashing the program otherwise return the front value of the queue array
		}
	else
		{
			return queue[qFront];
		}
}
/******************************
Function: int Queue::back()

Use: error checks for underflow and works as an accessor method to get the value of the back of the queue

Arguments: none

Returns: int qBack: the value at the back of the queue array
******************************/
int Queue::back()const
{
	if (empty())
		{
			throw underflow_error("queue underflow on back()");		 //if the queue is empty then throw an exception to avoid crashing the program otherwise return the value at the back of the queue array
		}
	else
		{
			return queue[qBack];
		}
}
/******************************
Function: void Queue::push(int queueValue)

Use: puts a new value into the queue array

Arguments: int queueValue: a new value to be pushed/inserted into the queue

Returns: nothing
******************************/
void Queue::push(int queueValue)
{
	if (qSize == qCapacity)
		{
			if (qCapacity == 0)
				{
					reserve(1);				//if the qCapacity is equal to the qSize and qCapacity is equal to 0 then call the reserve method of 1
				}
			else
				{
					reserve(qCapacity * 2);			//otherwise reserve double the amount of capacity for new values
				}
		}
	qBack = (qBack + 1) % qCapacity;
	queue[qBack] = queueValue;						//wrap the back of the queue array to the new back and set the qBack variable spot to hold the value of the passed in new queue Value 
	++qSize;								//increment qSize
}
/******************************
Function: void Queue::pop()

Use: removes a value from the front of queue array

Arguments: none

Returns: nothing
******************************/
void Queue::pop()
{
	if (empty())
		{
			throw underflow_error("queue underflow on pop()");	//throw an underflow exception if the program tries to pop a value off of an empty array
		}
	else
		{
			qFront = (qFront + 1) % qCapacity;			//otherwise wrap the qFront spot around to the new front of the array
			--qSize;						//decrement qSize
		}
}
/******************************
Function: void Queue::reserve(size_t newCapacity)

Use: reserve method to increase the capacity of the queue array

Arguments: size_t newCapacity: the new capacity value to be set for the queue object

Returns: nothing
******************************/
void Queue::reserve(size_t newCapacity)
{
	if (newCapacity > qCapacity)						//do this only if the new capacity is larger than the old capacity
		{
			int* tempQueue =  new int[newCapacity];			//temp queue object place holder
			int current = qFront;					//hold value of qFront
			for (size_t i = 0; i < qSize; i++)
				{
					tempQueue[i] = queue[current];
					current = (current + 1) % qCapacity;	//copies the elements in the current queue array into the temporary queue object 
				}
			qCapacity = newCapacity;				//set the capacity to the new capacity
			qFront = 0;						//set value of qFront to 0
			qBack = qSize - 1;					//set value of qBack to one less than the qSize
			delete[] queue;						//delete the old queue array
			queue = tempQueue;					//set the new queue array to the old queue array
		}
}
