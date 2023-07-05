/****************************************************************
   PROGRAM:   Assingment 8
   AUTHOR:    Katia Gomes
   LOGON ID:  Z1730089
   DUE DATE:  Friday, April 3

   FUNCTION:  Uses multiple processes and piping to execute two
		commands with one another
****************************************************************/

#include <iomanip>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>

using namespace std;

void findArgs (char[], char* []);	// Used to find the tokens from user commands

int main() {
  char command1[81];		// Holds the users first command
  char command2[81];		// Holds the users second command
  pid_t pid1 = 1, pid2 = 1;	// Process id from first and second fork

  // Gets first command from the user
  cout << "Enter command 1 (incl. args) or quit: ";
  cin.getline(command1, 81);

  // While the user doesn't enter "quit" and only loops for the parent process
  while (strcmp(command1, "quit") != 0 && pid1 > 0 && pid2 > 0) {
    // Gets second command from the user
    cout << "Enter command 2 (incl. args): ";
    cin.getline(command2, 81);

    char* arg1[6];		// Individual tokens from user first command
    char* arg2[6];		// Individual tokens from user second command
    char path1[21], path2[21];	// Paths to the first and second command
    int pipefd[2];		// Pipe file descriptor

    // Creates pipe and error checks
    if (pipe(pipefd) < 0) {
      perror ("Pipe");
      exit (-1);
    }

    // Creates first child process and error checks
    pid1 = fork();
    if (pid1 < 0) {
      perror ("Fork");
      exit (-1);
    }

    if (pid1 == 0) { // Child process from first fork()
      close(pipefd[0]);	// Close read end of pipe
      close(1);		// Close standard output

      dup(pipefd[1]);	// Duplicate write end of pipe into standard output
      close(pipefd[1]);	// Close write end of pipe

      findArgs(command1, arg1);	// Finds arguments from command 1

      strcpy(path1, "/bin/");	// Creates the path for command 1 to /bin/
      strcat(path1, arg1[0]);
      if (execv(path1, arg1) < 0) {	// Checks if command 1 is in /bin/
        strcpy(path1, "/usr/bin/");		// Creates path for command 1 to /usr/bin/
        strncat(path1, arg1[0], strlen(arg1[0]));
        if (execv(path1, arg1) < 0) {		// Checks if command 1 is in /usr/bin/
          perror ("Error");			// If in neither, error
          exit (-1);
        }
      }
    }

    else { // Successful fork
      // Creates second child process and error checks
      pid2 = fork();
      if (pid2 < 0) {
        perror ("Fork");
        exit (-1);
      }

      if (pid2 == 0) { // Child process from second fork()
        close(pipefd[1]);	// Close write end of pipe
        close(0);		// Close standard input

        dup(pipefd[0]);		// Duplicate read end of pipe into standard input
        close(pipefd[0]);	// Close read end of pipe

        findArgs(command2, arg2);	// Finds arguments from command 2

        strcpy(path2, "/bin/");		// Creates path for command 2 to /bin/
        strncat(path2, arg2[0], strlen(arg2[0]));
        if (execv(path2, arg2) < 0) {	// Checks if command 2 is in /bin/
          strcpy(path2, "/usr/bin/");		// Creates path for command 2 to /usr/bin/
          strncat(path2, arg2[0], strlen(arg2[0]));
          if (execv(path2, arg2) < 0) {		// Checks if command 2 is in /usr/bin/
            perror ("Error");			// If in neither, error
            exit (-1);
          }
        }
      }

      else { // Parent process
        close (pipefd[0]);	// Closes read end of pipe
        close (pipefd[1]);	// Closes write end of pipe

        waitpid(pid2, NULL, 0);	// Waits for child2's process to end

        // Re-defines command 1 to go through while loop again
        cout << "Enter command 1 (incl. args) or quit: ";
        cin.getline(command1, 81);
      }
    }
  }
  return 0;
}

/****************************************************************
   FUNCTION:   void findArgs (char [], char* [])

   ARGUMENTS:  char str[] which holds full command and char* args[]
		which will hold the individual commands

   RETURNS:    Nothing

   NOTES:      Takes the full command in a single char str[] and
		converts it to individual tokens within char *args[]
****************************************************************/
void findArgs(char str[], char* args[]) {
  char * index;	// Holds individual token
  int i = 0;	// Iterator

  index = strtok(str, " ");	// Gets first token
  // While the token isn't NULL
  while (index != NULL) {
    args[i] = index;		// Places token in args[i]
    index = strtok(NULL, " ");	// Gets next token
    i++;			// Iteratres i
  }

  args[i] = (char*) NULL;	// Sets the last argument to NULL
}
