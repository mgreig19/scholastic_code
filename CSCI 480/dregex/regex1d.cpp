#include <iostream>
#include <string>

#include <boost/regex.hpp>

using namespace std;

// use of basic regex functions
// based on a suggestion by Richel Bilderbeek 

int main()
{

  string s;
  string s0;
  bool r;

  cout << endl;

  // initialize pattern for a Dutch zip code

  static const boost::regex dutch_zip_pattern("\\d{4}\\s[A-Z]{2}");

  // regex_match must match the entire input

  s = "1234 AB";
  r = boost::regex_match("1234 AB", dutch_zip_pattern);
  cout << s << (r ? " is ": " is not ") << "a Dutch zip code" << endl;

  s = "1234 ab";
  r = boost::regex_match("1234 ab", dutch_zip_pattern);
  cout << s << (r ? " is ": " is not ") << "a Dutch zip code" << endl;

  s = "1234ab";
  r = boost::regex_match("1234ab", dutch_zip_pattern);
  cout << s << (r ? " is ": " is not ") << "a Dutch zip code" << endl << endl;


  // regex_search matches a pattern anywhere in a string

  string s2 = "My Dutch zip code is 1234 AB.";

  r = boost::regex_match(s2, dutch_zip_pattern);
  cout << "s2" << (r ? " is ": " is not ") << "a Dutch zip code" << endl;

  r = boost::regex_search(s2, dutch_zip_pattern);
  cout << "s2" << (r ? " contains ": " does not contain ")
       << "a Dutch zip code" << endl << endl;


  // how to anchor at the front only
  // i.e., determine whether the string starts with the pattern

  r = boost::regex_search(s2, dutch_zip_pattern, boost::match_continuous);
  cout << "s2" << (r ? " starts with ": " does not start with ") << "a Dutch zip code"
       << endl;

  s0 = "1234 AB";
  r = boost::regex_search(s0, dutch_zip_pattern, boost::match_continuous);
  cout << "s0" << (r ? " starts with ": " does not start with ") << "a Dutch zip code"
       << endl << endl;

}
