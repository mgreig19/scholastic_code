/*******************************************************

 Programmer: Mason Greig
 ID: grei
 Assignment 3

 DUE DATE: 4/10/2018
 DUE TIME: 11:59pm

 Function: This program builds a micro shell which can accept normal
	   commands from the command line. A piping functionality is also
	   implemented.

*******************************************************/
//libraries needed for the program to function
#include <unistd.h>
#include <sys/wait.h>
#include <string>
#include <string.h>
#include <iostream>
#include <cstdlib>

using namespace std;

//forward method declaration(s)
void prepCommand(string& command, string& arguments);
void tokenizeCommand(string fullCommand, char* commandArray[], string argumentList[], int& numOfCommands);

//main program
int main()
	{
		//program variables to be used for commands, arguments, fork, execvp return code, etc
		int pid_1;
		int returnCode, pos, commandCount = 0;
		string userArguments, userCommand, argumentArray[11];
		char* completeCommand[12];

		//user prompt
		cout << "masonShell@ ";

		//get the user entered command
		getline(cin, userCommand);

		//while the userCommand is not q or quit
		while(!(userCommand == "q" or userCommand == "quit"))
			{
				//check for pipe in string
				pos = userCommand.find("||");

				//if pipe found
				if(pos > -1)
					{

						//if no arguments are supplied to the pipe then print error and exit
						if(userCommand == "||")
							{
								cout << "\nError: Improper pipe usage.\nCheck your command syntax and try again.\n\n";
								exit(-1);
							}

						//variables required for pipe's second set of commands
						int pid_2, pipe_ID[2], commandCount2;
						string userCommand2, userArguments2, argumentArray2[11];
                				char* completeCommand2[12];

						//set userCommand2 to the string that is input after the ||
						userCommand2 = userCommand.substr(pos + 2, std::string::npos);

						//erases the pipe and following command from the first command string
						userCommand = userCommand.erase(pos, std::string::npos);

						//clean and prep the commands before and after the pipe which the user enters
						//see method doc box for more detail
						prepCommand(userCommand, userArguments);
						prepCommand(userCommand2, userArguments2);

						//tokenize the command and arguments into c_strs' in order to create char* arrays to be passed to execvp
						//see method doc box for more detail
						tokenizeCommand(userArguments, completeCommand, argumentArray, commandCount);
						tokenizeCommand(userArguments2, completeCommand2, argumentArray2, commandCount2);

						//create pipe and check for pipe failure; exit if failure
						if(pipe(pipe_ID) < 0)
							{
								cout << "\nThe pipe has failed.\n";
								exit(-1);
							}

						//fork a child process
                                                pid_1 = fork();

                                                //check for fork failure
                                                if(pid_1 < 0)
                                                        {
                                                                cout << "\nError: Program failed to fork the first fork from the pipe condition.\n" << endl;
                                                        	exit(-1);
							}
                                                //if child process
                                                else if(pid_1 == 0)
                                                        {

								//close read end of pipe
								close(pipe_ID[0]);
								//close standard output
								close(1);
								//dup pipe output
								dup(pipe_ID[1]);
								//close original pipe output
								close(pipe_ID[1]);

                                                                //call execvp using the char* array completeCommand which holds the newly
                                                                //parsed and built command string.
                                                                returnCode = execvp(userCommand.c_str(), completeCommand);

                                                                //check for execvp failure
                                                                if(returnCode < 0)
                                                                        {
										if(userArguments == "")
											{
                                                                                		cout << "\nThe execution of the passed in command: " << userCommand << ":from the first child has failed.\nCheck the command syntax and try again.\n" << endl;
                                                                        			exit(-1);
											}
										else
											{
												cout << "\nThe execution of the passed in command: " << userArguments << ":from the first child has failed.\nCheck the command syntax and try again.\n" << endl;
												exit(-1);
											}
									}
								//exit child process
								exit(0);
                                                        }

						//fork a second child
						pid_2 = fork();

						//if second child fails print error message and exit
						if(pid_2 < 0)
							{

								cout << "\nError: Program failed to fork the second fork from the pipe condition.\n" << endl;
								exit(-1);
							}
						//if child process of second fork
						else if(pid_2 == 0)
							{
								//close write end of pipe
								close(pipe_ID[1]);
								//close standard input
                                                                close(0);
								//dup pipe input
                                                                dup(pipe_ID[0]);
								//close original pipe input
                                                                close(pipe_ID[0]);

                                                                //call execvp using the char* array completeCommand2 which holds the newly
                                                                //parsed and built command string for the command after the pipe
                                                                returnCode = execvp(userCommand2.c_str(), completeCommand2);

                                                                //check for execvp failure
                                                                if(returnCode < 0)
                                                                        {
										if(userArguments2 == "")
											{
                                                                                		cout << "\nThe execution of the passed in command: " << userCommand2 << " :from the second child has failed.\nCheck the command syntax and try again.\n" << endl;
                                                                        			exit(-1);
											}
										else
											{
												cout << "\nThe execution of the passed in command: " << userArguments2 << " :from the second child has failed.\nCheck the command syntax and try again.\n" << endl;
												exit(-1);
											}
									}
								//exit child process
								exit(0);

							}
						//parent process
                                                else
                                                        {
								//end/close pipe
								close(pipe_ID[0]);
  								close(pipe_ID[1]);

                                                                //wait for child processes to terminate
                                                                waitpid(pid_1, 0, 0);
								waitpid(pid_2, 0, 0);
                                                        }
					}
				//no pipe found
				else
					{
						//pass references to userCommand and userArguments variables to the prepCommand mthoed
						//see method doc box for more detail
						prepCommand(userCommand, userArguments);

						//pass the command string, char* array, string array, and commandCount to the tonkenizeCommand method
						//see method doc box for more detail
						tokenizeCommand(userArguments, completeCommand, argumentArray, commandCount);

						//fork a child process
						pid_1 = fork();

						//check for fork failure
						if(pid_1 < 0)
							{
								cout << "\nError: Program failed to fork.\n" << endl;
								exit(-1);
							}
						//if child process
						else if(pid_1 == 0)
							{
								//call execvp using the char* array completeCommand which holds the newly
								//parsed and built command string.
								returnCode = execvp(userCommand.c_str(), completeCommand);

								//check for execvp failure, print message if fail and exit program
								if(returnCode < 0)
									{
										if(userArguments == "")
											{
												cout << "\nThe execution of the passed in command: " << userCommand << " :has failed.\nCheck command syntax and try again.\n" << endl;
												exit(-1);
											}
										else
											{
												cout << "\nThe execution of the passed in command: " << userArguments << " :has failed.\nCheck command syntax and try again.\n" << endl;
												exit(-1);
											}
									}
								//exit child process
								exit(0);
							}
						//parent
						else
							{
								//wait for child process to terminate
	                                                        waitpid(pid_1, 0, 0);
							}

					}

				//user prompt
				cout << "masonShell@ ";
				//get the user entered command; determines loop continuation
				getline(cin, userCommand);
			}
		//program end
		return 0;
	}

