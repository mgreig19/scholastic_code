#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{

  char a[] = "hello";

  string str = a;

  cout << endl;
  cout << str << endl;
  cout << a        << endl;

  cout << a[0]     <<  endl;
  cout << *a       << endl;

  cout << (void*)a << endl << endl;

  return 0;
}
