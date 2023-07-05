#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// #include <sys/types.h>

// based on figs. 3.23-3.24

using namespace std;

int main()
{
  int pid;
  int fd[2];
  int ret;

  char write_msg[100] = "hello world!";
  char read_msg[100];

  // create pipe
ret = pipe(fd);
if (ret == -1)
  { 
    cout << "Pipe failed " << ret << endl;
    exit(-1);
  }

  // fork another process
  pid = fork();
  if (pid < 0)                               // error occurred
    {
      cout << "Fork failed " << ret << endl;
      exit(-1);
    }
  else if (pid == 0)                         // child = consumer
    {
      // close unused write-end
      close (fd[1]);

      // read
      read (fd[0], read_msg, 100);
      cout << "child read " << strlen(read_msg) << " bytes: " << read_msg << endl;

      // close read-end
      close (fd[0]);
    }
  else                                       // parent = producer
    {
      // close unused read-end
      close (fd[0]);

      // write
      write (fd[1], write_msg, strlen(write_msg)+1);
      cout << "parent wrote " << strlen(write_msg) << " bytes plus terminator: " << write_msg << endl;

      // close write-end
      close (fd[1]);
     }

  return 0;
}
