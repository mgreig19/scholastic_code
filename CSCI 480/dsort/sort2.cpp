

// based on example from www.cplusplus.com/reference/algorithm/sort/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool myfunction (int i,int j);

// lexicographic sort

class myclass
  {
    public:
      bool operator() (int i, int j);
  };

int main ()
  {
    int myints[] = {1, 2, 3, 4, 10, 20, 30, 40};

    vector<int> myvector (myints, myints+8);
    vector<int>::iterator it;

    myclass myobject;

    // using function for comparison
    sort (myvector.begin(), myvector.end(), myfunction);

    // print out content
    cout << "myvector contains:";
    for (it = myvector.begin(); it != myvector.end(); ++it)
      cout << " " << *it;
    cout << endl;

    // using object for comparison
    sort (myvector.begin(), myvector.end(), myobject);

    // print out content
    cout << "myvector contains:";
    for (it = myvector.begin(); it != myvector.end(); ++it)
      cout << " " << *it;
    cout << endl;

    return 0;
  }

bool myfunction (int i, int j)
  { 
    stringstream ssi, ssj;
    string si, sj;
    bool result;

    ssi << i;
    ssj << j;

    si = ssi.str();
    sj = ssj.str();

    //  cout << "." << si << "." << sj << "." << endl;

    result = (si < sj);

    return result;
  }

bool myclass::operator() (int i, int j)
  { 
    stringstream ssi, ssj;
    string si, sj;
    bool result;

    ssi << i;
    ssj << j;

    si = ssi.str();
    sj = ssj.str();

    //  cout << "." << si << "." << sj << "." << endl;

    result = (si > sj);

    return result;
  }

