/*****************************************************************
 FILE:      Processor.h
 AUTHOR:    Mason Greig
 ID:        grei
 DUE DATE:  2/20/2018

 PURPOSE:   Contains the method definitions of Processor.h (class)
*****************************************************************/
#include "Processor.h"
#include <iostream>

/****************************************************************
 Default Constructor

	Arguments: None
	Reuturns: N/A

*****************************************************************/
Processor::Processor(){
}
/****************************************************************

 Method: void add(const std::string& key, const std::string& value)

 Arguments: const std::string& key, const std::string& value: the key value pair to be stored in the unordered map

 Returns: nothing, just adds a new element to the map

****************************************************************/
void Processor::addProcessor(const string& key, const string& value){

	processorInfo[key] = value;

}
/****************************************************************

 Method: const std::string& getValueForKey(const std::string& key)

 Arguments: const std::string& key: the key to be found in the map

 Returns: constant reference to a string, which holds the value of the passed in key

****************************************************************/
const string& Processor::getValueForKey(const string& key){

	return processorInfo[key];

}
/**************************************************************

 Method: int Processor::countStuff(const string& key)

 Arguments: const string& key: the key which is to be counted

 Returns: the number of occurences which were found of the passed in key

**************************************************************/
int Processor::countStuff(const string& key){

		return processorInfo.count(key);
}
/**************************************************************

 Method: void printProcessor()

 Arguments: none

 Returns: nothing

**************************************************************/
void Processor::printProcessors(){

	for(auto itr = processorInfo.begin(); itr != processorInfo.end(); ++itr){
		if(itr->first == "processor"){
                        cout << "\n";
                }
		cout << itr->first << " : " << itr->second << endl;
	}
}
