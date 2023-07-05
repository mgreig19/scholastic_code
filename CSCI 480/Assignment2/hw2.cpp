/***********************************************************

 Programmer: Mason Greig
 ID: grei
 Assignment 2

 DUE DATE: 3/2/2018
 DUE TIME: 11:59PM

 FUNCTION: get information from a kernal file using API calls

***********************************************************/

//required libraries for the assignment
#include <sys/utsname.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iomanip>
#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

//forward function declarations for functions used in main()
string getFileData(string fileName);
vector<string> parseVersion(string stringToParse);
void processEnvPath(string fullPath, int& recordCount, int& numOfBytes);

//main program
int main()
	{
		cout << unitbuf;
		//header lines
		string headerA = "\nSECTION A ******************************************\n\n";
                string headerB = "\nSECTION B ******************************************\n\n";
                string headerC = "\nSECTION C ******************************************\n\n";

		//uname instantiation and declaration
		struct utsname apiCall;
		uname(&apiCall);

		//variables for holding the file names
		string osTypeFile, hostNameFile, osReleaseFile, versionFile;
		vector<string> versionStrings, apiStrings;

		osTypeFile = "/proc/sys/kernel/ostype";
		hostNameFile = "/proc/sys/kernel/hostname";
		osReleaseFile = "/proc/sys/kernel/osrelease";
		versionFile = "/proc/sys/kernel/version";

		//variables to hold the retrieved file data
		string osType, hostName, osRelease, version;

		//calls to getFileData to get the required information for the assignment
		osType = getFileData(osTypeFile);
		hostName = getFileData(hostNameFile);
		osRelease = getFileData(osReleaseFile);
		version = getFileData(versionFile);

		//calls to parseVersion, which parse the passed in string into two strings
		versionStrings = parseVersion(version);
		apiStrings = parseVersion(string(apiCall.version));

		//prints the section A header
		cout << headerA;

		//prints the data stored in the strings along with the data retrieved from the api call
		cout << "Field" << setw(24) << "File Data" << setw(30) << "API Data\n";
		cout << "\nostype" << setw(19) << osType << setw(30) << apiCall.sysname;
		cout << "\nhostname" << setw(18) << hostName << setw(30) << apiCall.nodename;
		cout << "\nosrelease" << setw(24) << osRelease << setw(30) << apiCall.release;
		cout << "\nversion" << setw(35) << versionStrings[0] << setw(30) << apiStrings[0] << endl;
		cout << setw(40) << versionStrings[1] << setw(30) << apiStrings[1];
		cout << "\nmachine" << setw(49) << apiCall.machine << endl;

		//printing header section for part B
		cout << headerB;

		//getting full path from call to getenv
		string environmentPath = getenv("PATH");

		//declare and initialize count/accumulator variables
		int entryCount = 0, totalBytes = 0;

		//Prints the full path of the environment being recieved  and the length of the path
		cout << "Full Path:\n" << environmentPath << " " << environmentPath.length() << " bytes.\n\n";
		//column headers
		cout << "PATH:" << setw(33) << "Length:\n\n";

		//call to processEnvPath function, which is being passed the environment path, entryCount, totalBytes
		processEnvPath(environmentPath, entryCount, totalBytes);

		//the total line which displays the total number of bytes in length of the paths processed
		cout << "\nTotal:" << setw(30) << totalBytes << " bytes   " << entryCount << " entrie(s)\n";

		//section C  header
                cout << headerC;

		//ostringstream variable to hold the ps command to be called by the system
		ostringstream psCommand;

		//variable declaration and initialization
		psCommand << "/bin/ps -f --ppid" << " " << to_string(getppid()) << "," << to_string(getpid());
                ostringstream outputPackage;

		//two subsequent forks which create the four proccesses
		int pid1 = fork();
		int pid2 = fork();

		//error check for failed forks
		if(pid1 < 0 or pid2 < 0)
			{
				cerr << "Error: Fork failed.";
				exit(-1);
			}
		//if in original parent/grandparent
		else if(pid1 > 0 and pid2 > 0)
			{
				//clear and set outputPackage to empty
                                outputPackage.clear();
                                outputPackage.str("");
				//add the middle child pid to the ps command ostringstream object
				psCommand << "," << to_string(pid1);
				//package output into outputPackage
				outputPackage << "Parent: My PID is " << getpid() << ".\nMy parent is " << getppid()
				<< ".\nMy children are " << pid1 << " and " << pid2 << ".\n\n";
				//print outputpackage as a c++ string
				cout << outputPackage.str();
				//clear and set outputPackage to empty
                                outputPackage.clear();
                                outputPackage.str("");
				//package output into package
				outputPackage << "Parent: Issuing command: " << psCommand.str() << "\n";
				//print outputPackage as C++ string
				cout << outputPackage.str();
			}
		//if in middle child/second parent
		else if(pid1 == 0 and pid2 > 0)
			{
				//clear and set outputPackage to empty
                                outputPackage.clear();
                                outputPackage.str("");
				//package output into outputPackage
				outputPackage << "Middle: My PID is " << getpid() << ".\nMy parent is "
				<< getppid() << ".\nMy child is " << pid2 << ".\n\n";
				//print the output package as a c++ string
				cout << outputPackage.str();
				//clear and set outputPackage to empty
                                outputPackage.clear();
                                outputPackage.str("");
				//tell process to sleep for 3 seconds
				sleep(3);
				//package output into outputPackage
				outputPackage << "Middle: " << getpid() << " is awake.\n\n";
				cout << outputPackage.str();
				//exit process
				exit(0);
			}
		//if child
		else if((pid1 == 0 and pid2 == 0) or (pid1 > 0 and pid2 == 0))
			{
				//clear and set outputPackage to empty
                                outputPackage.clear();
                                outputPackage.str("");
				//put output into outputPackage
				outputPackage << "Child: My PID is " << getpid()
				<< ".\nMy parent is " << getppid() << ".\n\n";
				//print outputPackage as a c++ string
				cout << outputPackage.str();
				//clear and set outputPackage to empty
				outputPackage.clear();
                                outputPackage.str("");
				//tell the process to sleep for 3 seconds
				sleep(3);
				//put output into outputPackage
				outputPackage << "Child: " << getpid() << " is awake.\n\n";
				//print outputPackage as c++ string
				cout << outputPackage.str();
				//exit process
				exit(0);
			}
		cout << endl;
		//have system execute the psCommand which is passed as a c string
		system(psCommand.str().c_str());
		cout << endl;
		//wait for all processes to complete
		waitpid(-1, 0, 0);
		//sleep for 1 second
		sleep(1);
		//Display message indicating all processes have finished
		cout << "Parent: All processes finished.\n\n";
		//end program success
		return 0;
	}
