////
//
// Lab03: Sets and Recursion
//
// 1: Recursiveling generate the Fibonacci numbers up to and including 10 and add them to set R.
// 2: Generate a second set O of odd numbers from 1 to 100.
// 3: Create a set I that is the intersection of R and O by STL set_intersection.
// 4: Create a set U that is the union of the sets R and the first half of set O, you may not use STL set_union.
// 4: Create a map that uses first and last names as keys and age as value (read values from included file).
// 5: Print out age range in 10 year increaments 0 - 10, 11 - 20 and so on.
//
////
#include <iostream>
#include <set>
#include <algorithm>

const int RANGE_FOR_FIB = 11;
const int RANGE_FOR_ODD = 100;

int
fibonacci(int n)
{
	if(n == 0)
		return 0;
	else if(n == 1)									// Base case
		return 1;
    else
        return fibonacci(n - 1)+fibonacci(n - 2);
}// End of fibonacci

template<class Container>
void 
showSequence(const Container &s, const char *sep = " ", const char *prefix = "", std::ostream &where = std::cout)
{
//	int counter = 0;
  	typename Container::const_iterator iter = s.begin();
  	if(strncmp(prefix,"",1))
    	where << prefix << ": ";
  	while(iter != s.end())
  	{
    	where << *iter++ << sep;
//    	where << "(" << counter << ")" << *iter++ << sep;
//    	counter++;
  	}
  	where << std::endl;
}

int
main()
{
	std::set<int> R;
	std::set<int> O;

	for(int i = 0; i <= RANGE_FOR_FIB; ++i)
		R.insert(fibonacci(i));

	for(int i = 1;i < RANGE_FOR_ODD; ++i)
		if(i%2)
			O.insert(i);

	showSequence(R, " ", "Set R");
	showSequence(O, " ", "Set O");

	std::set<int> I;
	std::set_intersection(R.begin(), R.end(), O.begin(), O.end(), std::inserter(I,I.begin()));
	showSequence(I, " ", "Intersection of set R and O");

	auto itrO = O.begin();  // Start of Set O
	int size = O.size()/2;  // Half the size of Set O
	std::set<int> U;		// Empty set U

	for(int i = 0; i < size; ++i) 	// Filling U up with half of O
		U.insert(*itrO++);

	auto itrR = R.begin();			// Start of set R
	while(itrR != R.end())			// Inserting R into U, we know R is smaller and sets dump duplicates so we
		U.insert(*itrR++);			// will have the UNION of half of set O and set R

	showSequence(U, " ", "Union of half of set O and all of set R"); 	// Union of half of the set O and set R

}