#include <iostream>
#include <fstream>
#include <string>
#include <boost/regex.hpp>

// more regex features:
// - token iterator

// based on a suggestion in
// http://stackoverflow.com/questions/3122344/boost-c-regex-how-to-get-multiple-matches

using namespace std;

int main(int argc, char* argv[])
{

  string text("abc abd");
  boost::regex regex("ab.");

  boost::sregex_token_iterator iter(text.begin(), text.end(), regex, 0);
  boost::sregex_token_iterator end;

  for( ; iter != end; ++iter)
    {
      cout<< *iter << endl;
    }

  return 0;

}
