#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 100;
const int HIGH = 100;
const int LOW = 0;

int
linear_search(int *x, int n, int value)
{
	int i = 0;
	for(i = 0; i < n; i++)
	{
    	if(x[i] == value)
		{
			cout << "Number of times in loop " << i << endl;
			cout << "Value " << value << " found!" << endl;
       	 	return 1;
		}// End of IF
	}// End of FOR
	
	cout << "Number of times in loop " << i << endl;
	cout << "Value " << value << " not found!" << endl;

	return 0;
}// End of linear_search()

int
binary_search(int *x, int n, int value)
{
	int first = 0;
	int last = n-1;
	int mid = (last-first)/2;
	int i = 0;
	
	for(;;)
	{
		i++;
		if(first > last)
		{
			cout << "Number of times in loop " << i << endl;
			cout << "Value " << value << " not found!" << endl;
			return 0;
		}// End of IF
		mid = (first + last) / 2;

		if(value < x[mid])
			last = mid - 1;
		else if(value > x[mid])
			first = mid + 1;
		else
		{
			cout << "Number of times in loop " << i << endl;
			cout << "Value " << value << " found!" << endl;
       	 	return 1;
		}// End of ELSE
	}// End of FOR
	return 0;
}// End of binary_search

int
main()
{
	int x[MAX_SIZE];
	cout << "Building array not sorted..." << endl;
	for(int i = 0; i < MAX_SIZE; ++i)
		x[i] = rand() % (HIGH - LOW + 1) + LOW;

	for(int i = 1; i < MAX_SIZE+1; ++i)
	{
		cout << setw(3) << setfill('0') << x[i-1] << " ";
		if(!(i%8))
			cout << endl;	
	}// End of FOR
	cout << endl;

	cout << "Calling linear search on non sorted array ..." << endl;
	linear_search(x, MAX_SIZE, 88);
	cout << "Calling binary search on non sorted array ..." << endl;
	binary_search(x, MAX_SIZE, 88);
	sort(x,x+MAX_SIZE);
	for(int i = 1; i < MAX_SIZE+1; ++i)
	{
		cout << setw(3) << setfill('0') << x[i-1] << " ";
		if(!(i%8))
			cout << endl;	
	}// End of FOR
	cout << endl;

	cout << "Calling linear search on sorted array ..." << endl;
	linear_search(x, MAX_SIZE, 88);
	cout << "Calling binary search on sorted array ..." << endl;
	binary_search(x, MAX_SIZE, 88);
		
}
