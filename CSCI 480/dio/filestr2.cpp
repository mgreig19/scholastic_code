#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
 
using namespace std;

int main()
{

  //  Reading one line at a time into a C++ string
  // \n = LF = line feed is automatically deleted

 int line_count;
 string cppstr;

 ifstream myfile("files-many.txt");
 if (myfile.fail()) 
   {
     cout << "Fail bit set" << endl;
     return 1;
   }

 line_count = 0;
 cout << endl;

 while (true)
   {
     getline(myfile, cppstr);
     if (myfile.eof())
       {
	 cout << "Now it is end of file." << endl;
         break;
       }
    
     line_count++;
     cout << "we have read " << line_count << " "
          << (line_count == 1 ? "record.  " : "records. ")
	  << "It is not end of file yet." << endl;

     cout << "|" << cppstr << "|" 
          << " has length " << cppstr.length() << endl << endl;
   }

 cout << endl;
 myfile.close();

 return 0;

}
