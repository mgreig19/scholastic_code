#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main()
{
  int pid;

  // fork another process
  pid = fork();
  if (pid < 0) {                             // error occurred
    cerr << "Fork Failed" << endl;
    exit(-1);
  }
  else if (pid == 0) {                       // child process
    execlp("/bin/ls", "ls", NULL);
  }
  else {                                     // parent process
    // parent will wait for the child to complete
    wait (NULL);
    cout << "Child Complete" << endl;
    exit(0);
  }
}
