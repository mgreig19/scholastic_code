#include <iostream>
#include <fstream>
#include <string>
#include <boost/regex.hpp>

// opposite of regex6 - shows default = maximal munch = leftmost longest


using namespace std;

int main(int argc, char* argv[])
{

  string text("SolutionAN ANANANA SolutionBN");
  boost::regex regex("Solu(.*)N");

  boost::sregex_token_iterator iter(text.begin(), text.end(), regex, 0);
  boost::sregex_token_iterator end;

  for( ; iter != end; ++iter)
    {
      cout<< *iter << endl;
    }

  return 0;

}
