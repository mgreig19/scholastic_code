#include <iostream>
#include <list>

int
main()
{
	std::list<int> mylist;
	for(int i = 1; i <= 5; ++i) 
		mylist.push_back(i);

	//EXTRA CODE NOT IN QUIZ
	std::cout << "mylist forwards: "; 
	for(auto itr = mylist.begin(); itr != mylist.end(); ++itr)
		std::cout << *itr << " ";
	std::cout << std::endl;

	std::cout << std::endl << "Various approaches to printing out list in reverse" << std::endl;
/* Several different solutions */
	std::cout << "#1 mylist backwards: ";
	/* INSERT YOUR CODE HERE */
	std::list<int>::reverse_iterator rev;
	for(rev = mylist.rbegin();rev != mylist.rend(); ++rev)
		std::cout << *rev << " ";
	std::cout << '\n';

	std::cout << "#2 mylist backwards: ";
	/* INSERT YOUR CODE HERE */
	for(auto itr = mylist.rbegin(); itr != mylist.rend(); ++itr)
		std::cout << *itr << " ";
	std::cout << std::endl;

	std::cout << "#3 mylist backwards: ";
	/* INSERT YOUR CODE HERE */
	for(auto itr = --(mylist.end()); itr != (--mylist.begin());  --itr) 
		std::cout << *itr << " " ;
	std::cout << std::endl;

	// This method works to print the list backwards but is destructive, the list is empty at the end!!!!
	std::cout << "#4 mylist backwards: ";
	for(int i = 5;i>=1;i--)
	{
		std::cout << mylist.back() << " ";
		mylist.pop_back();
	}
	std::cout << std::endl;



	return 0;
}