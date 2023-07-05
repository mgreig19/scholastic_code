//*****************************************************************
// FILE:      Verifier.h
// AUTHOR:    Mason Greig
// LOGON ID:  z1768935
// DUE DATE:  9/23/2016
//
// PURPOSE:   Contains the declaration for the Verifier class.
//*****************************************************************
#ifndef VERIFIER_H						//class guard
#define VERIFIER_H

#include <string>
#include <iomanip>
#include <cstdlib>						//libraries to be included for program
#include <iostream>
#include <fstream>

#define NUMROW 9
#define NUMCOL 9						//symbolic constants which hold the values for the dimensions of the grid
#define SUBSEC 3

using std::cout;
using std::endl;
using std::cerr;

class Verifier
{
	private:
		int grid[NUMROW][NUMCOL] = {{0}};		//private data members
		bool found[9] = {false};
	public:
		Verifier();
		void readGrid(const char* sudoku);		//public methods to access the data members(method descriptions are available in Verifier.cpp)
		bool foundIn(int);
		void printGrid();
		bool verifySolution();
		void setFound();
};
#endif								//end class guard
