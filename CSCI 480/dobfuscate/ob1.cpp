#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

#include <math.h>

using namespace std;

int f(int x)
{
  int i;
  float fl;

  fl = 96.75 + -21.98*cos(x*1.118) + 13.29*sin(x*1.118) + -8.387*cos(2*x*1.118)
	     + 17.94*sin(2*x*1.118) + 1.265*cos(3*x*1.118) + 16.58*sin(3*x*1.118)
	     + 3.988*cos(4*x*1.118) + 8.463*sin(4*x*1.118) + 0.3583*cos(5*x*1.118)
             + 5.878*sin(5*x*1.118);
  i = int(round(fl));
  // cout << "** " << x << " " << fl << " " << i << " " << char(i) << endl;
  return(i);
}

int main()
{
  int j;
  char a[13];
  a[12] = 0;

  for (j = 0; j < 12; j++)
    {
      a[j] = f(j);
    }

  cout << endl << a << endl << endl;
}
