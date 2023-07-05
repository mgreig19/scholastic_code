#include <iostream>
#include <list>
#include <stack>

int main ()
{
// Question #5 from Quiz02
  	std::stack<int> s;
	int x = 3;
	int y = 5;

	s.push(8);
	s.push(x);
	s.push(y);
	x = s.top();
	s.pop();
	std::cout << x << std::endl;				// Output 1____5_______
	y = s.top();
	std::cout << y << std::endl;				// Output 2____3________
	s.pop();
	s.push(25);

	while(!s.empty()){
		y = s.top();
		s.pop();
		std::cout << y << " ";					// Output 3__25___8_____
	}// End of WHILE
	std::cout << std::endl;

	// Question #9

  	std::list<int> mylist;
  	for(int i=1; i<=5; ++i) mylist.push_back(i);

  	std::cout << "mylist backwards:";
 
 	/* INSERT YOUR CODE BELOW */
	for(std::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
    	std::cout << ' ' << *rit;

  	std::cout << '\n';
  	return 0;
}
