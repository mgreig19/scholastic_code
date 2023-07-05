/******************************************
Program: Assignment7: Changing permissions and adding to a file with no permissions

Author: Mason Greig

ZID: z1768935

Due date: 11/04/16

Purpose: become familiar with low level system calls
******************************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <unistd.h>								//the required libraries for the program to run
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

int main(int argc, char* argv[])						//main program takes arguments
{
	int inFileD;
	char *buffer, *fileName;						//variable declarations
	if(argc == 4)
		{
			fileName = argv[2];
			buffer = argv[3];
		}
	else									//variable initialization
		{
			buffer = argv[2];
			fileName = argv[1];
		}
	if (argc < 2 or argc > 4)						//if the number of arguments passed to main is < 2 or >= 4 then print a usage error message and exit
		{
			cerr << "Usage:  seclog [-c] out_file message_string\n" << "\twhere the message_string is appended to file out_file.\n" << "\tThe -c option clears the file before the message is appended.\n";
			exit(EXIT_FAILURE);
		}
	struct stat status;
	int result = stat(fileName, &status);					//create a stat struct and place the return value of the call into result
	if (result == -1)
		{
			inFileD = open(fileName, O_WRONLY | O_CREAT, 00000);	//if the file does not exist then create a file
			if (inFileD == -1)
				{
					perror("open failed");			//error checking for proper opening of file
					exit(EXIT_FAILURE);
				}
			close(inFileD);						// close file
		}
	else if ((status.st_mode & 0777) != 0000 )				//checks the file for permissions
		{
			cerr << fileName << " is not secure. Ignoring.\n";
			exit(EXIT_FAILURE);					//if the file has permissions then print an error message
		}
	chmod(fileName, 00200);							//change the permissions of the file to write only for the user
	if(argc == 4)								//if the number of arguments is equal to 4
		{
			inFileD = open(fileName,O_WRONLY | O_TRUNC);
			if (inFileD == -1)					//open the file and truncate it
	        		{
                        		perror("open for trunc failed");	//if opening the file fails print an error message and exit
                        		exit(EXIT_FAILURE);
                		}
			write(inFileD, buffer, strlen(buffer));
			write(inFileD, "\n", 1);				//write the information stored in buffer into the file
		}
	else
		{
			inFileD = open(fileName, O_WRONLY | O_APPEND);		//open the file and append the new information to the end of it
			if (inFileD == -1)
         			{
                        		perror("open for append failed");	//print an error message on a failed opening
                        		exit(EXIT_FAILURE);
				}
			write(inFileD, buffer, strlen(buffer));			//write the information stored in buffer into the file
			write(inFileD, "\n", 1);
		}
	chmod(fileName, 00000);							//clear the file permissions and close the file
	close(inFileD);
	return 0;								//end of program
}
