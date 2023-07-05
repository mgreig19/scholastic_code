/******************************************
Program: Assignment7: Linked queue ADT

Author: Mason Greig

ZID: z1768935

Due date: 11/10/16

Purpose: contains the definitions of the friend functions and class methods that are necessary for the linked queue
******************************************/
#ifndef LINKEDQ_H                         //beginning of class definition
#define LINKEDQ_H
#include <iostream>
#include <stdexcept>

using std::ostream;
using std::underflow_error;

/************************************
Struct declaration creating a node and associated method
************************************/
template <class T>
struct Node
	{
		T data;
		Node<T>* next;
		Node(const T& = T(), Node<T>* next = nullptr);	//node structure
	};
/******************************
Function: Node(const T& newData, Node<T>* newNext)

Use: node struct default constructor

Arguments: const T& newData: the value to be added to the linked list
	   Node<T>* newNext: the new pointer address for the next availble variable subscript in the linked list

Returns: nothing
******************************/
template <class T>
Node<T>::Node(const T& newData, Node<T>* newNext)
	{
		data = newData;
		next = newNext;		//node method setting the node values to the passed in values
	}
/************************************
Class declaration of a queue object as a linked list and associated methods
************************************/
template <class T>
class Queue;

template <class T>								//pre declarations for the queue class the the friend function
std::ostream& operator<<(std::ostream&, const Queue<T>&);

template <class T>
class Queue
{
	friend std::ostream& operator<< <>(std::ostream&, const Queue<T>&);	//the stand alone friend function to overload the << operator to print a linked queue object

