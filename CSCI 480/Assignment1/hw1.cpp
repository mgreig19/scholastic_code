/****************************************

 Programmer: Mason Greig
 id: grei
 Assignment: 1

 Due Date: 2/19/2018
 Due time: 11:59 pm

 Function: This program reads in a virtual file(s), parses the information,
	   stores the information in the Processor class object, and answers
	   the questions which are provided in the homework document.

****************************************/


//These libraries are included to ensure the proper functioning of the program
#include <vector>
#include <forward_list>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <fstream>
#include "Processor.h"

//Symbolic constants used for calculations
#define TWO 2
#define THOUSAND 1000
#define HOURS_IN_DAY 24
#define MINUTES_IN_HOUR 60
#define SECONDS_IN_MINUTE 60

//main program start
int main (int argc, char* argv[]){

	//create two input file variables
	ifstream inFile, timeFile;

	//If the program is passed a file in the argument then used the passed in file
	if(argc > 1){

	 	inFile.open(argv[1], ios::in);
	}
	//If no arguments, open default file
	else{
		inFile.open("/proc/cpuinfo", ios::in);
	}
	//open file containing cpu up time information for use in answering part D
	timeFile.open("/proc/uptime", ios::in);

	//if the open to either file fails then print an error message and exit
	if (inFile.fail() or timeFile.fail()){	//test for failure to open file

		cerr << "Error! The input file did not open/was not found.!" << endl;
		exit(-1);
	}

	//various variables being utilized in the program
	string whiteSpaces(" \t\n\r\v");
	string record, key, value, sharedCache, stringToInt, physicalAddress, virtualAddress, cacheString;
	std::string::size_type sz;
	forward_list<string> uniqueCount;
	vector<Processor*> processorList;
	bool firstLine = true;
	bool cacheShared = false;
	double cpuUpTime = 0.0;
	int recordCount = 0;
	double physicalSize, virtualSize, ratio;
	int cacheSize;
	int characterCount = 0;
	int genericCount = 0;
	size_t pos, endOfString, startOfString;

	//get the first line of the file
	getline(inFile, record);

	//while there is information in the file, keep looping
	while(inFile){

		//create a pointer to a processor object
		Processor* processor;

		//process count values while the file is being read
		recordCount += 1;
		characterCount += (record.length() + 1);

		//if the record is empty, store the pointer to the processor object into the vector of poiters and set firstLine variable to true
		if(record == ""){

                	processorList.push_back(processor);
                        firstLine = true;
                }
		else{
			//find the position of the delimiter
			pos = record.find(":");
			//assign key value based on pos; assign value to value based on pos+1 and npos
               		key = record.substr(0, pos);
			value = record.substr(pos+1, std::string::npos);
			//find the last non-whitespace value in key
               		endOfString = key.find_last_not_of(whiteSpaces);

               		if(endOfString != std::string::npos){
				//erase the part of the key string which contains whitespaces if not npos
                        	key.erase(endOfString + 1);
       	        	}
			//test to determine if a new processor object should be made
			if(firstLine == true and key == "processor"){

				processor = new Processor();
				firstLine = false;
			}
			//if the string value is not empty then process the string to be parsed and assigned back to string value 
			if(value != ""){

			 	startOfString = value.find_first_not_of(whiteSpaces);
				value = value.substr(startOfString, std::string::npos);
			}
			//place the key, value pair into the processor object
			processor->addProcessor(key, value);
		}
		//get the next line in the file
		getline(inFile, record);
	}
	//close the inFile stream
	inFile.close();

	//beginning of questions
	cout << "\nA: Questions about the cpuinfo file.\n" << endl;


	cout << "\t1. What is the name of the file you are reading? " << endl;

	//the answer to the question is determined by whether an argument was oassed to main
	if(argv[1] == NULL){

		cout << "\t\tThe name of the file being read in is /proc/cpuinfo\n" << endl;
	}
	else{

		cout << "\t\tThe name of the file being read in is " << argv[1] << "\n" << endl;
	}

	//questin 2 and 3 are answered through the use of the counters in the inFile read loop
	cout << "\t2. How many records are there in that file? " << endl;
	cout << "\t\tThere are " << recordCount << " records in the file.\n" << endl;
	cout << "\t3. How many characters are in that file? " << endl;
	cout << "\t\tThere are " << characterCount << " characters in the file.\n" << endl;

	//This question is answered by listing the utility I used to check the above answers
	cout << "\t4. Which system utility or utilities did you use to verify that your answers to 2 and 3 are correct? " << endl;
	cout << "\t\tI used the system utility: wc -l -c\n" << endl;

	cout << "\nB: Questions about configuration\n" << endl;

	//provides a count of the number of processors stored in the Processor being pointed to by the vector of pointers
	for(Processor* ptr : processorList){
		genericCount += ptr->countStuff("processor");
	}
	cout << "\t1. How many processors (total cores) does the machine have? " << endl;
	cout << "\t\tThe machine has " << genericCount << " processors.\n" << endl;

	//resetting the count variable for reuse
	genericCount = 0;

	//stores the physical id's of the cores into a forward list
	for(Processor* ptr : processorList){

                uniqueCount.push_front(ptr->getValueForKey("physical id"));
        }
	//erases duplicates
	uniqueCount.unique();
	//sets count variable to the number of unique physical id's foudn
        for(string& value: uniqueCount){
                genericCount += 1;
        }

	//use count variable to answer question
	cout << "\t2. How many physical CPUs? " << endl;
	cout << "\t\tThe machine has " << genericCount << " physical cpus.\n" << endl;

	cout << "\t3. What are the physical ids? " << endl;
	cout << "\t\tThe physical id's are ";
	//question is answered through the use of printing the number's of the physical id's
	if(genericCount > 0){

		for(int i = 0; i < genericCount; i++){
			cout << i << " ";
		}
	}
	//if no physical id's are found will print none
	else{
		cout << "None.";
	}
	cout << "\n" << endl;


	cout << "\t4. Are there any processors that share L2 cache? " << endl;
	//store's the value of the cache size of the first processor
	sharedCache = processorList[0]->getValueForKey("cache size");

	//compare's the first cache size to the other processor's to determine if cache is shared
	for(Processor* ptr : processorList){

		if(sharedCache == ptr->getValueForKey("cache size")){
			cacheShared = true;
		}
	}
	//prints out a message based on whether shared cache is found
	if(cacheShared == true){
		cout << "\t\tYes, there are processors that share L2 cache.\n" << endl;
	}
	else{
		cout << "\t\tNo, there are not processors that share L2 cache.\n" << endl;
	}

	cout << "\nC: Questions about the first processor in the file\n" << endl;
	//this piece of code parses the address sizes key field to be split into seperate physical and virtual variables
	stringToInt = processorList[0]->getValueForKey("address sizes");
        //parsing the physical address size out of the larger string
	pos = stringToInt.find(",");
        physicalAddress = stringToInt.substr(0, pos);
        endOfString = physicalAddress.find_first_of(whiteSpaces);
	//removes extra whitespaces from the variable
        if(endOfString != std::string::npos){

                physicalAddress.erase(endOfString);
        }
	//this piece of code parses out the virtual address size of the larger string
	virtualAddress = stringToInt.substr(pos+1, std::string::npos);
	startOfString = virtualAddress.find_first_not_of(whiteSpaces);
	virtualAddress = virtualAddress.substr(startOfString, std::string::npos);
	endOfString = virtualAddress.find_first_of(whiteSpaces);

	//removes extra whitespace from the variable
	if(endOfString != std::string::npos){

                virtualAddress.erase(endOfString);
        }

	//answering the question with the new parsed physical address size
	cout << "\t1. What is the physical address size? " << endl;
	cout << "\t\tThe physical address size of the first processor is " << physicalAddress << " bits.\n" << endl;
	//answering the question with new parsed virtual address size
	cout << "\t2. What is it's virtual address size? " << endl;
	cout << "\t\tThe virtual address size of the first processor is " << virtualAddress << " bits.\n" << endl;

	//the next two lines convert the previous variables from strings to doubles
	physicalSize = stod(physicalAddress, &sz);
	virtualSize = stod(virtualAddress, &sz);

	//this line of code calculates the ratio of virtual to physical address size
	ratio = pow(TWO, (virtualSize - physicalSize));
	cout << "\t3. What is the ratio of virtual address size to physical address size? " << endl;
	//answering the question using the ratio variable value
	cout << "\t\tThe ratio of virtual address size to physical address size is: " << ratio << "\n" << endl;

	cout << "\t4. Does it have a floating point unit? " << endl;
	//a decision statement which checks the value of the key field fpu which  determines if the machine has a floating point unit
	if((processorList[0]->getValueForKey("fpu")) == "yes"){

		cout << "\t\tYes, the machine does have a floating point unit.\n" << endl;
	}
	else{

		cout << "\t\tNo, the machine does not have a floating point unit.\n" << endl;
	}
	//answered by retrieving the value stored at the cache size key of the first processor
	cout << "\t5. How big is the level 2 cache in KB? " << endl;
	cout << "\t\tThe level 2 cache is " << processorList[0]->getValueForKey("cache size") << ".\n" << endl;

	//this block of code parses the KB out of the key field value stored in key: cache size
	stringToInt= processorList[0]->getValueForKey("cache size");
        pos = stringToInt.find(" ");
        cacheString = stringToInt.substr(0, pos);
        endOfString = cacheString.find_first_of(whiteSpaces);

	//removes the whitespace of the cache size variable
	if(endOfString != std::string::npos){

                cacheString.erase(endOfString);
        }

	//converts the string in cacheSize to an int
	cacheSize = stoi(cacheString, &sz);
	//calculates the cache size in bytes using a symbolic constant
	cacheSize = cacheSize * THOUSAND;
	cout << "\t6. How big is the level 2 cache in bytes? " << endl;
	//answering the question using the calculated chacheSize in bytes
	cout << "\t\tThe level 2 cache can also be represented as " << cacheSize << " bytes.\n" << endl;

	//get the line from the cpuUptime virtual file
	getline(timeFile, record);
	//parse out the first value stored in the virtual file
	endOfString = record.find_first_of(whiteSpaces);
	stringToInt = record.substr(0,endOfString);
	//convert parsed value in stringToInt to a double
	cpuUpTime = stod(stringToInt, &sz);

	//close the virtual file
	timeFile.close();
	cout << "\nD: Questions about uptime\n" << endl;
	cout << "\tHow long has it been up in seconds? " << endl;
	//prints out the double representation of the string which is the number in seconds of machine uptime
	cout << "\t\tThe machine has been up for " << stringToInt << " seconds.\n" << endl;

	//calculations to determine the number of days, hours, minutes, and seconds which can
	//be allocated using the number of cpuUpTime seconds
	int minutes = cpuUpTime / SECONDS_IN_MINUTE;
	double seconds = cpuUpTime - (minutes * SECONDS_IN_MINUTE);
	int hours = minutes / MINUTES_IN_HOUR;
	minutes = minutes - (hours * MINUTES_IN_HOUR);
	int days = hours / HOURS_IN_DAY;
	hours = hours - (days * HOURS_IN_DAY);

	//answers the question using the newly reformatted cpu Up time values
	cout << "\tExpress that time in days, hours, minutes, and seconds; to the nearest tenth of a second: " << endl;
	cout << "\t\tThe system has been running for " << days << " days, " << hours << " hours, " << minutes << " minutes, and " << fixed << setprecision(1) << seconds << " seconds.\n" << endl; 
	//end of main program
	return 0;
}
