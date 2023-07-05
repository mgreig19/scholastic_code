using namespace std;

#include <iostream>
#include <iomanip>
#include <fstream>

#include <string>
#include <sstream>   // ostringstream

// Formatting output using ostringstream

main() 
  {
    int i = 3;
    ostringstream oss;
    string s("I am a variable");

    cout << endl;

    // reset before each use
    oss.clear();
    oss.str("");

    // format some constants and variables of different types
    oss << "I am a constant " << "\n"
	<< s                  << "\n"
        << 123456             << "\n"
        << 3.14159            << "\n"
        << i                  << "\n";

    // now print them all at once
    //    cout << oss.str().c_str();
    cout << oss.str() << endl;
  }
