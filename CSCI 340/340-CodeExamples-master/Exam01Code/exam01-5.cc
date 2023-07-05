#include <iostream>

using namespace std;

const int BIG_N = 10;

int
sum(int x)
{
	if(x == 0)
		return 0;
	else 
		return x + sum(x-1);
}// End of sum(int x)

int
main()
{
	// Iterative
	int count;
	for(int i = 0; i < BIG_N; ++i)
	{
		count = 0;
		cout << "sum(" << i << ") = ";
		for(int j = 0; j <= i; ++j)
		{
			count += j;
			cout << j << " ";
			if(j<i)
				cout << "+ ";
		}

		cout << "= " << count << endl;
	}

	// Recursive
	for(int i = 0; i < BIG_N; ++i)
	{
		cout << "sum(" << i << ") = ";
		for(int j = 0; j <= i; ++j)
		{
			cout << j << " ";
			if(j<i)
				cout << "+ ";
		}

		cout << "= " << sum(i) << endl;
	}
}