// This code is adapted from "Data Structures and Algorithms in C++, 4th Edition"
// by Adam Drozdek
// Used for educational purposed related to CS340.
#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

const int X = 10;
const int ARRAY_SIZE = X*X;
const int HIGH = 1000;
const int LOW = 0;

template<class T>
void insertionsort(T data[], const int n) 
{
    for (int i = 1, j; i < n; i++) 
    {
        T tmp = data[i];
        for (j = i; j > 0 && tmp < data[j-1]; j--)
            data[j] = data[j-1];
        data[j] = tmp;
    }// End of FOR i < n
}// End of insertionsort

template<class T>
void selectionsort(T data[], const int n) 
{
    for (int i = 0, least, j; i < n-1; i++) 
    {
        for (j = i+1, least = i; j < n; j++)
            if (data[j] < data[least])
                least = j;
        swap(data[least],data[i]);
    }// End of FOR i < n-1
}// End of selectionsort

template <class T>
void bubblesort(T data[], const int n)
{
    for(int i = 0; i < n-1; i++)
    	for(int j = n-1; j > i; --j)
	if(data[j] < data[j-1])
		swap(data[j], data[j-1]);
}// End of bubblesort(data[], int n)

template<class T>
void quicksort(T data[], int first, int last) 
{
    int lower = first+1, upper = last;
    swap(data[first],data[(first+last)/2]);
    T bound = data[first];
    while (lower <= upper) 
    {
        while (data[lower] < bound)
             lower++;
        while (bound < data[upper])
             upper--;
        if (lower < upper)
             swap(data[lower++],data[upper--]);
        else lower++;
    }// End of WHILE (lower <= upper)
    swap(data[upper],data[first]);
    if (first < upper-1)
        quicksort (data,first,upper-1);
    if (upper+1 < last)
        quicksort (data,upper+1,last);
}// End of quicksort(T [], int, int)

template<class T>
void quicksort(T data[], const int n) {
    int i, max;
    if (n < 2)
        return;
    for (i = 1, max = 0; i < n; i++)// find the largest
        if (data[max] < data[i])    // element and put it
            max = i;                // at the end of data[];
    swap(data[n-1],data[max]); 		// largest el is now in its
    quicksort(data,0,n-2);     		// final position;
}// End of quicksort(T [], int)

void
insertion(int array[])
{
	for(int i = 0; i < ARRAY_SIZE; ++i)
		array[i] = rand()%(HIGH-LOW+1)+LOW;
                
  	cout << "Unsorted Array" << endl;
    for(int i = 0; i < X; ++i)
    {
    	for(int j = 0; j < X; ++j)
    		cout << setw(3) << array[i*X+j] << " ";
    	cout << endl;
    }// End of FOR

    insertionsort(array,ARRAY_SIZE);

    cout << "Insertion Sorted Array" << endl;
    for(int i = 0; i < X; ++i)
    {
    	for(int j = 0; j < X; ++j)
    		cout << setw(3) << array[i*X+j] << " ";
    	cout << endl;
    }// End of FOR
    cout << endl;
}// End of insertion(int [])

void
selection(int array[])
{
	for(int i = 0; i < ARRAY_SIZE; ++i)
		array[i] = rand()%(HIGH-LOW+1)+LOW;
                
  	cout << "Unsorted Array" << endl;
    for(int i = 0; i < X; ++i)
    {
    	for(int j = 0; j < X; ++j)
    		cout << setw(3) << array[i*X+j] << " ";
    	cout << endl;
    }// End of FOR

    selectionsort(array,ARRAY_SIZE);

    cout << "Selection Sorted Array" << endl;
    for(int i = 0; i < X; ++i)
    {
    	for(int j = 0; j < X; ++j)
    		cout << setw(3) << array[i*X+j] << " ";
    	cout << endl;
    }// End of FOR
    cout << endl;
}// End of selection(int [])

void
bubble(int array[])
{
	for(int i = 0; i < ARRAY_SIZE; ++i)
		array[i] = rand()%(HIGH-LOW+1)+LOW;
                
  	cout << endl << "Unsorted Array" << endl;
    for(int i = 0; i < X; ++i)
    {
    	for(int j = 0; j < X; ++j)
    		cout << setw(3) << array[i*X+j] << " ";
    	cout << endl;
    }// End of FOR

    bubblesort(array,ARRAY_SIZE);

    cout << "Bubble Sorted Array" << endl;
    for(int i = 0; i < X; ++i)
    {
    	for(int j = 0; j < X; ++j)
    		cout << setw(3) << array[i*X+j] << " ";
    	cout << endl;
    }// End of FOR
    cout << endl;
}// End of bubble(int [])

void
quick(int array[])
{
	for(int i = 0; i < ARRAY_SIZE; ++i)
		array[i] = rand()%(HIGH-LOW+1)+LOW;
                
  	cout << endl << "Unsorted Array" << endl;
    for(int i = 0; i < X; ++i)
    {
    	for(int j = 0; j < X; ++j)
    		cout << setw(3) << array[i*X+j] << " ";
    	cout << endl;
    }// End of FOR

	quicksort(array, ARRAY_SIZE);

	cout << "Quick Sorted Array" << endl;
    for(int i = 0; i < X; ++i)
    {
    	for(int j = 0; j < X; ++j)
    		cout << setw(3) << array[i*X+j] << " ";
    	cout << endl;
    }// End of FOR
    cout << endl;
}// End of quick(int [])

int
main()
{
	int myarray[ARRAY_SIZE];

	insertion(myarray);

	selection(myarray);

	bubble(myarray);

	quick(myarray);

  	return 0;
}