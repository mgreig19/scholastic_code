#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <iomanip>

using namespace std;


/* arptr3c.cpp   */

/* passing an array name as a pointer (and printing it as a pointer)
   using it to update the array in place
   shows pointer arithmetic in an integer array   */

void subr (int* ip);

int main()
{

int ar[10] = {10, 20};
int* ip;

printf("\nbefore:  ar[0] = %d  ar[1] = %d\n", ar[0], ar[1]);
printf("address of ar is %x\n", ar);

ip = ar;
printf("value at that address is %d\n", *ip);

subr(ar);
printf("after:   ar[0] = %d  ar[1] = %d\n", ar[0], ar[1]);

subr(ar);
printf("after:   ar[0] = %d  ar[1] = %d\n\n", ar[0], ar[1]);


return 0;
}

void subr (int* jp)
{ 

printf("\nsubr says: value of pointer jp is %x\n", jp);
printf("subr says: value at place jp points to is %d\n", *jp);


*jp = *jp + 1;

*(jp+1) = *(jp+1) + 2;

return;
}

/* output:

before:  ar[0] = 10  ar[1] = 20
address of ar is 0xffbefbb8
value at that address is 10

subr says: value of pointer jp is 0xffbefbb8
subr says: value at place jp points to is 10

after:   ar[0] = 11  ar[1] = 22

subr says: value of pointer jp is 0xffbefbb8
subr says: value at place jp points to is 11

finally: ar[0] = 12  ar[1] = 24

*/

