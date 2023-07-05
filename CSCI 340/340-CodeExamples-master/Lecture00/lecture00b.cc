// initialization of variables
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	int a = 25;
	int b(2);
	int result;

    cout << "Hex: " << std::hex << 255 << std::dec << endl;

	a = a + 3;
	result = a - b;

    cout << "a =" << a << " b =" << b;
    cout << " result of a-b: " << result << " now in hex: " << std::hex << result << endl;

	int values[] {1, 2, 3};
	vector<int> v {2, 3, 4, 5, 6, 7, 8};
	vector<string> cities {"DeKalb", "Chicago", "Rockford"};

	cout << endl <<  "Values for array of ints: ";
	for(int i=0;i<3;i++)
	{
		cout << values[i] << " ";
	}
	cout << endl;

	cout << "Values for vector of ints: ";
	for(int i=0;i<7;i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	cout << "Values for vector of strings: ";
	for(int i=0;i<3;i++)
	{
		cout << cities[i] << " ";
	}
	cout << endl;

	return 0;
}
