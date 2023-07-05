#include <iostream>
#include <iomanip>
#include <string>

void 
f(const std::string& s, int i)
{
	if(i < s.length())		// Base case achieved when i > s.length()
	{
		std::cout << s[i];
		f(s, i+1);			// Working towards base case
	}// End of IF
}// End of f(const string& s, int i)

void 
rf(const std::string& s, int i)
{
	if(i < s.length())		// Base case achieved when i > s.length()
	{
		rf(s, i+1);			// Working towards base case
		std::cout << s[i];
	}// End of IF
}// End of f(const string& s, int i)

const std::string s = "Hello";

int
main()
{
	
    f(s,0);
    std::cout << std::endl;
    f(s,3);
    std::cout << std::endl;
    
    // Reverse
    rf(s,0);
   	std::cout << std::endl;
    rf(s,3);
    std::cout << std::endl;

	return 0;
}