/*********************************************************************************
 Function: string getFileData(string fileName)

 Use: This function attempts to open the file path string which is passed into the
	method, if the open fails then the program is ended with a return code of -1
	; and if it the open is succesfull then it will read in the file information
	into record, close the file and return the record information obtained.

 Arguments: string fileName: this is the passed in fileName which is represented
				as a string

 Returns: string : the line of the file which contains the information to be used
			in the assignment

*********************************************************************************/
string getFileData(string fileName)
	{
		string record;
		ifstream inFile(fileName);
		if(inFile.fail())
			{
				cout << "ERROR: " << fileName << " failed to open/was not found.\n" << endl;
				exit(-1);
			}
		getline(inFile, record);
		inFile.close();
		return record;
	}
/*********************************************************************************
 Function: vector<string> parseVersion(string stringToParse)

 Use: This function parses the passed in version string and produces two seperate
	strings.

 Arguments: string stringToParse: the larger string to be parsed

 Returns: vector<string> : this vector of strings contains the two sub-strings
				which were produced using the method

*********************************************************************************/
vector<string> parseVersion(string stringToParse)
	{
		string parseString;
		int pos = stringToParse.find("+");
                parseString = stringToParse.substr(0, pos);
                stringToParse = stringToParse.substr(pos, std::string::npos);
		vector<string> twoStrings = {parseString, stringToParse};
		return twoStrings;
	}
/*********************************************************************************

 Function: void processEnvPath(string fullPath, int& recordCount, int& numOfBytes)

 Use: This function takes the path of the environment passed in along with two
	integer reference variables and processes the information by parsing the full path into
	smaller subsequent paths that are displayed along with thier size, the integers are used
	to calculate the number of records processed and the total size sum of the paths.

 Arguments: string fullPath: the full path of the environment that is to be parsed
	    int& recordCount: a reference to the number of records processed
	    int& numOfBytes: a reference to the total size of the path processed

 Returns: Nothing

**********************************************************************************/
void processEnvPath(string fullPath, int& recordCount, int& numOfBytes)
	{
		while(true)
                	{
                                recordCount += 1;
                                size_t pos = fullPath.find(":");
                        	if(pos == std::string::npos)
                                	{
                                        	cout << left << setw(30) << fullPath << right << setw(6) << fullPath.length() << endl;
                                        	numOfBytes += fullPath.length();
                                		break;
                        		}
                        	string subPath = fullPath.substr(pos+1, std::string::npos);
                        	fullPath = fullPath.substr(0, pos);
                        	cout << left << setw(30) << fullPath << right << setw(6) << fullPath.length() << endl;
                        	numOfBytes += fullPath.length();
                		fullPath = subPath;
        		}
		return;
	}
