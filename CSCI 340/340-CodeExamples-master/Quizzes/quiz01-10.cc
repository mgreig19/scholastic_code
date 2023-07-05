#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;

int main()
{
	vector<int> myVector;
	myVector.push_back(7);
	cout << "push_back(7): ";
	for(int i=0;i<myVector.size();++i)
		cout << myVector[i] << " ";
	cout << endl;

	myVector.push_back(6);
	cout << "push_back(6): ";
	for(int i=0;i<myVector.size();++i)
		cout << myVector[i] << " ";
	cout << endl;

	myVector.push_back(5);
	cout << "push_back(5): ";
	for(int i=0;i<myVector.size();++i)
		cout << myVector[i] << " ";
	cout << endl;

	sort(myVector.begin(),myVector.end());
	cout << "sort: ";
	for(int i=0;i<myVector.size();++i)
		cout << myVector[i] << " ";
	cout << endl;

	myVector.pop_back();
	cout << "pop from back: ";
	for(int i=0;i<myVector.size();++i)
		cout << myVector[i] << " ";
	cout << endl;

	myVector.push_back(4);
	cout << "push_back(4): ";
	for(int i=0;i<myVector.size();++i)
		cout << myVector[i] << " ";
	cout << endl;

	myVector.push_back(9);
	cout << "push_back(9): ";
	for(int i=0;i<myVector.size();++i)
		cout << myVector[i] << " ";
	cout << endl;

	return 0;
}
