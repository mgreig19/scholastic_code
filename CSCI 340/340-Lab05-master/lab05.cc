//	lab05.cc [not a required assignment but material may be found on exam]
//
// For each of the sort algorithms discussed in class, modify (http://tinyurl.com/m9xglwb)
// or write a new version that prints out the vector after each pass through the algorithms 
// loop.  Copy the vector provided at the beginning of the main routine below so you have the 
// same vector as input for each routine.
//
// Here is a the first five lines from bubble sort:
// 97 42 74 58 26 63 74 58 69 36 
//
// 97 42 74 58 26 63 74 58 36 69 
// 97 42 74 58 26 63 74 36 58 69 
// 97 42 74 58 26 63 36 74 58 69 
// 97 42 74 58 26 36 63 74 58 69 
// 97 42 74 58 26 36 63 74 58 69 
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <time.h>

const int VECTOR_LENGTH = 10;
const int HIGH = 99;
const int LOW = 0;

using namespace std;

int
main()
{
	srand(time(NULL));
	vector<int> a(VECTOR_LENGTH);

	for(int i=0;i<VECTOR_LENGTH;++i)
		a[i] = (rand() % (HIGH - LOW + 1) + LOW);

	cout << "Unsorted Vector of length " << VECTOR_LENGTH << ":" << endl;
	for(int i=0;i<VECTOR_LENGTH;++i)
		cout << setfill('0') << setw(2) << a[i] << " ";
	cout << endl;
	cout << endl;


	cout << "Insertion Sort: " << endl;

	cout << "Selection Sort: " << endl;

	cout << "Bubble Sort: " << endl;

	cout << "Quick Sort: " << endl;

	
}
