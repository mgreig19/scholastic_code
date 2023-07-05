#include <iostream>
#include <vector>

const int WONK = 4;

bool
wonkySort(const int &rhs, const int &lhs)
{
	return ((lhs%WONK) > (rhs%WONK));
}// End of wonkySort(int &, int&)

int
main()
{
	std::vector<int> v = {12, 10, 11, 16, 15};	

	std::cout << "Vector: ";
	for(auto itr=v.begin();itr!=v.end();++itr)
		std::cout << *itr << " ";
	std::cout << std::endl;

	sort(v.begin(),v.end(),wonkySort);
	std::cout << "Vector with wonkySort: ";
	for(auto itr=v.begin();itr!=v.end();++itr)
		std::cout << *itr << "(" << *itr%WONK << ") ";
	std::cout << std::endl;
}