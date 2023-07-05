//////
//	
// Adapted from www.cplusplus.com
//
// 
//
#include <iostream>
#include <set>
#include <map>

bool fncompInt (int lhs, int rhs) {return lhs>rhs;}

struct classcompInt {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs>rhs;}
};

bool fncompChar (char lhs, char rhs) {return lhs>rhs;}

struct classcompChar {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs>rhs;}
};

// Adapted from "Designing Components with the C++ STL"
template<class Container>
void 
showSequence(const Container &s, const char *sep = " ", std::string prefix = "", std::ostream &where = std::cout)
{
	typename Container::const_iterator iter = s.begin();
	if(prefix != "")
		where << prefix << ": ";
	while(iter != s.end())
		where << *iter++ << sep;
	where << std::endl;
}

int main ()
{

	// Set
	std::set<int> firstSet;                           					// empty set of ints
	showSequence(firstSet," ","firstSet");

  	int myints[]= {10,20,30,40,50};
  	std::set<int> secondSet(myints,myints+5);        					// range
  	showSequence(secondSet," ","secondSet");

	std::set<int> thirdSet(secondSet);                  				// a copy of second
 	showSequence(thirdSet," ","thirdSet");

	std::set<int> fourthSet(secondSet.begin(), secondSet.end());  		// iterator 
	showSequence(fourthSet," ","fourthSet");
	
	std::set<int,classcompInt> fifthSet(myints,myints+5);;   			// class as Compare
	showSequence(fifthSet," ","fifthSet");
	
  	bool(*fn_ptInt)(int,int) = fncompInt;
  	std::set<int,bool(*)(int,int)> sixthSet(myints,myints+4,fn_ptInt); 	// function pointer as Compare
	showSequence(sixthSet," ","sixthSet");
	
 	std::cout << std::endl << std::endl;

 	// Map 
  	std::map<char,int> firstMap;
  	std::cout << "firstMap: ";
  	for (const auto &p : firstMap)
    	std::cout << "[" << p.first << "] = " << p.second << " ";
    std::cout << std::endl;

  	firstMap['a']=10;
  	firstMap['b']=30;
  	firstMap['c']=50;
  	firstMap['d']=70;

  	std::map<char,int> secondMap (firstMap.begin(),firstMap.end());
  	std::cout << "secondMap: ";
  	for (const auto &p : secondMap)
    	std::cout << "[" << p.first << "] = " << p.second << " ";
    std::cout << std::endl;

  	std::map<char,int> thirdMap (secondMap);
  	std::cout << "thirdMap: ";
  	for (const auto &p : thirdMap)
    	std::cout << "[" << p.first << "] = " << p.second << " ";
    std::cout << std::endl;

  	std::map<char,int,classcompChar> fourthMap(firstMap.begin(),firstMap.end());                 // class as Compare
  	std::cout << "fourthMap: ";
  	for (const auto &p : fourthMap)
    	std::cout << "[" << p.first << "] = " << p.second << " ";
    std::cout << std::endl;

  	bool(*fn_ptChar)(char,char) = fncompChar;
  	std::map<char,int,bool(*)(char,char)> fifthMap(firstMap.begin(),firstMap.end(),fn_ptChar); // function pointer as Compare
	std::cout << "fifthMap: ";
  	for (const auto &p : fifthMap)
    	std::cout << "[" << p.first << "] = " << p.second << " ";
    std::cout << std::endl;
	
	return 0;
}
