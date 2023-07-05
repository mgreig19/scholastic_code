// based on example from www.cplusplus.com/reference/algorithm/sort/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool myfunction (int i,int j)
  { 
    return (i < j);
  }

class myclass
  {
    public:
      bool operator() (int i, int j) { return (i > j);}
  };

int main ()
  {
    int myints[] = {32, 71, 12, 45, 26, 80, 53, 33};

    vector<int> myvector (myints, myints+8);         // 32 71 12 45 26 80 53 33
    vector<int>::iterator it;

    myclass myobject;

    // using default comparison (operator <):
    sort (myvector.begin(), myvector.begin()+4);     //(12 32 45 71) 26 80 53 33

    // using function for comparison
    sort (myvector.begin()+4, myvector.end(), myfunction);
                                                     // 12 32 45 71 (26 33 53 80)
    // print content
    cout << "myvector contains:";
    for (it = myvector.begin(); it != myvector.end(); ++it)
      cout << " " << *it;
    cout << endl;

    // using object for comparison
    sort (myvector.begin(), myvector.end(), myobject);

    // print output
    cout << "myvector contains:";
    for (it = myvector.begin(); it != myvector.end(); ++it)
      cout << " " << *it;
    cout << endl;

    return 0;
  }
