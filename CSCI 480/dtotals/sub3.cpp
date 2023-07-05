#include <iostream>
#include <iomanip>
#include <fstream>
#include <boost/regex.hpp>

using namespace std;

int main()
{

  // subtotals - using v. 2 I/O loop

  // uses regex to validate input format
  // compile with -lboost_regex

  static const boost::regex in_pattern("(\\d)\\s(\\d{4})\\s+(\\d+)");
  boost::smatch m;

  ifstream in_file;
  string in_string;

  string dept_no;
  string item_no;
  int count;

  string prev_dept_no;

  int sub_total;
  int grand_total;

  bool beg_of_file = true;
  bool ret;

  sub_total = 0;
  grand_total = 0;

  in_file.open("input_data.txt");
  cout << endl;

  while (true)
    {
      //       in_file >> dept_no >> item_no >> count;

      getline(in_file, in_string);
      if (in_file.eof())  break;

      ret = boost::regex_match(in_string, m, in_pattern);
      if (!ret)
        {
          cout << "input error: " << in_string << endl; 
          exit(1);
        }
      dept_no = m[1];
      item_no = m[2];
      count = atoi(m[3].str().c_str());

      if (beg_of_file)
        {
          beg_of_file = false;
          prev_dept_no = dept_no; 
        }
      else if (dept_no != prev_dept_no)
	 {
          cout << "dept.  " << prev_dept_no << " "
               << setw(10)  << sub_total << endl << endl;
          grand_total += sub_total;
          sub_total = 0;
          prev_dept_no = dept_no;
	 };

      cout << "       " << dept_no << "  " << item_no << " "
           << setw(4) << count << endl;
      sub_total += count;

    };


  cout << "dept.  " << prev_dept_no << " "
       << setw(10)  << sub_total << endl << endl;
  grand_total += sub_total;

  cout << "GRAND TOTAL    " << setw(4) << grand_total << endl;
  cout << endl;

  return 0;
}
