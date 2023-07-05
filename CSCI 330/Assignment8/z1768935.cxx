/******************************************
Program: Assignment8: Command interpreter

Author: Mason Greig

ZID: z1768935

Due date: 11/18/16

Purpose: become familiar with fork, exec, and wait network programming calls
******************************************/
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>									//libraries to include for the program
#include <iostream>
#include <sys/wait.h>


using namespace std;

int main()
{
	string userInput, command, arg1, arg2, arg3;
	int argc;
	string delimit = " ";
        size_t stringPos = 0;					//variable declarations for use in the program
        string token;
	int pid, result, status;
	while (true)						//while true do the following
		{
			cout << "Enter a command (exit to quit): ";			//promtpt user for a command
                        getline(cin, userInput);					//store command in variable userInput
                        if(userInput == "exit")
	                        {
        	                        break;						//if the userInput is equal to exit then break out of the loop
                                }
   			pid = fork();							// fork will make 2 processes
   			if (pid == -1)
				{
					perror("fork");
					exit(EXIT_FAILURE);				//incase of fork failure
				}
   			if (pid == 0)							//if pid is equal to 0 then initiate child process
				{
					while((stringPos = userInput.find(delimit)) != std::string::npos)	//while the sting in the userInput has not reached the null position cycle through the loop
						{
							token = userInput.substr(0, stringPos);			//token is equal to the string found from position 0 to the delimiter " "
							if(argc == 0)
								{
									command = token;			//if the number of the argument count is 0 at the end of the loop then set command equal to the token
								}
							else if (argc == 1)					//if the number of the argument count is 1 at the ned of the loop then set arg1 equal to token
								{
									arg1 = token;				// a loop to partition the passed in string stored in userInput into a command line with either 1, 2, or 3 proceding arguments
								}
							else if (argc == 2)
								{
									arg2 = token;				//if the number of the argument count is 2 at the end of the loop then store the value of token in arg2
								}
							else
								{
									arg3 = token;				//if the number of the argument count is 3 at the end of the loop then store the value of token in arg3 
								}
							argc++;							//increment argument count
							userInput.erase(0, stringPos + delimit.length());	//erase the string located at between position 0 and the next delimiter value in order to have the next string section cycle through the loop 
						}
					if(argc == 1)
						{
							arg1 = userInput;
							result = execlp(command.c_str(), command.c_str(), arg1.c_str(), (char*) NULL);
						}
					if (argc == 2)
						{
							arg2 = userInput;
							result = execlp(command.c_str(), command.c_str(), arg1.c_str(), arg2.c_str(), (char*) NULL);	//set the remaining argument of the command to userInput and if the number of arguments is 1 - 3 then execute the necessary command call using exclp
						}
					if (argc == 3)
						{
							arg3 = userInput;
							result = execlp(command.c_str(), command.c_str(), arg1.c_str(), arg2.c_str(), arg3.c_str(), (char*) NULL);
						}
					if (result == -1)
						{
							perror("execlp");				//error check for the execlp failure
							exit(EXIT_FAILURE);
						}
   				}
			else
				{
      					wait(&status);							//parent process waits for the child process to finish
   				}
		}
   	return 0;										//return 0 to terminate the program
}
