#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
 
using namespace std;

int main()
{

string filedata;

ifstream newfile("file-empty.txt");
if (newfile.eof()) 
  cout << "File is empty" << endl;
newfile.close();
newfile.clear();

ifstream myfile("filesin.txt");
cout << "Just opened file" << endl;
if (myfile.good()) cout << "Good bit set" << endl;
if (myfile.bad()) cout << "Bad bit set" << endl;
if (myfile.fail()) cout << "Fail bit set" << endl;
if (myfile.eof()) cout << "Eof bit set" << endl;
cout << endl;

myfile >> filedata;
cout << "Just read an item" << endl;
if (myfile.good()) cout << "Good bit set" << endl;
if (myfile.bad()) cout << "Bad bit set" << endl;
if (myfile.fail()) cout << "Fail bit set" << endl;
if (myfile.eof()) cout << "Eof bit set" << endl;
cout << endl;

myfile >> filedata;
cout << "Trying to read another item" << endl;
if (myfile.good()) cout << "Good bit set" << endl;
if (myfile.bad()) cout << "Bad bit set" << endl;
if (myfile.fail()) cout << "Fail bit set" << endl;
if (myfile.eof()) cout << "Eof bit set" << endl;
cout << endl;

myfile.close();
myfile.clear();

// This file doesn't exist

myfile.open("filesin3.txt");
cout << "Trying to open non-existent file" << endl;
if (myfile.good()) cout << "Good bit set" << endl;
if (myfile.bad()) cout << "Bad bit set" << endl;
if (myfile.fail()) cout << "Fail bit set" << endl;
if (myfile.eof()) cout << "Eof bit set" << endl;
cout << endl;

myfile >> filedata;
cout << "Trying to read from it" << endl;
if (myfile.good()) cout << "Good bit set" << endl;
if (myfile.bad()) cout << "Bad bit set" << endl;
if (myfile.fail()) cout << "Fail bit set" << endl;
if (myfile.eof()) cout << "Eof bit set" << endl;
cout << endl;

myfile.close();
cout << "Trying to close it" << endl;
if (myfile.good()) cout << "Good bit set" << endl;
if (myfile.bad()) cout << "Bad bit set" << endl;
if (myfile.fail()) cout << "Fail bit set" << endl;
if (myfile.eof()) cout << "Eof bit set" << endl;

return 0;

}
