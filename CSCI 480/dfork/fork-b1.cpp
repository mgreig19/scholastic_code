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
    execl("/home/turing/t90rkf1/d480/dfork/hello1.exe", "hello1.exe", NULL);
    cout << "Hi! This is dead (unreachable) code." << endl;
  }
  else {                                     // parent process
    // parent will wait for the child to complete
    wait (NULL);
    cout << "Child Complete" << endl;
    exit(0);
  }
}
