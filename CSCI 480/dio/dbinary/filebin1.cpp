#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
 
using namespace std;

int main()
{

  // Reading ascii file w/ binary I/O

 char str[80];
 int char_count;
 int eol_count;
 char ch;

 ifstream myfile;
 myfile.open("files-many.txt", ios::in | ios::binary);

 if (myfile.fail()) 
   {
     cout << "Can't open" << endl;
     exit(1);
   }

 myfile.read(str, 33);
 if (myfile.fail()) 
   {
     cout << "Can't do first read" << endl;
     exit(1);
   }
 else
     cout << str << "..." << endl;

 myfile.read(str, 99);
 if (myfile.fail()) 
   {
     cout << "Can't do second read" << endl;
     exit(1);
   }
 else
     cout << str << "..." << endl;

 myfile.close();
 myfile.clear();

 return 0;

}
