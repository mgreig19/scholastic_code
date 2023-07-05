/******************************************
Program: Assignment9: TCP server socket system calls

Author: Mason Greig

ZID: z1768935

Due date: 12/2/16

Purpose: become familiar with TCP server socket system calls
******************************************/
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <errno.h>
#include <dirent.h>
#include <ctime>					//libraries
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

void processClientRequest(int connSock)			//function to implement the request of a client
{
        int receivedResult;
	stringstream convert;
	string replace;
        char buffer[1024], targetPath[1024], argument[1024], request[1024];	//declared data types
	time_t targetTime = time(0);

	receivedResult = read(connSock, targetPath, sizeof(targetPath));	//read message from client
        if (receivedResult <= 0)
		{
                	perror("read");
                	exit(EXIT_FAILURE);
        	}
	else
		{
			strncpy(request, targetPath, 5);			//seperate the first 5 char spaces from the rest of the pathName
			request[5] = '\0';					//adds null to the end of the char array
		}

	cout << "Client request: " << targetPath << endl;

	convert << request;
	convert >> replace;
	if (replace != "GET /" and string(targetPath) != "INFO")		//checks for whether or not the argument passed in is GET / or INFO
		{
			strcpy(buffer, targetPath);
			strcat(buffer, ": the argument must start with (GET /) or (INFO)\n");		//copy the info in targetPath into the buffer
			receivedResult = write(connSock, buffer, strlen(buffer));
        		if (receivedResult < 0)
				{
                			perror("write (located in resultRequest)");		//error check for failed write call
                			exit(EXIT_FAILURE);
        			}
			exit(EXIT_SUCCESS);
		}
	convert << targetPath;
	convert >> replace;
	if (replace == "GET /")							//if the passed target is equal to GET /
		{
			for (unsigned int i = 6; i < sizeof(targetPath); i++)			//loop through the path info
				{
					if (targetPath[i - 1] == '.' and targetPath[i] == '.')
						{
							strcpy(buffer, targetPath);
							strcat(buffer, ": no arguments within the path may contain ..\n");	//copy info from path into buffer
							receivedResult = write(connSock, buffer, strlen(buffer));
							if (receivedResult < 0)
								{
									perror("write in GET / argument");		//error check for failed write
									exit(EXIT_FAILURE);
								}
							exit(EXIT_SUCCESS);
						}
					else if (targetPath[i] == ' ')
						{
							break;					//if a space is encountered break out of the decision
						}
					else
						{
							argument[i - 6] = targetPath[i];		//make the values at 0 to sizeof(targetPath)in argument store the values of the targetPath 
						}
				}
		}
	convert << targetPath;
	convert >> replace;
	if (replace == "INFO")					//INFO extra credit which displays the local time
		{
			struct tm *currentTime = localtime(&targetTime);
			cout << "Local Time & Date: " << currentTime->tm_hour << ":" << currentTime->tm_min << " " << (currentTime->tm_mon + 1) << " " << currentTime->tm_mday << ", " << (currentTime->tm_year + 1900) << endl;
			close(connSock);
		}

	DIR *directoryPath = opendir(argument);		//opens a directory
	if (directoryPath == 0)
		{
			strcpy(buffer, argument);
			strcat(buffer, ": unable to open directory\n");
			int receivedResult = write(connSock, buffer, strlen(buffer));
			if (receivedResult < 0)								//error message
				{
					perror("write (in dirPathResult)");
					exit(EXIT_FAILURE);
				}
			exit(EXIT_SUCCESS);
		}

	struct dirent *entry;										//the entry of the directory
	while((entry = readdir(directoryPath)) != NULL)
		{
			strcpy(buffer, entry->d_name);							///copy d_name of entry into the buffer
			strcat(buffer, "\n");
			receivedResult = write(connSock, buffer, strlen(buffer));			//while the next entry from the directory is not NULL loop through and read the whole thing into the client while it still available 
			if (receivedResult < 0)
                                {
                                        perror("write (in entryResult)");
                                        exit(EXIT_FAILURE);						//error checking
                                }
			cout << "Information: " << buffer << ": was sent successfully.";
		}

	closedir(directoryPath);
	cout << "Finished with Client request." << endl;						//close the directory
        close(connSock);
}

int main(int argc, char *argv[])
{
	int result;
	if (argc != 2)
		{
			cerr << "USAGE: TCPServerFork port\n";
			exit(EXIT_FAILURE);
		}

	// Create the TCP socket
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0)
		{
			perror("socket");
			exit(EXIT_FAILURE);
		}
	// create address structures
	struct sockaddr_in server_address;  // structure for address of server
	struct sockaddr_in client_address;  // structure for address of client
	unsigned int addrlen = sizeof(client_address);

	// Construct the server sockaddr_in structure
	memset(&server_address, 0, sizeof(server_address));   /* Clear struct */
	server_address.sin_family = AF_INET;                  /* Internet/IP */
	server_address.sin_addr.s_addr = INADDR_ANY;          /* Any IP address */
	server_address.sin_port = htons(atoi(argv[1]));       /* server port */

	// Bind the socket
	result = bind(sock, (struct sockaddr *) &server_address, sizeof(server_address));
	if (result < 0)
		{
			perror("bind");
			exit(EXIT_FAILURE);
		}

	// listen: make socket passive and set length of queue
	result = listen(sock, 64);
	if (result < 0)
		{
			perror("listen");
			exit(EXIT_FAILURE);
		}

	cout << "TCPServer listening on port: " << argv[1] << endl;
	// Run until cancelled

	while (true)
		{
			int connSock=accept(sock, (struct sockaddr *) &client_address, &addrlen);
			if (connSock < 0)
				{
					perror("accept");
					exit(EXIT_FAILURE);
				}
			// fork
			if (fork())
				{ 	    // parent process
					close(connSock);
				}
			else
				{ 			// child process
					processClientRequest(connSock);
				}
		}
	close(sock);
	return 0;
}
