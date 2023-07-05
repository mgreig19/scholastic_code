#include <iostream>

using namespace std;

const int BIG_N = 10;

int
f(int x)
{
	if(x < 0)
		cout << "ERROR" << endl;
	if(x == 0)
		return x;
	if(x == 1)
		return x;

	return f(x-2) + f(x-1);
}

int
main()
{
	for(int i = 0; i < BIG_N;++i)
		cout << "f(" << i << ") is " << f(i) << endl;;
}