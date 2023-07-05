#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>

using std::list;
using std::cout;
using std::endl;

int
main()
{
    list<int> L1 {0, 2, 3, 5};
    list<int> L2 {1, 4, 6, 10};
    list<int> L3;
    
    std::cout << "L1: ";
    for(auto itr1 = L1.begin(); itr1 != L1.end(); ++itr1)
        std::cout << *itr1 << " ";
    std::cout << std::endl;
    std::cout << "L2: ";
    for(auto itr2 = L2.begin(); itr2 != L2.end(); ++itr2)
        std::cout << *itr2 << " ";
    std::cout << std::endl;

    /* Insert your code here YOU MAY NOT USE STL merge */
    auto itr1 = L1.begin();
    auto itr2 = L2.begin();
    
    int combinedsize = L1.size() + L2.size();
    
    for(int i = 0; i < combinedsize; i++)
    {
        if(itr1 == L1.end())
        {
            L3.push_back(*itr2);
            ++itr2;
        }// End of ELSE IF
        else if(itr2 == L2.end())
        {
            L3.push_back(*itr1);
            ++itr1;
        }// End of ELSE IF
        else if(*itr1 < *itr2){
            L3.push_back(*itr1);
            ++itr1;
        }// End of ELSE IF
        else
        {
            L3.push_back(*itr2);
            ++itr2;
        }// End of ELSE  
    }// End of FOR  
	 
    for(auto itr3 = L3.begin(); itr3 != L3.end(); ++itr3)
        std::cout << *itr3 << " ";
    
    std::cout << std::endl;
}