#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

// based on http://stackoverflow.com/questions/346858/
//   how-do-you-search-a-stdstring-for-a-substring-in-c


int main()
{

  string str_input = "Total disk space: 9852465";

  string str_number = "0";

  size_t str_index = str_input.rfind(": ");

  if (str_index != string::npos && str_input.length() >= 2)
    {
      str_number = str_input.substr(str_index + 2, str_input.length()
                                    - str_index - 2);

      cout << "Length is " << str_input.length() << endl;
      cout << "Index is  " << str_index << endl;
      cout << "Number is " << str_number << endl << endl;
    }

  return 0;
}
