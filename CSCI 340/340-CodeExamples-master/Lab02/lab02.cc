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

using std::list;
using std::cout;
using std::endl;

const int start=10;
const int stop=25;
const int low=0;
const int high=100;

int
randomNumber(int a, int b)
{
    return (rand() % (b - a + 1) + a);
}

int
main()
{
    list<int> l1, l2, l3, l4;

    srand(340);
    
    int listsize = randomNumber(start, stop);
    for(int i=0;i<listsize;++i)
        l1.push_back(randomNumber(low,high));

    listsize = randomNumber(start, stop);
    for(int i=0;i<listsize;++i)
        l2.push_back(randomNumber(low,high));

    l1.sort();
    l2.sort();
    
    /* Insert your code here YOU MAY NOT USE STL merge */
    auto itr1 = l1.begin();
    auto itr2 = l2.begin();
    
    int combinedsize = l1.size() + l2.size();
    
    for(int i = 0; i < combinedsize; i++)
    {
        if(itr1 == l1.end())
        {
            l3.push_back(*itr2);
            ++itr2;
        }// End of ELSE IF
        else if(itr2 == l2.end())
        {
            l3.push_back(*itr1);
            ++itr1;
        }// End of ELSE IF
        else if(*itr1 < *itr2){
            l3.push_back(*itr1);
            ++itr1;
        }// End of ELSE IF
        else
        {
            l3.push_back(*itr2);
            ++itr2;
        }// End of ELSE  
    }// End of FOR  

    cout << "l1: ";
    for(auto itr1 = l1.begin(); itr1 != l1.end(); ++itr1)
        std::cout << *itr1 << " ";
    cout << endl;

    cout << "l2: ";
    for(auto itr2 = l2.begin(); itr2 != l2.end(); ++itr2)
        std::cout << *itr2 << " ";
    cout << endl;
    
    cout << "l3: ";
    for(auto itr3 = l3.begin(); itr3 != l3.end(); ++itr3)
        std::cout << *itr3 << " ";
    cout << endl;

    l4.merge(l1);
    l4.merge(l2);
    cout << "l4: ";
    for(auto itr4 = l4.begin(); itr4 != l4.end(); ++itr4)
        std::cout << *itr4 << " ";
    cout << endl;


}
