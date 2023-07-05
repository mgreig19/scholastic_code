#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

int
main(int argc, char *argv[])
{
	auto start = std::chrono::system_clock::now();

	std::vector<int> v(100000000,0);
	for(int i = 0;i<10;i++)
		cout << v[i] << " ";

	cout << endl;

	int bob[] = {1, 2, 3, 4};
	for(int j : bob)
	{
		cout << j << " ";
	}// End of FOR
	cout << endl;

	auto result = std::minmax({1,2,3,4,5,0,94,43,22});

  	std::cout << "minmax({1,2,3,4,5,0,94,43,22}): ";
  	std::cout << result.first << ' ' << result.second << '\n';
  
	auto end = std::chrono::system_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

	std::cout << elapsed.count() << '\n';
  	return 0;

}