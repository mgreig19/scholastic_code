#include <fstream>
#include "Verifier.h"

using std::ifstream;

/***********************************************************
Function:Verifier::verifySolution();

Use:verifies that the solution to the sudoku grid is correct

Arguments:none

Returns:bollean:returns true if correct and false if incorrect
************************************************************/
bool Verifier::verifySolution()
{
	for(int row = 0; row < NUMROW; row++)					// loop to cycle through the rows checking for whether or not the number 1 - 9 has been found only one time.
		{
			setFound();						// calls setFound() which sets boolean array to false for each new row check
			for(int column = 0; column < NUMCOL; column++)
				{
					if (foundIn(grid[row][column]))		// checks if the value in the 2-d array subscript is in the found array and if it is foudn then the decision statement returns false to communicate an invalid solution
						{
							return false;
						}
				}
		}
	for(int column = 0; column < NUMCOL; column++)				// loop to cycle through the columns checking for whether or not the number 1 - 9 has been found only one time.
		{
			setFound();						// calls setFound() which sets boolean array to false for each new column check
			for(int row = 0; row < NUMROW; row++)
				{
					if (foundIn(grid[row][column]))		// checks if the value in the 2-d array subscript is in the found array and if it is foudn then the decision statement returns false to communicate an invalid solution
						{
							return false;
						}
				}
		}
	for(int subRow = 0; subRow < SUBSEC; subRow++)											// loop which sets the value and cycles through for the number of sub rows in the sub section grids in the 2-d array
		{
			for(int subCol = 0; subCol < SUBSEC; subCol++)									//loop to cycle through the sub column sub section of the 2-d array
				{
					setFound();											// calls setFound() which sets boolean array to false for each new sub check
					for(int row = subRow * SUBSEC; row < subRow * SUBSEC + SUBSEC; row++)				//loop which cycles through each row within the current sub section
						{
							for(int column = subCol * SUBSEC; column < subCol * SUBSEC + SUBSEC; column++)	//loop which cycles through each column within the current sub section
								{
									if (foundIn(grid[row][column]))					// checks if the value in the 2-d array subscript is in the found array and if it is foudn then the decision statement returns false to communicate an invalid solution
										{
											return false;
										}
								}
						}
				}
		}
	return true;															//returns true if all other conditions as outlined above have passed, this indicates a valid sudoku soltion
}
/*******************************
Function:Verifier::setFound();

Use: method which sets the boolean array to false in preparation for a new part of the grid to be checked against

Arguments:none

Returns:none
********************************/
void Verifier::setFound()
{
	for(int column = 0; column < NUMCOL; column++)		//loops through boolean array setting all elements to false in prep for next testing
		{
			found[column] = false;
		}
}
/*******************************
Function:bool Verifier::foundIn(int sudoku[Row][Column]);

Use: compares the value of the specified 2-d array subscript to the value of the boolean array and sets it to true if the number is equal; it also will return false if a number is repeated.

Arguments:int sudoku: 2-d array which is passing the sudoku values in for checking

Returns:boolean: whether or not the check was valid or invalid; success or none success
********************************/
bool Verifier::foundIn(int sub)
{
	sub--;
	if(found[sub] == false)
		{
			found[sub] = true;
			return false;
		}
	else
		{
			return true;
		}
}
/*******************************
Function:Verifier::printGrid();

Use: method which prints out the sudoku grid and an outline of the outer grid along with an outline of the subsections

Arguments:none

Returns:none
********************************/
void Verifier::printGrid()
{
	for (int row = 0; row < NUMROW; row++)								//loops through every row
		{
			if (row == 0 or (row % 3) == 0)							//if row number is 0,3, 6 etc.. print a border
				{
					std::cout << "-------------------------" << std::endl;
				}
			for(int column = 0; column < NUMCOL; column++)					//loops through every column
				{
					if (column == 0 or (column % 3) == 0)				//if column num is 0,3, 6 etc print a border
						{
							std::cout << "| ";
						}
					std::cout << grid[row][column] << " ";				//cout value of grid with a space after it
					if(row <= 8 and column == 8)					//if row and column number are equal to 8 then print the closing right border
						{
							std::cout << "|";
						}
					if (row == 8 and column == 8)
						{
							std::cout << std::endl << "-------------------------";	//if row and column number are equal to 8 then print a closing bottom border
						}
				}
			std::cout << std::endl;
		}
}
/*******************************
Function:Verifier::readGrid(const char* newLibrary);

Use:reads in the sudoku grids from an external file

Arguments: const char*:a sudoku grid to be read in from a txt file

Returns:nothing
********************************/
void Verifier::readGrid(const char* sudoku)
{
        std::ifstream inFile;
        inFile.open(sudoku);
        if (inFile.fail())
                {
                        std::cerr << "Error! The input file did not open properly!" << std::endl;		//error message incase open input file fails
                        exit(-1);
                }
        else
                {
			for(int row = 0; row < NUMROW; row++)
				{
                        		for(int column = 0; column < NUMCOL; column++)
						{
							inFile >> grid[row][column];				//loop to read in input file data into the 2-d array to hold the sudoku solution
						}
				}
                }
        inFile.close();												//closes file
}
/*******************************
Function:Verifier::Verifier();

Use:default constructor

Arguments: none

Returns: none
********************************/
Verifier::Verifier()
{
}
