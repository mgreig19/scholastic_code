/****************************************************************
   FILE:      z1730089.cpp
   AUTHOR:    Katia Gomes
   LOGON ID:  Z1730089
   DUE DATE:  Friday, April 24

   FUNCTION:  Create a server program for a client to connect to
****************************************************************/

#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <string>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

using namespace std;

int main (int argc, char* argv[]) {
  string path;

  // Makes sure user entered correct arguments
  if (argc != 3) {
    cout << "Incorrect number of arguments" << endl;
    exit(EXIT_FAILURE);
  }
  else {
    path = argv[2];
  }

  // Makes sure the path the user provided starts with a /
  //   and doesn't contain ..
  size_t found;
  found = path.find("/");
  if (found == string::npos && found != 0) {
    cout << "Invalid path. Must begin with /" << endl;
    exit(EXIT_FAILURE);
  }
  else {
    found = path.find("..");
    if (found != string::npos) {
      cout << "Invalid path. Can't have .." << endl;
      exit(EXIT_FAILURE);
    }
  }

  // Makes sure that the user ented a valid directory for the path
  struct stat s;
  if (stat(path.c_str(), &s) == 0) {
    if (!(s.st_mode & S_IFDIR)) {
      cout << "Path is not a directory" << endl;
      exit(EXIT_FAILURE);
    }
  }
  else {
    cerr << "Path doesn't exist" << endl;
    exit(EXIT_FAILURE);
  }

  int sockfd;
  int serverlen;
  struct sockaddr_in echoserver; // Structure for address to server
  struct sockaddr_in echoclient; // Structure for address to client

  // Create the TCP socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    cerr << "Failed to create socket" << endl;
    exit(EXIT_FAILURE);
  }

  // Construct the server sockaddr_in structure
  memset (&echoserver, 0, sizeof(echoserver));	// Clear stuct
  echoserver.sin_family = AF_INET;		// Internet IP
  echoserver.sin_addr.s_addr = INADDR_ANY;	// Any IP address
  echoserver.sin_port = htons (atoi(argv[1]));	// Server port

  // Binds the socket
  serverlen = sizeof(echoserver);
  errno = 0;
  if (bind(sockfd, (struct sockaddr*) &echoserver, serverlen) < 0) {
    cerr << "Bind failed. Reason '" << strerror(errno) << "'" << endl;
    exit(EXIT_FAILURE);
  }

  errno = 0;
  if (listen(sockfd, 64) < 0) {
    cerr << "Listen failed. Reason '" << strerror(errno) << "'" << endl;
    exit(EXIT_FAILURE);
  }

  // Run until cancelled
  int received, newSock;
  int forkfd;
  socklen_t clientlen;
  char buffer[265];
  while ( (newSock = accept(sockfd, (struct sockaddr*) &echoclient, &clientlen)) ) {
    errno = 0;
    if (newSock < 0) {
      cerr << "Accept failed. Reason '" << strerror(errno) << "'" << endl;
      exit(EXIT_FAILURE);
    }

    // Creates a child process to handle user request
    forkfd = fork();
    if (forkfd < 0) {	// Error
      cerr << "Fork Failed. Reason '" << strerror(errno) << "'" << endl;
      exit(EXIT_FAILURE);
    }
    else if (forkfd == 0) {	// Child Process
      // Read a message from the client
      errno = 0;
      if ( (received = read(newSock, buffer, 256)) < 0) {
        cerr << "Failed to receive message. Reason '" << strerror(errno) << "'" << endl;
        exit(EXIT_FAILURE);
      }
      buffer[received] = '\0';

      close(sockfd);	// Closes socket
      dup2(newSock, 0);	// Duplicates read end of client to standard input
      dup2(newSock, 1);	// Duplicates write end of client to standard output
      dup2(newSock, 2);	// Duplicates error end of client to standard error output
      close(newSock);	// Closes newSock

      // Grabs the first command the client enters
      char* command;
      command = strtok(buffer, " ");
      // Makes sure the client entered an argument
      if (command == NULL ) {
        cerr << "Incorrect number of argument provided" << endl;
        exit(EXIT_FAILURE);
      }

      // If the client wishes to GET information
      if (strcmp(command, "GET") == 0) {
        // Grabs the path the client enters
        char *newPath;
        newPath = strtok(NULL, " ");

        // Makes sure the client entered a path
        if (newPath == NULL) {
          cerr << "No path provided" << endl;
          exit(EXIT_FAILURE);
        }

        // Constructs the full path using the path for this server and the path the client provided
        char *comPath = argv[2];
        strncat(comPath, newPath, strlen(newPath));

        // Makes sure the path exist
        if (stat(comPath, &s) == 0) {
          // Path leads to a directory
          if(s.st_mode & S_IFDIR) {
            // Displays the contents of the directory
            if (execl("/bin/ls", "ls", comPath, (char *) NULL) < 0) {
              cerr << "Failed to run ls execl." << endl;
              exit(EXIT_FAILURE);
            }
          }

          // Path leads to a file
          else if (s.st_mode & S_IFREG) {
            // Displays the contents of the file
            if (execl("/bin/cat", "cat", comPath, (char *) NULL) < 0) {
              cerr << "Failed to run cat execl." << endl;
              exit(EXIT_FAILURE);
            }
          }
        }

        // Client entered an invalid path
        else {
          cerr << "Path doesn't exist" << endl;
          exit(EXIT_FAILURE);
        }
      }

      // If the client wishes to see the date and time
      else if (strcmp(command, "INFO") == 0) {
        // Displays date and time
        if (execl("/bin/date", "date", "+%A, %B %d %r", (char *) NULL) < 0) {
          cerr << "Failed to run date execl." << endl;
          exit(EXIT_FAILURE);
        }
      }

      // Client enters neither GET or INFO
      else {
        cerr << "Must enter either 'GET' or 'INFO' first";
        exit(EXIT_FAILURE);
      }

      close(newSock);
      exit(EXIT_SUCCESS);
    }
    else {	// Parent Process
      close(newSock);
    }
  }
  close(sockfd);
  return 0;
}
