//*****************************************************************
// FILE:      Processor.h
// AUTHOR:    Mason Greig
// ID:        grei
// DUE DATE:  2/20/2018
//
// PURPOSE:   Contains the declaration of Processor class
//*****************************************************************
#ifndef PROCESSOR_H
#define PROCESSOR_H
#include <string>
#include <unordered_map>

using namespace std;

class Processor{

	private:

		unordered_map<string, string> processorInfo;

	public:

		Processor();
		void addProcessor(const string& key, const string& value);
		void printProcessors();
		const string& getValueForKey(const string& key);
		int countStuff(const string& key);
};

#endif
