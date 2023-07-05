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
#include <cstdlib>
#include <iostream>								// libraries required for program
#include <iomanip>
#include <cctype>
#include <cstring>

#define PAUSE cout << "Press enter to continue.\n "; cin.ignore();		//symbolic constant that pauses the program before exiting

using namespace std; 								// namespace required for variables

string userName, name;								// string which holds the name that the user entered
string userChoice; 								// string which holds the value of the User's decision to continue the program
int nameLgth;									// variable  whihc holds the length of a char array
int NameValue; 									// holds the value for the numeric value which is returned by NameConvert(char[], int)

int NameConvert(string name, int nameLgth);					// method prototypes
void Numerology(int NameValue);

int main()
	{
		cout << "Numerology Program" << endl;				// Display's the program title
		do								// Start of the Do-while loop to contain the program and allow for repeat entries
			{
				cout << "\nPlease enter a name: ";		// Prompts the user to enter their name
				getline(cin, userName);				// retrieves the contents of the char array userName
				nameLgth = userName.length();			// retrieves the numeric length of the char array userName
				NameValue = NameConvert( userName, nameLgth);	//Assigns the numeric  value returned from the function NameConvert(char[].int)
				Numerology( NameValue );			// calls the program  Numerology(int)
				cout << "\nEnter another name? (y/n): ";	//prompts the user for another name entry
				getline(cin, userChoice);			// retrieves the char that was entered into userChoice

			}
		while (userChoice == "Y" or userChoice == "y");			// end of do-while loop which is checking the char value of userChoice

		return 0;							// end of program

	}
/*********************************************************************************
Function: int NameConvert(string , int)

Use: converts the user name string into a numeric value that is returned

Arguments: int: the length of the string that the user entered
	   string: the user entered string  that holds the user's name

Returns: int: a numeric value for the user's name string
**********************************************************************************/

int NameConvert(string name, int nameLgth)
	{
		int chval = 0;
		int i;
		string reConvert;

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
				reConvert = to_string(chval);
				chval = 0;
				for (i = 0; i <= nameLgth; i++)
					{
						if (isdigit(reConvert[i]))
							{
								chval += reConvert[i] - '0';
							}
					}
			}
		return chval;
	}
/********************************************************************************************
Function: void Numerology ( int )

Use: Reads in the value from  function int NameConvert(string, int), the user's numeric name value, and displays a list of personlity traits which are associated with that value 

Arguments: int: the numeric value which is obtained from the function Nameconvert(string, int)

Returns: nothing
*******************************************************************************************/
void Numerology( int NameValue )
	{
		string zero, one, two, three, four, five, six, seven, eight, nine, eleven, twelve, twentytwo;

		zero = " emptiness, nothingness, blank";
		one = " independence, loneliness, creativity, originality, dominance, leadership, impatience";
		two = " quiet, passive, diplomatic, co-operation, comforting, soothing, intuitive, compromising, patient";
		three = " charming, outgoing, self expressive, extroverted, abundance, active, energetic, proud";
		four = " harmony,truth, justice, order, discipline, practicality";
		five = " new directions, excitement, change, adventure";
		six = " love, harmony, perfection, marriage, tolerance, public service";
		seven = " spirituality, completeness, isolation, introspection";
		eight = " organization, business, commerce, new beginnings";
		nine = " romantic, rebellious, determined, passionate, compassionate";
		eleven = " idealism, visionary, inspirational";
		twelve = " perfectionist, discriminating";
		twentytwo = " builder, leader, humanitarian, practical, honest";

		cout << "\nThat name has the traits ";
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
