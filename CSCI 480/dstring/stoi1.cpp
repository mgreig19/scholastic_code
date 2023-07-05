#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{

  string str1 = "123";
  string str2 = "   4";

  int i;
  int j;
  
  cout << endl;
  
  i = stoi(str1);
  j = stoi(str2);
  
  cout << "|" << str1 << "| = "<< i << endl << endl;
  cout << "|" << str2 << "| = "<< j << endl << endl;

  return 0;
}