/*************************************************************

Function: void prepCommand(string& command, string& arguments)

Use: Splits the passed in command by placing the first string into
     the command variable and the remainder of the string into the
     arguments variable. If the command has no following arguments
     then the arguments variable is set to empty.

Arguments: string& command: a string which has been passed by reference and contains the
			    initial command variable
	   string& arguments: a string which has been passed by reference and contains the
			      initial arguments variable

Returns: Nothing

*************************************************************/
void prepCommand(string& command, string& arguments)
	{

		size_t pos = command.find_first_not_of(" ");
		//if npos found on either side of pipe print error and exit
		if(pos == std::string::npos)
			{
				cout << "\nError: Improper pipe usage.\nCheck your command syntax and try again.\n\n";
                                exit(-1);
			}
		//remove any leading spaces before the initial user command to be executed
		command = command.substr(pos, std::string::npos);

		//if no space is found before the end of the end of the command string
                if(command.find_first_of(" ") == std::string::npos)
	                {
        	                //set arguments to empty
                                arguments = "";
                        }
		//arguments were supplied
                else
                        {
                	        //place the command to be parsed into arguments
                                arguments = command;
                                //erase all the arguments from the command string, leaving only the main command which is used in execvp call
                               	command.erase(command.find_first_of(" "), std::string::npos);
                        }
		//exit method
		return;
	}
