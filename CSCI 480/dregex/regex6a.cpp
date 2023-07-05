#include <iostream>
#include <fstream>
#include <string>
#include <boost/regex.hpp>

// more regex features:
// - token iterator again
// - '?' = non-greedy '*' 
//    overrides default, which is maximal munch = leftmost longest

// based on a suggestion in
// http://stackoverflow.com/questions/16665981/boost-c-regex-how-to-return-all-matches

using namespace std;

int main(int argc, char* argv[])
{

  string text("SolutionAN ANANANA SolutionBN");
  boost::regex regex("Solu(.*?)N");

  boost::sregex_token_iterator iter(text.begin(), text.end(), regex, 0);
  boost::sregex_token_iterator end;

  for( ; iter != end; ++iter)
    {
      cout<< *iter << endl;
    }

  return 0;

}
