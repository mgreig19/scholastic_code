#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using std::string;
using std::ofstream;
using std::cerr;
using std::endl;
using std::setprecision;
using std::ios;

int main()
{

  ofstream  txtfile;
  ofstream  binfile;

  string  txtfilename = "txt.dat";
  string  binfilename = "bin.dat";

  float f1 = 3.14159265358979323846;
  double d1 = 3.14159265358979323846;
    

  // Text mode
  txtfile.open(txtfilename.c_str());

  if(!txtfile)
    {
      cerr << "Can't open " << txtfilename << endl;
      return -1;
    }

  txtfile << setprecision(20);
  txtfile << f1 << " " << d1;

  txtfile.close();


  // Binary mode
  binfile.open(binfilename.c_str(), ios::binary);

  if(!binfile)
    {
      cerr << "Can't open " << binfilename << endl;
      return -1;
    }

  binfile.write((char *) &f1, sizeof(float));
  binfile.write((char *) &d1, sizeof(d1));

  binfile.close();
  return 0;
}
