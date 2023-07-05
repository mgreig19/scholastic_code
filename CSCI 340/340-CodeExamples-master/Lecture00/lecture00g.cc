#include <iostream>
#include <cmath>

void 
print(std::initializer_list<int> vals)
{
	for(auto p = vals.begin(); p != vals.end(); ++p)
		std::cout << *p << "\n";
}// End of void print(intializer_list)

void
print2(std::initializer_list<int> vals)
{
	for(std::initializer_list<int>::iterator p = vals.begin(); p != vals.end(); ++p)
		std::cout << *p << "\n";
}// End of void print(intializer_list)

int
main()
{

	print({1,2,3,4});
	print2({5,6,7,8});

	std::cout << "Precision: " << std::cout.precision(12) << ", Precision: " << std::cout.precision(12) <<", Value: " << std::sqrt(2.0) << std::endl;

}

