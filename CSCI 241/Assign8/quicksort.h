/******************************************
Program: Assignment8: quick sort algorithm

Author: Mason Greig

ZID: z1768935

Due date: 11/17/16

Purpose: contains the definitions of the friend functions and class methods that$
******************************************/
#ifndef QUICKSORT_H										//beginning of the header file definition
#define QUICKSORT_H

using namespace std;

template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&));

template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));	//method prototypes

template<class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));

/******************************
Function: void quickSort(vector<T>& set, 
bool (*compare)(const T& lhs, const T& rhs))


Use: calls the recursive quick sort algorithm

Arguments: vector<T>&: a reference to a vector object of data type T
           bool (*compare)(const T&, const T&)): a pointer to a function which compares two vector objects of data type T

Returns: nothing
******************************/
template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T& lhs, const T& rhs))
{
	quickSort(set, 0, set.size() - 1, compare);				//calls the recursive quick sort algorithm
}
/******************************
Function: void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))

Use: sorts the values of a vector object

Arguments: vector<T>&: a reference to a vector object of data type T
           bool (*compare)(const T&, const T&)): a pointer to a function which compares two vector objects of data type T
	   int start: the start of the vector object
	   int end: the end of the vector object

Returns: nothing
******************************/
template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
	int pivotPoint;
	if(start < end)
		{
			pivotPoint = partition(set, start, end, compare);		//set the pivot point for the quick sort algorithn
			quickSort(set, start, pivotPoint - 1, compare);			//call the quick sort algorithm for each side of the partitioned vector object
			quickSort(set, pivotPoint + 1, end, compare);
		}
}
/******************************
Function: int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))

Use: splits the vector object into two smaller vector objects

Arguments: vector<T>&: a reference to a vector object of data type T
           bool (*compare)(const T&, const T&)): a pointer to a function which compares two vector objects of data type T
           int start: the start of the vector object
           int end: the end of the vector object

Returns: int: whether or not the partition was succesful
******************************/
template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
	int pivotIndex, mid;							//declare local variables
	T pivotValue;
	mid = (start + end) / 2;						//set the mid to the middle of the vector object

	swap(set[start], set[mid]);						//swap the elements at the start and being of the vector object

	pivotIndex = start;
	pivotValue = set[start];						//set the pivot point to the start of the vector object and set the value stored in the start of the vector

	for(int scan = start + 1; scan <= end; scan++)				//for as long as the scan through the vector object does not reach the end of the object
		{
			if(compare(set[scan], pivotValue))
				{
					pivotIndex++;				//increment pivot index
					swap(set[pivotIndex], set[scan]);	//swap the values stored at pivotIndex and scan of the vector object
				}
		}
	swap(set[start], set[pivotIndex]);					//swap the values stored at pivotIndex and start of the vector object

	return pivotIndex;							//return the pivotindex value
}
#endif										//end of the header file definition 
