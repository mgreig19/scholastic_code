#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::sort;
using std::cin;
using std::vector;

int
main()
{
	int input;
  	vector<int> inputVector;

  	// Get input from standard in
  	while (cin >> input) 				// <crtl d> ends
    	inputVector.push_back(input); 	// pushes new value on back of vector

  	vector<int>::iterator it; // creates an iterator it for vector<int> container

  	cout << endl << "Unsorted Vector: ";
  	for(it = inputVector.begin(); it != inputVector.end(); ++it)
    	cout << *it << " ";
  	cout << endl;
  
  	// STL sort
  	sort(inputVector.begin(), inputVector.end());

  	cout << "Sorted Vector: ";
  	for(it = inputVector.begin(); it != inputVector.end(); ++it)
    	cout << *it << " ";
  	cout << endl;
  
  	return 0;
}
