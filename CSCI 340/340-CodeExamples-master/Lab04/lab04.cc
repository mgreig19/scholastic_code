////
//
// Lab04: Maps
//
// 1: Create a map M that uses first and last names as keys and age as value (read values from included file).
// 2: Print out age range in 10 year increaments 0 - 10, 11 - 20 and so on (covering range of ages), with the 
//    names in alphabetical order based on lastname.
//
////
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

const int AgeBucket = 10;

typedef std::pair<std::string, std::string> FirstLastNameKey;

struct compareByLastName {
    bool operator()(const FirstLastNameKey& a, const FirstLastNameKey& b) const {
        return (a.second < b.second);
    }
};

bool
compareByAge(std::pair<FirstLastNameKey,int> p, std::pair<FirstLastNameKey,int> q)
{
	return p.second < q.second;
}// End of compareByAge

typedef std::map<FirstLastNameKey, int, compareByLastName> FirstnameLastnameAgeMap;

int 
main() 
{
	FirstnameLastnameAgeMap M;

  	std::string line;
  	
  	// Builds map
  	std::ifstream inputFile("Lab04.in");
  	std::string firstname, lastname, age;
  	
  	if(inputFile.is_open())
  	{
    	while(getline(inputFile,line))
    	{
      		std::stringstream sstr(line);

			sstr >> firstname >> lastname >> age;
    		M.insert(FirstnameLastnameAgeMap::value_type(FirstLastNameKey(firstname,lastname),stoi(age)));
    	}// End of WHILE
    	inputFile.close();
  	}// End of IF
	else std::cout << "Unable to Input File" << std::endl;

	int counter = 0;
	auto maxItr = std::max_element(M.begin(),M.end(),compareByAge);
	std::cout << "Age of the oldest person is: " << maxItr->second << std::endl;

	// Prints out map, in bins as specified
	for(int i = 0; i < maxItr->second; i = i+AgeBucket)
	{
		std::cout << std::endl << "Age: " << i+1 << " to " << i+AgeBucket << std::endl;
		for (auto it = M.begin(); it != M.end(); ++it)
		{
  			if(it->second >= (i+1) and it->second <= (i+AgeBucket))
  				std::cout << "\t" << "(" << counter++ << ")" << it->first.first << " " << it->first.second << " "  << it->second << std::endl;
		}// End of FOR
	}// End of FOR

  return 0;

}// End of MAIN