        private:
        	Node<T>* qFront = nullptr;
		Node<T>* qBack = nullptr;			//the private data members that represent the different elements required for a linked queue
                size_t qSize = 0;
		void copyList(const Queue<T>& other);
	public:
		Queue();
		~Queue();
		Queue(const Queue<T>& other);
		Queue<T>& operator=(const Queue<T>& other); 		//the public methods, constructors, and destructor to be implemented/called with the linked queue object 
		void clear();
		void push(const T& newValue);
		void pop();
		bool empty() const;
		size_t size()const;
		const T& front()const;
		const T& back()const;
};
/******************************
Function: Queue<T>::Queue()

Use: Class default constructor

Arguments: none

Returns: nothing
******************************/
template <class T>
Queue<T>::Queue()
{
}
/******************************
Function: Queue<T>::~Queue()

Use: Class destructor

Arguments: none

Returns: nothing
******************************/
template <class T>
Queue<T>::~Queue()
{
	clear();						//calls clear() method
}
/******************************
Function: Queue<T>::Queue(const Queue<T>& other)

Use: Class copy constructor

Arguments: const Queue<T>& other: a passed in reference to a linked queue object

Returns: nothing
******************************/
template <class T>
Queue<T>::Queue(const Queue<T>& other)
{
	qFront = nullptr;
	qBack = nullptr;
	qSize = 0;				//sets the elements of the linked queue to that of an empty queue and then calls the copyList() method to copy the values of the passed in linked queue into the linked queue object 
	copyList(other);
}
/******************************
Function: Queue<T>& Queue<T>::operator=(const Queue<T>& other)

Use: Class overloaded assignment operator

Arguments: const Queue<T>& other: a passed in reference to a linked queue object

Returns: Queue<T>&: a reference to a linked queue object
******************************/
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
	if (this != &other)
		{
			clear();
			copyList(other);	//if the passed in linked queue is different than the current queue then call the clear method and then call the copyList() method to copy the values of the other linked que into the this linked queue
		}
	return *this;				//return the linked queue object with the new values
}
/******************************
Function: ostream& operator<<(ostream& lhs, const Queue<T>& rhs)

Use: Stand alone friend function of the queue class which overloads the << operator to print a linked queue object

Arguments: ostream& lhs: the output operator to allow for cascading cout statments
	   const Queue<T>& rhs: the passed by reference linked queue object to be printed

Returns: a output operator
******************************/
template <class T>
ostream& operator<<(ostream& lhs, const Queue<T>& rhs)
{
	Node<T>* ptr;
	for(ptr = rhs.qFront; ptr != nullptr; ptr = ptr->next)
		{
			lhs << ptr->data << " ";			//a loop to print out a linked queue object
		}
	return lhs;							//allows for a cascading output operator use
}
/******************************
Function: void Queue<T>::clear()

Use: clear method to remove the nodes from a linked queue array, making it an empty queue

Arguments: none

Returns: nothing
******************************/
template <class T>
void Queue<T>::clear()
{
	while(qSize != 0)
		{
			pop();		// while the queue is empty call the pop method to remove a node
		}
}
/******************************
Function: size_t Queue<T>::size()const

Use: returns the value that represents the size of the queue

Arguments: none

Returns: size_t: the size of the linked queue
******************************/
template <class T>
size_t Queue<T>::size()const
{
	return qSize;					//return the current size of the linked queue
}
/******************************
Function: bool Queue<T>::empty()const

Use: a method to determine whether or not a queue array is empty

Arguments: none

Returns: bool: true if the queue is empty and false if the queue has a node present
******************************/
template <class T>
bool Queue<T>::empty()const
{
	if(qSize == 0)
		{
			return true;
		}
	else						//if the qSize of the linked queue is 0 then return true otherwise return false
		{
			return false;
		}
}
/******************************
Function: const T& Queue<T>::front()const

Use: returns the front element of the linked queue if the qSize is not less than or equal to 0

Arguments: none

Returns: T&: the value stored in the front element of the linked queue
******************************/
template <class T>
const T& Queue<T>::front()const
{
	if(qSize <= 0)
		{
			throw underflow_error("Queue underflow on front()");
		}
	else									//if the qSize is less then or equal to 0 then throw an underflow_error exception
		{
			return qFront->data;					//otherwise return the value stored at the front of the linked queue
		}
}
/******************************
Function: const T& Queue<T>::back()const

Use: back() method which returns the value stored at the back of the linked queue if the queue size is greater than 0

Arguments: none

Returns: T&: the value stored in the back of the linked queue
******************************/
template <class T>
const T& Queue<T>::back()const
{
	if(qSize <= 0)
                {
                        throw underflow_error("Queue underflow on back()");			//if the qSize is less then or equal to 0 then throw an underflow_error exception
                }
        else
                {
                        return qBack->data;					//otherwise return the value stored at the back of the linked queue
                }
}
/******************************
Function: void Queue<T>::push(const T& newValue)

Use: push(const T& newValue): inserts a new node and stores the passed in value into the linked queue

Arguments: const T&: a new value to be stored in the next node of the linked queue

Returns: nothing
******************************/
template <class T>
void Queue<T>::push(const T& newValue)
{
	Node<T>* newNode = new Node<T>(newValue);		//create a new node with the value that is passed into the method
	if(qSize == 0)
		{
			qFront = newNode;			//if the qSize is equal to 0 then place the node at the front of the linked queue
		}
	else
		{
			qBack->next = newNode;			//otherwise place the new node as the next node pointed to of the linked queue
		}
	qBack = newNode;					//make the new node the back of the queue
	qSize++;						//increment size of linked queue
}
/******************************
Function:void Queue<T>::pop()

Use: method which removes the front node of the linked queue

Arguments: none

Returns: nothing
******************************/
template <class T>
void Queue<T>::pop()
{
	if(qSize <= 0)
		{
			throw underflow_error("Queue underflow on pop()");	//if the qSize is less then or equal to 0 then throw an underflow_error exception
		}
	Node<T>* delNode = qFront;
	qFront = qFront->next;					//create a node pointer to the front of the linked queue for temporary storage of the address 
	if(qFront == nullptr)					//assign the address of the next pointer from the front in the linked queue to the front of the linked queue 
		{
			qBack = nullptr;			//if the front is equal to nullptr then assign qBack to null pointer to indicate a empty linked queue
		}
	delete delNode;						//delete the temporary address value variable to deallocate the node
	qSize--;						//decrement the qSize
}
/******************************
Function: void Queue<T>::copyList(const Queue<T>& other)

Use: method which copies the values of the linked queue represented by other into the linked queue represented by this

Arguments: const Queue<T>& other: the linkede queue to be copied

Returns: nothing
******************************/
template <class T>
void Queue<T>::copyList(const Queue<T>& other)
{
	Node<T>* ptr;
	for(ptr = other.qFront; ptr != nullptr; ptr = ptr->next)		//a loop which calls the push methos to copy the contents of the other linked queue object into the this queue object
		{
			push(ptr->data);
		}
}
#endif										//end of header file
