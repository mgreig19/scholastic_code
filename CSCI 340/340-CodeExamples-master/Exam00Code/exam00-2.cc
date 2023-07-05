#include <iostream>
#include <list>

std::list<int> qlist;

int 
enqueue(int a)
{
	qlist.push_back(a);
	return 0;
}

int 
dequeue()
{
	int a (0);
	a = qlist.front();
	qlist.pop_front();
	return a;	
}

int
peek()
{
	int a;
	a = qlist.front();
	return a;
}

bool
isEmpty()
{
	return qlist.empty();
} 

int
main()
{
	enqueue(7);
	enqueue(4);
	enqueue(2);
	enqueue(3);
	enqueue(9);
	enqueue(8);
	std::cout << dequeue() << " " << isEmpty() << " " << peek() << std::endl;

	while(!isEmpty())
		std::cout << dequeue() << " ";
	std::cout << std::endl;
}
