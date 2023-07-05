#include <array>
#include <iostream>

using namespace std;

const int N = 10;
std::array<int, N> myarray;
std::array<int, N*N> multiarray;

int
main()
{

	myarray.fill(0);

	// 2.a Print the value of each element in an array?
	for(int i = 0; i < N; ++i)
		cout << "(" << i << ") " << myarray[i] << endl;		// O(N)

	// 2.b Doubling the value of each element in an array?
	for(int i = 0; i< N; ++i)
		myarray[i] = myarray[i] * 2;						// O(N)

	// 2.c Doubling the value of first element in an array?
	myarray[0] = myarray[0] * 2;							// O(1)

	// 2.d Creating a multiplication table of all the elements 
	// in the array. So if your array [1, 2, 3, 4, 5], you first 
	// multiply every element by 1, then multiply every element
	// by 2, then by 3, and so on.
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			multiarray[i*N+j] = myarray[i] * myarray[j]; 	// O(N^2)
}