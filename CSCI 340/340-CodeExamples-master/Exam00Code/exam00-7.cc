#include <iostream>
#include <vector>

int
main()
{
	// Create vector with 12, 10, 11, 16, 15
	std::vector<int> v = {12, 10, 11, 16, 15};	

	// Print out vector
	std::cout << "Vector: ";
	for(auto itr=v.begin();itr!=v.end();++itr)
		std::cout << *itr << " ";
	std::cout << std::endl;

	// Alternative method to create vector
	std::vector<int> altv;
	altv.push_back(12);				// 12
	altv.push_back(10);				// 12 10
	altv.push_back(11);				// 12 10 11
	altv.push_back(16);				// 12 10 11 16
	altv.push_back(15);				// 12 10 11 16 15

	std::cout << "Alt Vector: ";
	for(auto itr=altv.begin();itr<altv.end();++itr)
		std::cout << *itr << " ";
	std::cout << std::endl;

	std::cout << "Alt Vector using size and subscript: ";
	for(int i = 0; i < altv.size(); i++)
		std::cout << altv[i] << " ";
	std::cout << std::endl;                                                                                                                                                                                                                                                                                                                                                                                                                                          
}