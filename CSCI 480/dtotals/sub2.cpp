#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{

  // subtotals - using v. 2 for I/O loop

  // using getline and istringstream is safer if you might have bad input
  // (or just have multiple record types)

  int prev_dept_no;

  int dept_no;
  int item_no;
  int count;

  int sub_total;
  int grand_total;

  bool beg_of_file = true;


  ifstream in_file;
  in_file.open("input_data.txt");

  sub_total = 0;
  grand_total = 0;

  while (true)
    {
       in_file >> dept_no >> item_no >> count;
       if (in_file.eof())  break;

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

       cout << "       " << dept_no << "  " << item_no << " " << setw(4) << count << endl;
      sub_total += count;

    };


  cout << "dept.  " << prev_dept_no << " "
       << setw(10)  << sub_total << endl << endl;
  grand_total += sub_total;

  cout << "GRAND TOTAL    " << setw(4) << grand_total << endl;
  cout << endl;

  return 0;
}
