using namespace std;

#include <iostream>
#include <iomanip>
#include <fstream>

#include <string>
#include <cstdlib>   // C standard library w/ C++ wrapper

// Formatting output using ostringstream

main() 
  {
    string s("123456");
    string t("134");
    int i;
    int j;

    cout << endl;
    cout << "The strings are  " << s << " and " << t << endl;

    i = atoi(s.c_str());
    j = atoi(t.c_str());
    cout << "The integers are " << i << " and " << j << endl;

    if (s > t)
        cout << "s > t" << endl;
      else
        cout << "s <= t" << endl;

    if (i > j)
        cout << "i > j" << endl;
      else
        cout << "i <= j" << endl;

  }
