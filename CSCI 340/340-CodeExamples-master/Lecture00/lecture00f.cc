#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

int
main(int argc, char *argv[])
{
	int age = 0;
	cout << "Please enter your age: ";
	cin >> age;

	int dayage = age*365;

	cout << endl << "You are at least " << dayage << " days old." << endl;

	// change the notation, oct puts cout in octal form, hex puts cout in hex form
	cout << "In octal: " << oct << dayage << " hex: " << hex << dayage << dec << endl;

	bool on = 1;
	bool off = 0;

	// boolalpha prints out boolean variables in alpha form versus 0 and 1
	cout << endl << "On " << on << " Off " << off << boolalpha << " On " << on << " Off " << off << endl;

	long double a = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;
	cout << a << " ";
	cout << setprecision(5); // sets precision to 5
	cout << a << " " << cout.precision() << endl; // prints out shortened value for "a" prints out precision

	int b[] = {234, 242, 294, 953, 34, 349, 204, 23};
	int k = 0;

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 2; j++)
			cout << b[k++];
		cout << endl;
	}

	cout << "123456123456" << endl;
	k = 0;

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 2; j++)
			cout << setw(6) << b[k++];
		cout << endl;
	}

	cout << "123456123456" << endl;
	k = 0;
	cout << left;

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 2; j++)
			cout << setw(6) << b[k++];
		cout << endl;
	}

	cout << "123456123456" << endl;
	k = 0;
	cout << right << setfill('?');

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 2; j++)
			cout << setw(6) << b[k++];
		cout << endl;
	}


	string s = "The quick brown fox jumps over the lazy dog!";
	cout << s << endl;
	std::transform(s.begin(), s.end(), s.begin(), std::ptr_fun<int, int>(std::toupper));
	cout << s << endl;

}