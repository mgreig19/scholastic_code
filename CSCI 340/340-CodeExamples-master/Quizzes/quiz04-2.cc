#include <iostream>
#include <iomanip>

using namespace std;

int f(int x)
{
	if(x == 0)
		return 0;
	else
		return 2 * f(x -1) + x * x;
}// End of f(int x)

int counter = 0;
int f2(int);

int
f2helper(int x)
{
	if(x > 0)
		cout << setw(counter=counter+4) << "2 * f(" << x << ") + " << x << " * " << x << endl;

	return f2(x);

}

int f2(int x)
{
	int returnValue = 0;
	if(x == 0)
		return returnValue;
	else
		returnValue = 2 * f2helper(x - 1) + x * x;
		cout << setw(counter=counter-4) << returnValue << endl;
		return returnValue;
}

std::string
reverseString(std::string str)
{    
	if (str.length() == 1)        // Base case    
		return str;    
	else
		return reverseString(str.substr(1,str.length())) + str.at(0);
}


int
main()
{
	cout << "Output is " << f(3) << endl;
	f2(3);
	cout << "String " << reverseString("Hello") << endl;
}