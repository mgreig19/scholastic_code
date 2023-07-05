#include <iostream>
#include <fstream>
#include <string>
#include <boost/regex.hpp>

// more regex features:
// - extended syntax
// - structure of 'smatches'

// based on a suggestion in
// http://stackoverflow.com/questions/7304026/extracting-submatches-using-boost-regex-in-c

using namespace std;

int main(int argc, char* argv[]) {

  string pattern = "(abc)(def)";  
  string target = "abcdef"; 

  boost::regex regexPattern(pattern, boost::regex::extended); 
  boost::smatch what; 
  bool isMatchFound; 

  int i;

  isMatchFound = boost::regex_match(target, what, regexPattern); 
  if (isMatchFound) 
    { 
      for (i = 0; i < what.size(); i++) 
	{ 
	  cout << "WHAT " << i << " " << what[i] << endl; 
	} 
    } 

}
