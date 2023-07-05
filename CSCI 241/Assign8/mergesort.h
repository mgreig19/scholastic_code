/******************************************
Program: Assignment8: Merge sort algorithm

Author: Mason Greig

ZID: z1768935

Due date: 11/17/16

Purpose: contains the method definitions and prototypes needed for the merge sort algorithym
******************************************/
#ifndef MERGESORT_H												//start the header file definition
#define MERGESORT_H

template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&));

template <class T>
void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&));		//merge sort prototypes

template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&));

/******************************
Function: void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))

Use: calls the recursive merge sort algorithm

Arguments: vector<T>&: a reference to a vector object of data type T
	   bool (*compare)(const T&, const T&)): a pointer to a function which compares two vector objects of data type T

Returns: nothing
******************************/
template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
	mergeSort(set, 0, set.size() - 1, compare);				//calls the recursive mergesort
}
/******************************
Function: void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))

Use: calls the recursive merge sort algorithm

Arguments: vector<T>&: a reference to a vector object of data type T
	   int low:  used to keep track of the low value in a vector object
	   int high: used to keep track of the high value in a vector object
           bool (*compare)(const T&, const T&)): a pointer to a function which compares two vector objects of data type T

Returns: nothing
******************************/
template <class T>
void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&))
{
	int mid;
	if (low < high)
		{
			mid = (low + high) / 2;					//sets mid to the center of the vecotr object
			mergeSort(set, low, mid, compare);
			mergeSort(set, mid + 1, high, compare);			//splits the vector into two seperate vector objects for sorting
			merge(set, low, mid, high, compare);			//merges the two vector object back into a single vector object
		}
}
/******************************
Function: void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&))

Use:sorts the vector object of T data type 

Arguments: vector<T>&: a reference to a vector object of data type T
           int low:  used to keep track of the low value in a vector object
           int high: used to keep track of the high value in a vector object
           bool (*compare)(const T&, const T&)): a pointer to a function which compares two vector objects of data type T
	   int mid: the middle position of the vector object

Returns: nothing
******************************/
template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&))
{
	vector<T> temp(high - low + 1);				//creates a temporary vector object
	int i = low;
	int j = mid + 1;					//variables to track the sort as it cycles through each value of the vector object
	int k = 0;

	while ( i <= mid and j <= high)				//while the low value is less than or equal to the middle value and while the value 1 place above the middle is less then or equal to the high value
		{
			if (compare(set[j], set[i]))		//compare the two values located at the current count of j and i
				{
					temp[k] = set[j];	//if it returns true then assign the value stored at j in the vector should be copied to the same space as it was in j
					j++;
					k++;			//increment counts
				}
			else
				{
					temp[k] = set[i];
					i++;			//if the decision above returns false then store the value located in the current count of i to the same position in the temp vector object
					k++;			//increment count
				}
		}
	while (i <= mid)					//while the count value of i is less than or equal to the mid value
		{
			temp[k] = set[i];			//place the value stored in i of set into k of the temp vector object
			i++;
			k++;					//increment count
		}
	while (j <= high)					//while the count value of j is less than or equal to high value
		{
			temp[k] = set[j];			//place the value stired in j of set into k of the temp vector object
			j++;
			k++;					//increment count
		}
	for(i = 0, j = low; j <= high; i++, j++)
		{
			set[j] = temp[i];			//copy the newly sorted vector object back into the original set object
		}
}
#endif								//end of header file definition
