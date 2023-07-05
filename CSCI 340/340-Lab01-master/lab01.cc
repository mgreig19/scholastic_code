#include<iostream>
#include<vector>

using std::cout;
using std::vector;
using std::endl;

/*************************************************************************************************************************
 Purpose: Gain experience with STL vectors ....
 
 Task: Complete the following steps.
 
 1) add 10 natural numbers which are multiples of 10 eg: 10,20,....100.
 2) Print the vector.
 3) add 5 to each elements of the vector.
 4) print vector again in reverse order using a reverse iterator
 5) modify vector again by adding a random number between 0 and 99 to each element
 6) print vector again
 7) sort the vector using mySortFunction
 8) print the vector again adding ""(" << *i%8 << ")"" to show how items are sorted
 ***************************************************************************************************************************/

bool mySortFunction(int i,int j) {return ((i%8) > (j%8));}

int main()
{
    vector<int> myvector;
    
    // (1) add 10 natural numbers which are multiples of 10 eg: 10,20,....100
    
    // (2) display the vector
    
    // (3) Add number 5 to all the elements
    
    // (4) display the vector using reverse iterator
    
    // (5) Add random number between 0 and 99 to all elements (you will need rand() % 100)
    
    // (6) display the vector
    
    // (7) sort the array based on mySortFunction
    
    // (8) display vector again, change cout to include parens with mod used [looks something like  ""(" << *i%8 << ")""] to show how items are sorted
    
    return 0;
}
