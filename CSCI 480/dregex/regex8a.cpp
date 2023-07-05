#include <iostream>
#include <fstream>
#include <string>
#include <boost/regex.hpp>

// reading a file w/ regex

using namespace std;

int main(int argc, char* argv[]) {

  string filename;

  if (argc > 1)
    filename = argv[1];
  else
    filename = "input_data.txt";
  ifstream infile(filename.c_str());

  // -------------------------------------------------
  

  boost::regex re("(\\d+)\\s+(\\d+)\\s+(\\d+)");
  boost::smatch matches;

  string input_line;
  int input_count;
  bool result;

  string expt_string;
  string eqpt_string;
  string value_string;

  input_count = 0;
  cout << endl;

  while (true)
    {
      getline(infile,input_line);
      if (infile.eof()) break;
      input_count += 1;
      
      result = boost::regex_match(input_line, matches, re);

      if (result)
	{
	  expt_string = matches[1];
          eqpt_string = matches[2];
	  value_string = matches[3];
	  cout << "Record #" << input_count << " "
	       << expt_string << " "
	       << eqpt_string << " "
	       << value_string << endl;
	}
      else
	cout << "Record # " << input_count
	     <<	"has incorrect format: " << input_line << endl;
    }
  cout << endl;
}
