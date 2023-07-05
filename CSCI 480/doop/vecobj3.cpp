// example: vector of pointers to dynamically allocated
// variable-length objects

#include <memory>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <vector>

// instead of #include "Person.h", we will put the class definition
// here don't forget the .h file needs header guards

using namespace std;

class Person
{

private:
  string id;
  string name;

public:
  Person();
  string get_id();
  void set_id(string input_id);
  string get_name();
  void set_name(string input_name);
};


// --

int main ()
  {
    vector <shared_ptr<Person>> people;
    vector <shared_ptr<Person>>::iterator it;

    shared_ptr<Person> pers_ptr;
    int i;

    // make some people and add to list
    // make sure each person gets their own memory
    // so we don't get multiple ptrs to the same object

    // make first person and push onto vector
    pers_ptr = make_shared<Person>(Person());
    pers_ptr->set_id("1234");
    pers_ptr->set_name("Smith");
    people.push_back(pers_ptr);

    // make second person and push onto vector
    pers_ptr = make_shared<Person>(Person());
    pers_ptr->set_id("567");
    pers_ptr->set_name("Johnson");
    people.push_back(pers_ptr);

    // now iterate through the list

    cout << endl;
    cout << "People to call in case of emergency:" << endl << endl;

    // print all people
    for (it = people.begin(); it != people.end(); it++)
      {
        cout << setw(6) << right << (*it)->get_id()   << "  "
	     << setw(8) << left <<  (*it)->get_name() << endl;
      }

    cout << endl;
    return 0;
  }

// --

// functions would normally go in Person.cpp
// ... which of course needs to #include Person.h

// remember that each file (compilation unit) needs its own includes
// and 'using' statement(s)

Person::Person()
{
  id = "";
  name = "";
}

string Person::get_name()
{
  return name;
}

string Person::get_id()
{
  return id;
}

void Person::set_name (string input_name)
{
  name = input_name;
}

void Person::set_id (string input_id)
{
  id = input_id;
}
