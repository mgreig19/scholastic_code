
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <iomanip>

using namespace std;


/* strptr1c.cpp  */

/* shows strings represented in memory as char array + terminator
   shows printf printing string instead of address for char array     */

int main()
{

char ar[10] = "wxyz";

printf("The string %s has length %d\n\n", ar, strlen(ar));

/* Let's give the string a new value
   Why can't we say this?  ar = "abcde"  */

strcpy(ar, "abcde");
printf("The string %s has length %d\n\n", ar, strlen(ar));


/* We can make the string shorter too  */

strcpy(ar, "qq");
printf("The string %s has length %d\n\n", ar, strlen(ar));


/* Let's violate data abstraction (NOT recommended)  */

ar[2] = 'z';
printf("The string %s has length %d\n\n", ar, strlen(ar));

return 0;
}

/* output:

The string wxyz has length 4

The string abcde has length 5

The string qq has length 2

The string qqzde has length 5

*/

