#include <iostream>
#include <fstream>
#include <string>
#include <boost/regex.hpp>

// more regex features:
// nested 'smatches'

using namespace std;

int main(int argc, char* argv[]) {

  string pattern = "((a)(bc))((d)(ef))";  
  string target = "abcdef"; 

  boost::regex regexPattern(pattern, boost::regex::extended); 
  boost::smatch what; 

  int i;
  bool isMatchFound; 

  isMatchFound = boost::regex_match(target, what, regexPattern); 
  if (isMatchFound) 
    { 
      for (i = 0; i < what.size(); i++) 
	{ 
	  cout << "WHAT " << i << " " << what[i] << endl; 
	} 
    } 

}
