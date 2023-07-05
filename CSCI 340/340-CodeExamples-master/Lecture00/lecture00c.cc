#include <iostream>
#include <string>

using namespace std;

class Name
{
	public:
		Name();
		Name(string first, string last);
		
		string getFirstName();
		string getLastName();
		int setFirstName(string first);
		int setLastName(string last);
		int printName();

	private:
		string firstname;
		string lastname;
};

Name::Name()
{
	firstname = "empty";
	lastname = "empty";
}// End of Name()

Name::Name(string first, string last)
{
	firstname = first;
	lastname = last;
}// End of Name(string, string)

string
Name::getFirstName()
{
	return firstname;
}// End of getFirstName()

string
Name::getLastName()
{
	return lastname;
}// End of getLastName()

int
Name::setFirstName(string first)
{
	firstname = first;
	return 0;
}// End of setFirstName(string)

int
Name::setLastName(string last)
{
	lastname = last;
	return 0;
}// End of setLastName(string)

int
Name::printName()
{
	cout << firstname << " " << lastname;
	return 0;
}// End of printName()

int
main(int argc, char *argv[])
{
	Name foo("John","Smith");
	Name boo;

	boo.setFirstName("Jane");
	boo.setLastName("Doe");

	boo.printName();
	cout << endl;

	cout << "First Name: " << foo.getFirstName() << " Last Name: " << foo.getLastName() << endl;
	return 0;
}