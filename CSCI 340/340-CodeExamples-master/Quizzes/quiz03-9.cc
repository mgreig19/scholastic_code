#include <iostream>

int
power(int x, int n)
{
    if(n==0)
        return 1;                   // Base Case
    else
        return x * power(x, n-1);   // Making progress towards base case, n-1
}// Recursive power function

const int MAX_X = 10;
const int MAX_N = 5;

int
main()
{
	
    for(int x=0;x<MAX_X;++x)
        for(int n=1;n<MAX_N;++n)
            std::cout << x << " to the " << n << " equals " << power(x,n) << std::endl;

	return 0;
}
