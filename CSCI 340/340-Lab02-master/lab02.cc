/////////
//
//  Lab02 (lists)
//
//  1) create 2 lists of integers, l1 and l2
//  2) fill each list with a random number of integers (10 - 25 entries) with random numbers from 0 to 100
//  3) sort each list using STL sort function
//  4) merge the two lists into a third list l3, you may not use any STL algorithms
//  5) merge l1 and l2 using STL merge into l4
//  6) print out all four lists

#include <iostream>
#include <list>

const int start=10;
const int stop=25;
const int low=0;
const int high=100;

int
randomNumber(int a, int b)
{
    return (rand() % (b - a + 1) + a); // Return a random number between a and b
}// End of randNumber(int, int)

int
main()
{
  std::list<int> l1, l2, l3, l4;
  srand(340);
    

    
    
    return 0;
}
