#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using std::string;
using std::ifstream;
using std::cerr;
using std::cout;
using std::endl;
using std::setprecision;
using std::ios;

int main()
{

  ifstream  binfile;

  string  binfilename = "bin.dat";

  float f1;
  double d1;
    
  // Binary mode
  binfile.open(binfilename.c_str(), ios::binary);

  if(!binfile)
    {
      cerr << "Can't open " << binfilename << endl;
      return -1;
    }

  cout << setprecision(20);
  cout << "f1 before read: " << f1 << endl;
  cout << "d1 before read: " << d1 << endl;

  binfile.read((char *) &f1, sizeof(float));
  binfile.read((char *) &d1, sizeof(d1));

  binfile.close();

  cout << "f1 after read: " << f1 << endl;
  cout << "d1 after read: " << d1 << endl;

  return 0;
}
