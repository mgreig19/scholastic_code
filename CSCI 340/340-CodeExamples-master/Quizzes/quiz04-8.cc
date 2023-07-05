#include <iostream>
#include <math.h>
#include <iomanip>

const int SOME_N = 100;
int loopCounter = 0;

using namespace std;


int
main()
{
	int i,j;
	int n = SOME_N;
	int a[SOME_N];
	int sum = 0;


	for(i=0;i<n;i++)
	{

		for(j=1,sum=a[0];j<=i;j++)
		{
			sum += a[j];
			loopCounter++;
		}

//		cout << "Sum for " << i << " is " << sum << endl;
	}// End of FOR
	cout << "Loop Counter for snippet is " << loopCounter << " and if we looked at O(N Log(N)) for N equal to " << SOME_N;
	cout << " we get " << int(log(SOME_N)*SOME_N) << " and O(N*N) " << SOME_N*SOME_N << endl;
	cout << endl << "This snippet is O(N**2)."<< endl;
}