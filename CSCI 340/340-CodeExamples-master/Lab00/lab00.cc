#include <algorithm>
#include<iostream>
#include<vector>

using std::cout;
using std::vector;
using std::endl;

/***********************************************************************************************************
 Purpose: This program initialises a vector of integers,
 1) add 10 natural numbers which are multiples of 10 eg: 10,20,....100.
 2) Print the vector.
 3) add 5 to each elements of the vector.
 4) print vector again in reverse order using a reverse iterator
 5) modify vector again by adding a random number between 0 and 99 to each element
 6) print vector again
 7) sort the vector using mySortFunction
 8) print the vector again adding ""(" << *i%8 << ")"" to show how items are sorted
 
 Task: Complete the code.
***********************************************************************************************************/

bool mySortFunction(int i,int j) {return ((i%10) > (j%10));}

int main()
{
	vector<int> myvector;
	// add 10 natural numbers which are multiples of 10 eg: 10,20,....100
    
    for(int i=0;i<10;i++)
        myvector.push_back(10+i*10);
    
	// display the vector
    cout << "Original Vector: ";
    vector<int>::iterator i;
	for (i = myvector.begin(); i != myvector.end(); i++)
		cout << *i << " ";
	cout << endl;
	
	//Add number 5 to all the elements
	for (i = myvector.begin(); i != myvector.end(); i++)
        *i += 5;
    
    // display the vector
    cout << "Modified and Reversed Vector: ";
    for (auto ri = myvector.rbegin(); ri != myvector.rend(); ri++)
        cout << *ri << " ";
    cout << endl;
    
	// Add random number between 0 and 99 to all elements
    for (i = myvector.begin(); i != myvector.end(); i++)
        *i += rand() % 100;             // add random number between 0 and 99
    
    // display the vector
    cout << "Modified with Random Vector: ";
    for (i = myvector.begin(); i != myvector.end(); i++)
        cout << *i << " ";
    cout << endl;
    
    // sort the array based on mySortFunction
    sort(myvector.begin(), myvector.end(), mySortFunction);
    
    // display vector
    cout << "Sorted by mySortFunction with mod: " << endl;
    for (i = myvector.begin(); i != myvector.end(); i++)
        cout << *i << "(" << *i%8 << ") ";
    cout << endl;
		
	return 0;
}
