#include <iostream>

void
tabber(int t)
{
	for(int i=0;i<t;++i)
		std::cout << '\t';
}// End of tabber()

int counter = 0;

int p = 0;

int
power(int x, int n)
{
    if(n==0)
        return 1;                   // Base Case
    else
    {
    	counter++;
    	tabber(counter);
    	p = power(x, n-1);
    	std::cout << p << " ";
        return x * p;   // Making progress towards base case, n-1
    }
}// Recursive power function

int level=0;

int
f(int x)
{
	std::cout << "\tLevel: " << level << " value of x is " << x << std::endl;
	level++; 
	if (x == 0)
		return 0;
	else
	{
		std::cout << "2 * f(" << x-1 << ") + " << x << " x " << x;
		return 2 * f(x - 1) + x * x;
	}
}// End of f(int x)



int
factorial(int n)
{
	int y = 0;
	if (n == 0)
	{
		std::cout << "Base Case Reached!!!!" << std::endl;
		return 1;
	}// End of IF
	else
	{
		tabber(counter++);
		std::cout << "N is " << n << " making recursive call" << std::endl;
		y = n * factorial(n - 1);
		tabber(--counter);
		std::cout << "N is " << n << " returning with value of " << y << std::endl;
		return y;
	}// End of ELSE
}// End of FACTORIAL

void
tail(int i)
{
	if(i > 0)
	{
		std::cout << i << " ";
		tail(i-1);
	}// End of IF
}// End of TAIL

void
nontail(int i)
{
	if(i > 0)
	{
		nontail(i-1);
		std::cout << i << " ";
		nontail(i-1);
	}// End of IF
}// End of NONTAIL

int
fibonacci(int n)
{
	if(n < 2)
		return n;
	else
		return fibonacci(n-2) + fibonacci(n-1);
}// End of FIBONACCI

const int x = 2;
const int n = 4;
const int FIB_MAX = 10;

int
main()
{
	std::cout << x << " raised to the " << n << " power is " << power(x,n) << std::endl;
	std::cout << std::endl;
	
	std::cout << x << " where f(x) is " << std::endl << f(x) << std::endl;
	std::cout << std::endl;

	std::cout << "Recursive calls to calculate factorial of " << x << std::endl;
	factorial(4);
	std::cout << std::endl;

	std::cout << "Tail versus Nontail" << std::endl;
	std::cout << "Tail "; tail(2); std::cout << std::endl;
	std::cout << "Nontail "; nontail(2); std::cout << std::endl;
	std::cout << std::endl;

	for(int i = 0;i < FIB_MAX;++i)
	{
		std::cout << "fibonacci(" << i << ") = " << fibonacci(i) << std::endl;
	}// End of FOR
}