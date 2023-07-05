// 480/580-1  Spring 2017 BASIC DATA CONVERSION

// Four data representations we have used repeatedly in different
// programs include the following:

// a. integer
// b. C-string, i.e., sequence of Ascii characters with a terminator
// c. C++ String, i.e., member of the String class
// d. sequence of Ascii characters without a terminator

// Make sure you can convert from each of these formats to each of the
// others without using a character-by-character loop.

// There are 8 conversions to consider:
//  1. int -> C++ String
//  2. int -> C-string

//  3. C++ String -> C-string
//  4. C-string -> C++ String

//  5. C++ String -> int
//  6. C-string -> int

//  7. C-string -> char array without terminator
//  8. char array without terminator -> C-string

// SAMPLE QUESTIONS: Write code for the functions below
// You will NOT receive credit if you use a character by character loop.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

string int2cpp  (int);                 // 1. convert int to C++ string
void   int2c (int, char[]);            // 2. convert int to C-string

void   cpp2c (string, char[]);         // 3. convert C++ string to C-string
string c2cpp (char[]);                 // 4. convert C-string to C++ string

int    cpp2int (string);               // 5. convert C++ string to int
int    c2int (char[]);                 // 6. convert C-string to int

// note: in the functions below, the first argument is the 'from'
// data structure and the second is the 'to'
void   c2t (char[], char[]);     // 7. convert C-string to char array w/o term
void   t2c (char[], char[]);     // 8. convert char array w/o term to C-string


int main(int argc, char * argv[])
{
  string s1("1234");
  string s3;
  string s4;

  char xy[10] = "567";
  char qq[10];
  char ca1[10];
  char ca2[10];
  char ct1[10];
  char ct2[10];
  
  int j;
  int k;

  // You will get credit if your code WORKS in the GENERAL CASE (i.e., not
  // just for these specific examples) and does NOT use any character by
  // character processing. (You can update ONE character; you just can't
  // update an entire string one character at a time.)

  // If you write the code for pratice, make sure to add some print statements
  // in the driver so that you know your code works.

  // Make sure your code does what is required, i.e., updates the correct
  // argument or returns a value of the correct type. Notice that none of
  // these functions asks you to print anything.

  
  s4 = int2cpp(42);                          // #1
  int2c(42, ca1);                            // #2

  cpp2c(s1, qq);                             // #3
  s3 = c2cpp(xy);                            // #4

  j  = cpp2int(s1);                          // #5
  k  = c2int(xy);                            // #6

  strncpy(ct2, xy, 2);
  c2t(xy, ct1);                              // #7
  t2c(ct2, ca2);                             // #8

  return 0;

}
