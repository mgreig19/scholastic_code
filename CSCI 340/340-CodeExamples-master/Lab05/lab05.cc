#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <ostream>
#include <time.h>

const int VECTOR_LENGTH = 5;
const int HIGH = 99;
const int LOW = 0;

using namespace std;

int bubblesort(vector<int> data, const int);

namespace Color {
    enum Code {
    	RESET				= 0,
    	BOLD				= 1,
    	UNDERLINE			= 4,
    	BLINK				= 5,
    	INVERT				= 7,
    	HIDDEN				= 8,
    	FG_BLACK			= 30,
        FG_RED      		= 31,
        FG_GREEN   	 		= 32,
        FG_YELLOW			= 33,
        FG_BLUE     		= 34,
        FG_MAGENTA			= 35,
        FG_CYAN				= 36,
        FG_LIGHT_GRAY		= 37,
        FG_DARK_GRAY		= 90,
        FG_LIGHT_RED		= 91,
        FG_LIGHT_GREEN		= 92,
        FG_LIGHT_YELLOW		= 93,
        FG_LIGHT_BLUE		= 94,
        FG_LIGHT_MAGENTA	= 95,
        FG_LIGHT_CYAN		= 96,
        FG_WHITE			= 97,
        FG_DEFAULT  		= 39,
        BG_RED      		= 41,
        BG_GREEN    		= 42,
        BG_BLUE     		= 44,
        BG_DEFAULT  		= 49
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}

int
main()
{
	srand(time(NULL));
	vector<int> a(VECTOR_LENGTH);

	for(int i=0;i<VECTOR_LENGTH;++i)
		a[i] = (rand() % (HIGH - LOW + 1) + LOW);

	for(int i=0;i<VECTOR_LENGTH;++i)
		cout << setfill('0') << setw(2) << a[i] << " ";
	cout << endl;
	cout << endl;

	bubblesort(a,VECTOR_LENGTH);

}

int
bubblesort(vector<int> data, const int n)
{
	Color::Modifier red(Color::BG_RED);
    Color::Modifier green(Color::BG_GREEN);
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier fdef(Color::FG_DEFAULT);
    Color::Modifier bdef(Color::BG_DEFAULT);
    Color::Modifier bold(Color::BOLD);
 
 	int k = 0;
 	int swapped = 0;

    for(int i = 0; i < n-1; i++)
    {
    	k = n -1;
    	for(int j = n-1; j > i; --j)
    	{
			if(data[j] < data[j-1])
			{
				swap(data[j], data[j-1]);
				swapped = 1;
			}
			if(swapped)
			{
				for(k=0;k<VECTOR_LENGTH;++k)
				{
					if(k == i)
						cout << "\e[5m";
					
					if(k == j)
					{
						cout << red << bold << setfill('0') << setw(2) << data[k];
						cout << bdef << " ";
					}
					else if(k == (j-1))
					{
						cout << green << "\e[1m" << setfill('0') << setw(2) << data[k];
						cout << bdef << " ";
					}	
					else
						cout << fdef << "\e[0m" << setfill('0') << setw(2) << data[k] << " ";
				}// End of FOR
				swapped = 0;
				cout << endl;
			}// End of IF
			else
			{
				for(k=0;k<VECTOR_LENGTH;++k)
				{
					if(k == j)
						cout << blue << "\e[1m" << setfill('0') << setw(2) << data[k] << " ";
					else if(k == (j-1))
						cout << blue << "\e[1m" << setfill('0') << setw(2) << data[k] << " ";
					//else if(k == i)
					//	cout << "   ";
					else
						cout << fdef << "\e[0m" << setfill('0') << setw(2) << data[k] << " ";
				}// End of FOR
				swapped = 0;
				cout << endl;
			}

    	}
    }
    cout << fdef << bdef << endl;
    return 0;

}// End of bubblesort(data[], int n)