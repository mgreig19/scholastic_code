#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{

  // multiple levels of subtotals

  // using v. 2 for I/O loop

  // using getline and istringstream is safer if you might have bad input
  // (or just have multiple record types)

  string prev_area;
  string prev_exch;

  string in_area;
  string in_exch;
  string in_number;

  int total_exch;
  int total_area;
  int total_grand;

  bool beg_of_file = true;


  ifstream in_file;
  in_file.open("mult-data.txt");

  total_exch  = 0;
  total_area  = 0;
  total_grand = 0;

  while (true)
    {
       in_file >> in_area >> in_exch >> in_number;
       if (in_file.eof())  break;

       if (beg_of_file)
         {
           beg_of_file = false;
           prev_exch = in_exch; 
           prev_area = in_area;
         }
      else if (prev_area != in_area)
	 {
           // forced exchange total
           cout << "exch total  " << prev_area << " " << prev_exch
                << setw(3) << total_exch << "   *" << endl;
           total_area += total_exch;

           // area total
	   cout << "area total  " << prev_area << "    "
                << setw(3) << total_area << "   **" << endl << endl;
           total_grand += total_exch;

           // reset exchange and area
           prev_exch = in_exch;
           prev_area = in_area;
           total_exch = 0;
           total_area = 0;
	 }
      else if (prev_exch != in_exch)
	{
          // exchange total
           cout << "exch total  " << prev_area << " " << prev_exch
                << setw(3) << total_exch << "   *" << endl;
          total_area += total_exch;
          // reset exchange
          total_exch = 0;
          prev_exch = in_exch;
        }

      // print detail line
      cout << "                         "
           << in_area << " " << in_exch << " " << in_number << endl;
      total_exch += 1;

    };


  // forced exchange total at eoj
  cout << "exch total  " << prev_area << " " << prev_exch
       << setw(3) << total_exch << "   *" << endl;
  total_area += total_exch;

  // forced area total at eoj
  cout << "area total  " << prev_area << "    "
       << setw(3) << total_area << "   **" << endl << endl;
  total_grand += total_area;

  // grand total
  cout << "GRAND TOTAL " << "       " << setw(3) << total_grand << "   ***" << endl;
  cout << endl;

  return 0;
}
