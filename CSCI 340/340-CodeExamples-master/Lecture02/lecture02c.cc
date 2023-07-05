#include <iostream>
#include <string>

using std::cout;
using std::endl;

int
main()
{
	std::string s1;
  	cout << "String1: " << s1 << endl;

  	s1 = "Good Morning";
  	cout << "String1: " << s1 << endl;

  	std::string s2 = s1 + s1;
  	cout << "String2: " << s2 << endl;

	cout << "String1 and String2 are ";
  	if(s1 == s2)
    	cout << "Equal" << endl;
  	else
    	cout << "Not Equal" << endl;

	return 0;
}// End of MAIN()
