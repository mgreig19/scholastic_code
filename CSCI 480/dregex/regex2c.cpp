#include <iostream>
#include <fstream>
#include <string>
#include <boost/regex.hpp>

// a bunch of matches
// based on a suggestion by O'Reilly OnLamp

using namespace std;

int main(int argc, char* argv[]) {

  string filename;

  // <a
  // \\s+
  // href=
  // \"
  // ([\\- : \\w \\d \\. \\/]+)
  //  
  // \"
  // >;

  boost::regex re("<a\\s+href=\"([\\-:\\w\\d\\.\\/]+)\">");
  boost::smatch matches;

  string sbuf;
  string::const_iterator begin;
  string::const_iterator end;

  if (argc > 1)
    filename = argv[1];
  else
    filename = "niuhomepage.shtml";


  ifstream infile(filename.c_str());

  while (true)
    {
      getline(infile,sbuf);
      if (infile.eof()) break;

      begin = sbuf.begin();
      end = sbuf.end();

      while (boost::regex_search(begin, end, matches, re))
	{
	  string url(matches[1].first, matches[1].second);
	  cout << "URL: " << url << endl;
	  // Update the beginning of the range to the character
	  // following the match
	  begin = matches[1].second;
	}
    }
}
