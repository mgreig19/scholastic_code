/* swap1c.cpp      */

#include <iostream>
#include <iomanip>

using namespace std;

void swap1 (int i, int j);
void swap3 (int* ip, int* jp);

int main()
{

int i, j;

i = 3;
j = 4;
swap1(i, j);
cout << "a: " << i << " " << j << endl;

int* ip;
ip = &i;
int* jp;
jp = &j;

i = 3;
j = 4;

swap3(ip, jp);
cout << "g: " << *ip << " " << *jp << endl;

i = 3;
j = 4;

swap1(*ip, *jp);
cout << "h: " << i << " " << j << endl;

return 0;
}

void swap1 (int i, int j)
{ 
int x;
x = i;
i = j;
j = x;
}


void swap3 (int* ip, int* jp)
{
int x;
x = *ip;
*ip = *jp;
*jp = x;
}


/* Output:

a: 3 4
g: 4 3
h: 3 4

*/


