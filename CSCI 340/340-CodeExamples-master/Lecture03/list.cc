#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using std::cout;
using std::endl;
using std::string;
using std::list;
using std::ostream_iterator;

void printLists (string ln1, const list<int>& l1, string ln2, const list<int>& l2)
{
    cout << ln1 << ": ";
    copy (l1.begin(), l1.end(), ostream_iterator<int>(cout," "));
    cout << endl << ln2 << ": ";
    copy (l2.begin(), l2.end(), ostream_iterator<int>(cout," "));
    cout << endl;
}

int main()
{
    // create two empty lists
    list<int> list1, list2;

    // fill both lists with elements
    for (int i=0; i<6; ++i) {
        list1.push_back(i);                         // Add at back of list
        list2.push_front(i);                        // Add at front of list
    }

    list<int> olist1 = list1;                       // Copy original list1
    list<int> olist2 = list2;                       // Copy original list2

    cout << "original lists" << endl;
    printLists("list1", list1, "list2", list2);
    cout << "_______________________________" << endl << endl;
    
    // insert all elements of list1 before the first element with value 3 of list2
    
    // - find() returns an iterator to the first element with value 3
    //template <class InputIterator, class T>
    //   InputIterator find (InputIterator first, InputIterator last, const T& val);
    
    // void splice (iterator position, list& x); <- transfers all the elements of x into the container
    list2.splice(find(list2.begin(),list2.end(), 3), list1);  
    
    cout << "first splice" << endl;                                                    
    printLists("list1", list1, "list2", list2);
    printLists("original list1", olist1, "current list1", list1);
    printLists("original list2", olist2, "current list2", list2);
    cout << "_______________________________" << endl << endl;

    // void splice (iterator position, list& x, iterator i);
    // transfers only the element pointed by i from x into the container
    // move first element to the end
    
    list2.splice(list2.end(),        // destination position
                 list2,              // source list
                 list2.begin());     // source position
    
    cout << "second splice" << endl;                                                    
    printLists("list1", list1, "list2", list2);
    cout << "_______________________________" << endl << endl;

    list2.splice(list2.end(),        // destination position
                 list2,              // source list
                 list2.begin());     // source position
    
    cout << "third splice" << endl;                                                    
    printLists("list1", list1, "list2", list2);
    cout << "_______________________________" << endl << endl;

    list1 = list2;
    // sort second list
    list2.sort();
    cout << "sort" << endl;                                                    
    printLists("list1", list1, "list2", list2);
    cout << "_______________________________" << endl << endl;

    list1.unique();
    list2.unique();
    cout << "unique" << endl;                                                    
    printLists("list1", list1, "list2", list2);
    cout << "_______________________________" << endl << endl;

    list2.insert(list2.begin(),0);
    list2.insert(list2.begin(),0);
    list2.insert(list2.begin(),0);
    list2.insert(list2.begin(),0);
    cout << "inserted 4 extra 0 into list2" << endl;                                                    
    printLists("list1", list1, "list2", list2);
    cout << "_______________________________" << endl << endl;
    
    list1.unique();
    list2.unique();
    cout << "unique" << endl;                                                    
    printLists("list1", list1, "list2", list2);
    cout << "_______________________________" << endl << endl;

    // merge both sorted lists into the first list
    olist1.merge(olist2);
    cout << "merge" << endl; 
    printLists("original list1", olist1, "original list2", olist2);
    cout << "_______________________________" << endl << endl;
}
