using namespace std;

#include <iostream>
#include <iomanip>
#include <fstream>

#include <string>
#include <sstream>   // ostringstream

// Formatting output using ostringstream
// Modifiers work the same way w/ cout
// See http://www.cs.niu.edu/~freedman/241/ for more on modifiers

main() 
  {
    int i = 3;

    // some approximations
    float pi = 3.14159;
    float e  = 2.718281828;

    ostringstream oss;
    string s("variable");

    cout << endl;

    // reset before each use
    oss.clear();
    oss.str("");

    // setw is not sticky
    // other modifiers are
    oss << setw(20) << left  << "constant " << "\n"
	<< setw(20) << right << s           << "\n"
	<< s                                << "\n"
        << setw(10) << s                    << "\n";

    cout << oss.str() << endl;

    // reset
    oss.clear();
    oss.str("");

    oss << fixed << setprecision(3)
        << setw(10) << pi << " " << setw(10) << e << "\n";
    cout << oss.str() << endl;

    cout << setw(10) << 100+pi << " " << setw(10) << 100+e << endl << endl;


  }
