#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
 
using namespace std;

int main()
{

 long int i = 1;

 ofstream myfile;
 myfile.open("file-end.txt", ios::binary);

 if (myfile.fail()) 
   {
     cout << "Can't open" << endl;
     exit(1);
   }

 myfile.write((char *)&i, 4);

 if (myfile.fail()) 
   {
     cout << "Couldn't write" << endl;
     exit(1);
   }

 myfile.close();
 myfile.clear();

 return 0;

}
