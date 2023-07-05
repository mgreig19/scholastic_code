/****************************************************************
   PROGRAM:   Numerology Assignment 1
   AUTHOR:    Mason Greig
   LOGON ID:  Z1768935
   DUE DATE:  9/8/2016

   FUNCTION:  associates a set of personality traits with a numerical value
     	      that is generated from the user inputingn their name.

   INPUT:     standard input

   OUTPUT:    Displays a set of personality traits associated with the numeric
	      value of the user's name.

   NOTES:    none
****************************************************************/
#include <cmath>
#include <string.h>
#include <cstdlib>
#include <iostream>									// libraries which are required for the program
#include <iomanip>
#include <cctype>

#define PAUSE cout << "Press enter to continue.\n "; cin.ignore(); 			//symbolic constant to pause the program before returning 0

using namespace std;									// namespace required to make variables
// using std::cout; and using std::endl; using std::cin *Alternative to using namespce: become familiar with this to avoid point loss

char userName[100];									// char array which holds the user's name
char userChoice[10];									// char array which holds the char for userChoice
int nameLgth;										//valuable which holds the length of a char array
int NameValue;										//holds the value for the numeric value which is returned by NameConver(char [],int)

int NameConvert(char name[], int nameLgth);						//method prototypes
void Numerology(int NameValue);

int main()
        {
                cout << "Numerology Program" << endl;                   		// Display's the program title
                do                                     					// Start of the Do-while loop to contain the program and allow for repeat entries
                        {
                                cout << "\nPlease enter a name: ";      		// Prompts the user to enter their name
                                cin.getline(userName, 100);             		// retrieves the contents of the char array userName
                                nameLgth = strlen(userName);            		// retrieves the numeric length of the char array userName
                                NameValue = NameConvert( userName, nameLgth);   	//Assigns the numeric  value returned from the function NameConvert(char[].int)
                                Numerology( NameValue );        			// calls the program  Numerology(int)
                                cout << "\nEnter another name? (y/n): "; 		//prompts the user for another name entry
                                cin.getline(userChoice, 10);    			// retrieves the char that was entered into userChoice
                        }
                while (userChoice[0] == 'Y' or userChoice[0] == 'y');			// end of do-while loop which is checking the char value of userChoice

                return 0;								// end of program
    	}
/*********************************************************************************
Function: int NameConvert(char [] , int)

Use: converts the user name char array into a numeric value that is returned

Arguments: int: the length of the char array that the user entered
	   char []: the char array that holds the user's name

Returns: int: a numeric value for the user's name char array
**********************************************************************************/

int NameConvert(char name[], int nameLgth)
	{
		int chval = 0;
		unsigned  i;
		char reConvert[100];

		for (i = 0; i <  nameLgth; i++)
			{
				if (isalpha(name[i]))
					{
						chval += tolower(name[i]) - 'a' + 1;
					}
				else if (isdigit(name[i]))
					{
						chval += name[i] - '0';
					}
			}
		while ((chval >= 13 and chval <= 21) or chval == 10 or chval >= 23)
			{
				i = 0;
				while (chval > 0)
					{
						i += chval%10;
						chval /= 10;
					}
				chval = i;
			}
		return chval;
	}
/********************************************************************************************
Function: void Numerology ( int )

Use: Reads in the value from function int NameConvert(string, int), the user's numeric namevalue, and displays a list of personlity traits which are associated with that value

Arguments: int: the numeric value which is obtained from the function Nameconvert(string, int)

Returns: nothing
*******************************************************************************************/
void Numerology( int NameValue )
	{
		char zero[] = " emptiness, nothingness, blank";
		char one[] = " independence, loneliness, creativity, originality, dominance, leadership, impatience";
		char two[] = " quiet, passive, diplomatic, co-operation, comforting, soothing, intuitive, compromising, patient";
		char three[] = " charming, outgoing, self expressive, extroverted, abundance, active, energetic, proud";
		char four[] = " harmony, truth, justice, order, discipline, practicality";
		char five[] = " new directions, excitement, change, adventure";
		char six[] = " love, harmony, perfection, marriage, tolerance, public service";
		char seven[] = " spirituality, completeness, isolation, introspection";
		char eight[] = " organization, business, commerce, new beginnings";
		char nine[] = " romantic, rebellious, determined, passionate, compassionate";
		char eleven[] = " idealism, visionary, inspirational";
		char twelve[] = " perfectionist, discriminating";
		char twentytwo[] = " builder, leader, humanitarian, practical, honest";

		cout << "\nThat name has the traits";
		if ( NameValue == 0)
			{
				cout << zero << "\n" << endl;
			}
		else if (NameValue == 1)
			{
				cout << one << "\n" << endl;
			}
		else if (NameValue == 2)
			{
				cout << two << "\n" << endl;
			}
		else if (NameValue == 3)
			{
				cout << three << "\n" << endl;
			}
		else if (NameValue == 4)
			{
				cout << four << "\n" << endl;
			}
		else if	(NameValue == 5)
			{
				cout << five << "\n" << endl;
			}
		else if (NameValue == 6)
			{
				cout << six << "\n" << endl;
			}
		else if (NameValue == 7)
			{
				cout << seven << "\n" << endl;
			}
		else if (NameValue == 8)
			{
				cout << eight << "\n" << endl;
			}
		else if (NameValue == 9)
			{
				cout << nine << "\n" << endl;
			}
		else if (NameValue == 11)
			{
				cout << eleven << "\n" << endl;
			}
		else if (NameValue == 12)
			{
				cout << twelve << "\n" << endl;
			}
		else if (NameValue == 22)
			{
				cout << twentytwo << "\n" << endl;
			}
	}
