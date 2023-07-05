#include <iostream>
#include <functional>

int add(int a, int b)
{
  return (a+b);
}

int sub(int a, int b)
{
  return (a-b);
}

int multi(int a, int b)
{
  return (a*b);
}

using namespace std;

int print(int a, int b, function<int(int, int)>p)
{
  cout << "Calling a function with " <<  a << " " << b << " result " << (p)(a,b) << endl;
  return 0;
}

int main()
{
  print(4,5,add);
  print(4,5,sub);
  print(4,5,multi);

  return 0;
}