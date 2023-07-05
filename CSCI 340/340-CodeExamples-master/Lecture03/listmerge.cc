#include <iostream>
#include <list>
#include <algorithm>            // std::sort

using std::cout;
using std::endl;

const int LOW = 0;
const int HIGH = 100;
const int LIST_SIZE = 25;
const int MERGE_LIST_SIZE = 2*LIST_SIZE;

int main(int argc, const char * argv[]) {
    
    srand(49);
    
    // Create 4 lists
    std::list<int> list1;
    std::list<int> list2;
    std::list<int> list3;
    std::list<int> list4;
    
    // Filling list1 and list2 with random numbers between LOW and HIGH
    for(int i = 0;i<LIST_SIZE;++i)
        list1.push_back(rand() % (HIGH-LOW + 1) + LOW);
    
    for(int i = 0;i<LIST_SIZE;++i)
        list2.push_back(rand() % (HIGH-LOW + 1) + LOW);
    
    cout << "Unsorted Lists" << endl;
    cout << "List 1: ";
    for(auto itr = list1.begin();itr != list1.end(); ++itr)
        cout << *itr << " ";
    cout << endl;
    
    cout << "List 2: ";
    for(auto itr = list2.begin();itr != list2.end(); ++itr)
        cout << *itr << " ";
    cout << endl;
    
    // Sorting list1 and list2
    list1.sort();
    list2.sort();
    
    cout << "Sorted Lists" << endl;
    cout << "List 1: ";
    for(auto itr = list1.begin();itr != list1.end(); ++itr)
        cout << *itr << " ";
    cout << endl;
    
    cout << "List 2: ";
    for(auto itr = list2.begin();itr != list2.end(); ++itr)
        cout << *itr << " ";
    cout << endl;

    std::list<int>::iterator itrList1 = list1.begin();
    std::list<int>::iterator itrList2 = list2.begin();
    
    /// Merge of list1 and list2 into list3
    for(int i = 0;i<MERGE_LIST_SIZE;++i)
    {
        if(itrList1 == list1.end()){
            list3.push_back(*itrList2);
            ++itrList2;
        }// End of IF
        else if(itrList2 == list2.end())
        {
            list3.push_back(*itrList1);
            ++itrList1;
        }// End of ELSE IF
        else if(*itrList1 <= *itrList2)
        {
            list3.push_back(*itrList1);
            ++itrList1;
        }// End of IF
        else
        {
            list3.push_back(*itrList2);
            ++itrList2;
        }// End of ELSE
    }// End of FOR
    
    cout << "Merged Lists" << endl;
    cout << "List 3: ";
    for(auto itr = list3.begin();itr != list3.end(); ++itr)
        cout << *itr << " ";
    cout << endl;
    
    // Merge of two lists into one using STL list.merge
    list4.merge(list1);
    list4.merge(list2);
    
    cout << "Merged Lists using STL Merge" << endl;
    cout << "List 4: ";
    for(auto itr = list4.begin();itr != list4.end(); ++itr)
        cout << *itr << " ";
    cout << endl;
        
    return 0;
}
