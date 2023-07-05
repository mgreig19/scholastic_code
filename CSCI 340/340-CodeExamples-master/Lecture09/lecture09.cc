#include <iostream>

using namespace std;

double 
powerFOR(double x, int n)
{
	double product = 1;
	int i;
	for(i = 1; i <= n; i++)
		product *= x;
	return product;
}// End of power using for loop

double 
powerRECURSIVE(double x, int n)
{
	if(n == 0)						// base case
		return 1.0;
	else
		return x * powerRECURSIVE(x, n-1); 	// recursive step
}// End of power using recursion

int 
gcd(int a, int b)
{
if(b == 0)							// base case
	return a;
else
	return gcd(b, a%b);				// recursive step
}// End of GCD(int a, int b)

std::string
reverseString(std::string str)
{    
	if (str.length() == 1)        	// base case    
		return str;    
	else
		return reverseString(str.substr(1,str.length())) + str.at(0);
}


int
main()
{
	cout << "Power function using FOR loop: " << powerFOR(2.0, 5) << endl;
	cout << "Power function using recursive function: " << powerRECURSIVE(2.0, 5) << endl;
	cout << "Greatest common divisor of 234 and 22 is: " << gcd(234, 22) << endl;
	cout << "String " << reverseString("Hello") << endl;
}