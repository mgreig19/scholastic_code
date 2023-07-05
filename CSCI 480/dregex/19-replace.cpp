
// STL Functions replace, replace_if, replace_copy, and
//   replace_copy_if

// Based on Malek ch. 19


#include <iostream>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

bool lessThanEqualTo50(int num);

int main()
  {
    char cList[10] = {'A', 'a', 'A', 'B', 'A', 'c', 'D', 'e', 'F', 'A'};

    vector<char>  charList(cList, cList + 10);

    ostream_iterator<char> screen(cout, " ");

    cout << endl;

    cout << "Line 4:  Character list: " << endl 
         << "         ";                              // Line 4
    copy(charList.begin(), charList.end(), screen);
    cout << endl << endl;

    // replace

    replace(charList.begin(), charList.end(), 'A', 'Z');

    cout << "Line 8:  Character list after replacing A with Z: "
         << endl << "         ";                      // Line 8
    copy(charList.begin(), charList.end(), screen);
    cout << endl << endl;

    // replace_if

    replace_if(charList.begin(), charList.end(), (int (*)(int)) isupper, '*');
    cout << "Line 12: Character list after  replacing uppercase  " << endl
         << "         letters with *: " << endl
         << "         ";                              // Line 12

    copy(charList.begin(), charList.end(), screen);
    cout << endl << endl;

    int list[10] = {12, 34, 56, 21, 34, 78, 34, 55, 12, 25};

    vector<int>  intList(list, list + 10);

    ostream_iterator<int> screenOut(cout, " ");

    cout << "Line 18: intList: " << endl
         << "         ";                              // Line 18
    copy(intList.begin(), intList.end(), screenOut);
    cout << endl << endl;

    // replace_copy

    vector<int> temp1(10);

    replace_copy(intList.begin(), intList.end(), temp1.begin(), 34, 10);
    
    cout << "Line 23: temp1 list after copying intList and " << endl
         << "         replacing 34 with 10: " << endl
         << "         ";                              // Line 23
    copy(temp1.begin(), temp1.end(), screenOut);
    cout << endl << endl;

    // replace_copy_if

    vector<int> temp2(10);

    replace_copy_if(intList.begin(), intList.end(),
              temp2.begin(), lessThanEqualTo50, 50);

    cout << "Line 28: temp2 after copying intList and replacing " << endl
         << "         numbers less than 50 with 50:" << endl   
         << "         ";                              // Line 28

    copy(temp2.begin(), temp2.end(), screenOut);
    cout << endl << endl;

    return 0;
  }

bool lessThanEqualTo50(int num)
  {
    return (num <= 50);
  }
