// copied and modified from http://www.cplusplus.com/reference/algorithm/equal_range/
// equal_range example
#include <iostream>     // std::cout
#include <algorithm>    // std::equal_range, std::sort
#include <vector>       // std::vector

using std::cout;
using std::endl;

const int inVector = 78;
const int notInVector = 6;

bool mygreater (int i,int j) { return (i>j); }

int main () {
	std::vector<int> v {1,34,23,78,56,12,9,7};                       
  
  	std::pair<std::vector<int>::iterator,std::vector<int>::iterator> bounds;

  	cout << "Unsorted vector: ";
  	for(auto itr=v.begin();itr != v.end(); ++itr)
  		cout << *itr << " ";
  	cout << endl;

  	bounds=std::equal_range (v.begin(), v.end(), notInVector);
   	if(std::distance(bounds.first,bounds.second) == 0)			// if not found the distance between first and second is zero
  		cout << notInVector << " Not found in vector: " << *bounds.first << " " << *bounds.second << endl;
  	else{
		cout << notInVector << " Found in vector with bounds returning: " << *bounds.first << ", " << *bounds.second;
		cout <<  " found at location " << std::distance(v.begin(), bounds.first) << endl;
	}// End of ELSE

  	bounds=std::equal_range (v.begin(), v.end(), inVector);
  	if(std::distance(bounds.first,bounds.second) == 0)			// if not found the distance between first and second is zero
  		cout << inVector << " Not found in vector: " << *bounds.first << " " << *bounds.second << endl;
  	else{
  		int i_would_like_to_return_int = std::distance(v.begin(), bounds.first);
		cout << inVector << " Found in vector with bounds returning: " << *bounds.first << ", " << *bounds.second;
		cout <<  " found at location " << i_would_like_to_return_int << endl;
	}// End of ELSE

  	// using default comparison:
  	std::sort (v.begin(), v.end());
  
  	cout << endl << "Sorted vector: ";
  	for(auto itr=v.begin();itr != v.end(); ++itr)
  		cout << *itr << " ";
  	cout << endl;

  	bounds=std::equal_range (v.begin(), v.end(), notInVector);
  	if(std::distance(bounds.first,bounds.second) == 0)			// if not found the distance between first and second is zero
  		cout << notInVector << " Not found in vector: " << *bounds.first << " " << *bounds.second << endl;
  	else{
		cout << notInVector << " Found in vector with bounds returning: " << *bounds.first << ", " << *bounds.second;
		cout <<  " found at location " << std::distance(v.begin(), bounds.first) << endl;
	}// End of ELSE

  	bounds=std::equal_range (v.begin(), v.end(), inVector);
  	if(std::distance(bounds.first,bounds.second) == 0)			// if not found the distance between first and second is zero
  		cout << inVector << " Not found in vector: " << *bounds.first << " " << *bounds.second << endl;
  	else{
		cout << inVector << " Found in vector with bounds returning: " << *bounds.first << ", " << *bounds.second;
		cout <<  " found at location " << std::distance(v.begin(), bounds.first) << endl;
	}// End of ELSE

  // using "mygreater" as comp:
  	std::sort (v.begin(), v.end(), mygreater);
  	cout << endl << "Sorted vector using the mygreater comparison: ";
  	for(auto itr=v.begin();itr != v.end(); ++itr)
  		cout << *itr << " ";
  	cout << endl;

  	bounds=std::equal_range (v.begin(), v.end(), notInVector, mygreater);
  	if(std::distance(bounds.first,bounds.second) == 0)			// if not found the distance between first and second is zero
  		cout << notInVector << " Not found in vector: " << *bounds.first << " " << *bounds.second << endl;
  	else{
		cout << notInVector << " Found in vector with bounds returning: " << *bounds.first << ", " << *bounds.second;
		cout <<  " found at location " << std::distance(v.begin(), bounds.first) << endl;
	}// End of ELSE


  	bounds=std::equal_range (v.begin(), v.end(), inVector, mygreater);
  	if(std::distance(bounds.first,bounds.second) == 0)			// if not found the distance between first and second is zero
  		cout << inVector << " Not found in vector: " << *bounds.first << " " << *bounds.second << endl;
  	else{
		cout << inVector << " Found in vector with bounds returning: " << *bounds.first << ", " << *bounds.second;
		cout <<  " found at location " << std::distance(v.begin(), bounds.first) << endl;
	}// End of ELSE


  return 0;
}