/*************************************************************

Function: void tokenizeCommand(string fullCommand, char* commandArray[], string argumentList[], int& numOfCommands)

Use: splits the passed in string fullCommand into individual arguments and stores them
	in the string array argumentList, which then the address gets
	stored in the array of pointers to strings commandArray.
	The function also keeps track of the number of parsed arguments for debugging purposes.

Arguments: string fullCommand: the passed in string to be parsed
	   char* commandArray[]: the passed in array of pointers to strings which the arguments are to
				 be stored in
	   string argumentList[]: the string array which is going to store the address of the strings
	   int& numOfCommands: a passed in reference int to the number of commands which are processed

Returns: Nothing

*************************************************************/
void tokenizeCommand(string fullCommand, char* commandArray[], string argumentList[], int& numOfCommands)
        {
		//method members
		string arguments;
		size_t pos, pos_2;
		int i = 0;
		numOfCommands = 0;
		//begin loop
                while(true)
                        {
				//find a blank in fullCommand and store the position in pos
                           	pos = fullCommand.find(" ");

				//if there is no space after the string
				if(pos == std::string::npos)
                                        {
						//set the string new value, ending at npos
						fullCommand = fullCommand.substr(0, pos);
						//places string in i of argumentsList
						argumentList[i] = fullCommand;
						//put address of first char of the string at i in argumentList into
						//the commandArray at i
						commandArray[i] = (char*) argumentList[i].c_str();
						//set terminating null character after the last argument stored
						commandArray[i + 1] = NULL;
						//increment numOfCommands (debugging)
						numOfCommands = i + 1;
						//exit loop
                                                break;
                                        }
				//set arguments to the remaining string after the found space position
				arguments = fullCommand.substr(pos, std::string::npos);

				//store value ofarguments.find_first_not_of(" ") into pos_2
				pos_2 = arguments.find_first_not_of(" ");

				//is pos_2 is npos (if no arguments found)
				if(pos_2 == std::string::npos)
					{
						//set full command to the full command string - leading spaces up to the npos
						fullCommand = fullCommand.substr(fullCommand.find_first_not_of(" "), pos);
						//places string in i of argumentsList
						argumentList[i] = fullCommand;
						//put address of first char of the string at i in argumentList into
                                                //the commandArray at i
                                		commandArray[i] = (char*) argumentList[i].c_str();
						//set terminating null character after the last argument stored
						commandArray[i + 1] = NULL;
						//increment numOfCommands
                                                numOfCommands = i + 1;
						//break out of loop
                                                break;

					}
				//set arguments to the remaining string after the command word
				arguments = arguments.substr(pos_2, std::string::npos);
				//set command to the first word - leading spaces
                                fullCommand = fullCommand.substr(fullCommand.find_first_not_of(" "), pos);
				//places string in i of argumentsList
				argumentList[i] = fullCommand;
				//put address of first char of the string at i in argumentList into
                                //the commandArray at i
				commandArray[i] = (char*) argumentList[i].c_str();
				//set fullCommand to the arguments string to be processed by next loop iteration
				fullCommand = arguments;
				//increment i
				i++;
                        }
		//exit method
                return;
        }
