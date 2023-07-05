#include <iostream>

int add(int a, int b);
int sub(int a, int b);
int multi(int a, int b);

int print(int a, int b, int (*p)(int, int));

using namespace std;

int
add(int a, int b)
{
	return (a+b);
}

int
sub(int a, int b)
{
	return (a-b);
}

int 
multi(int a, int b)
{
	return (a*b);
}

int 
print(int a, int b, int (*p)(int x, int y))
{
	cout << "Calling a function with " <<  a << " " << b << " result " << (p)(a,b) << endl;
	return 0;
}

int
main()
{
	print(4, 5, add);
	print(4, 5, sub);
	print(4, 5, multi);

	return 0;
}
