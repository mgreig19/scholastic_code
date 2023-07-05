using namespace std;

#include <iostream>
#include <iomanip>
#include <fstream>

#include <string>
#include <sstream>   // istringstream

// Tokenization using istringstream

main() 
  {
    int i;
    istringstream iss;
    string cppstr;
    string tokenlist[10];
    string newtoken;

    ifstream myfile("files-many.txt");

    while (true)
      {
       getline(myfile, cppstr);
       if (!myfile)
         {
           cout << "end of file" << endl;
           break;
         }

       cout << endl << "|" << cppstr << "|"
            << " has " << cppstr.length() << " characters" << endl;

       // check for empty line
       if (cppstr.length() == 0) 
         {
	   cout << "empty line" << endl;
           continue;
         }

       // not empty, so move into iss object
       iss.clear();
       iss.str(cppstr);

       // read from iss object and break into tokens

       i = 0;
       while (iss >> newtoken)
         {
           i++;
           cout << i << ". |" << newtoken << "|" << endl;
	 }

      } // end of outer loop

    return(0);
  }
