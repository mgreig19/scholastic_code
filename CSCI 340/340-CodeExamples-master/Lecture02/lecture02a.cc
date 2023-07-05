// from http://www.cplusplus.com/reference/algorithm/random_shuffle/
// from http://www.cplusplus.com/reference/algorithm/find/
// from http://www.cplusplus.com/reference/algorithm/count_if/
//

#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle std::find std::count_if
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

// random generator function:
int myrandom (int i) { return std::rand()%i;}
bool IsOdd (int i) { return ((i%2)==1); }

int main () {

/******************* random_shuffle ******************************/
 	std::srand(unsigned(std::time(0)));
  std::vector<int> myvector;

  // set some values:
  for (int i=1; i<10; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

 	std::cout << "myvector (before shuffle) contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  // using built-in random generator:
  std::random_shuffle ( myvector.begin(), myvector.end() );
 	std::cout << "myvector (after shuffle) contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
	std::cout << '\n';

	// using myrandom:
	std::random_shuffle ( myvector.begin(), myvector.end(), myrandom);
	// print out content:
	std::cout << "myvector (after myrandom shuffle) contains:";
	for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
	std::cout << '\n';

/**************************** find *********************************/
  int myints[] = { 10, 20, 30, 40 };
	int * p;

	p = std::find (myints, myints+4, 30); // find over an array
	if (p != myints+4)
  	std::cout << "Element found in myints: " << *p << '\n';
	else
  	std::cout << "Element not found in myints\n";

  p = std::find (myints, myints+4, 15); // find over an array
	if (p != myints+4)
  	std::cout << "Element found in myints: " << *p << '\n';
	else
  	std::cout << "Element not found in myints\n";

	// using std::find with vector and iterator:
	std::vector<int> myintvector (myints,myints+4);
	std::vector<int>::iterator it;

	it = find (myintvector.begin(), myintvector.end(), 30);
	if (it != myintvector.end())
  	std::cout << "Element found in myintvector: " << *it << '\n';
	else
  	std::cout << "Element not found in myintvector\n";
    
/**************************** count_if *********************************/
  std::vector<int> mycountvector;
  for (int i=1; i<10; i++) 
    mycountvector.push_back(i); // mycountvector: 1 2 3 4 5 6 7 8 9

  int mycount = count_if (mycountvector.begin(), mycountvector.end(), IsOdd);
  std::cout << "mycountvector contains " << mycount  << " odd values.\n";
      
  return 0;
}
