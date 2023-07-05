// carg2.cpp

// shows how to receive command line arguments:
// note: C string library

#include <iostream>
#include <iomanip>

#include <string.h>
#include <string>

using namespace std;

int main( int argc, char *argv[])
{

  int i;
  string cppstr;

  cout << endl;
  cout << "I received " << argc << " argument(s)" << endl;

  for (i = 0; i < argc; i++)
    {
      cout << "Argument " << i << " is " << argv[i] 
	   << " and it has length " << strlen(argv[i]) << endl;
    }
  cout << endl; 

  cppstr = string(argv[0]);
  cout << "This program was called as " << cppstr << endl << endl;

  cout << "The value of the pointer is " << (void*)argv[0] << endl << endl;

  return 0; 
} 

/* Sample output:

./carg2.exe blob glubb

I received 3 argument(s)
Argument 0 is ./a.out and it has length 7
Argument 1 is blob and it has length 4
Argument 2 is glubb and it has length 5
The value of the pointer is 0xffbefd58

*/
