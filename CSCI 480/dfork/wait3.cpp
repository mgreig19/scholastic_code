#include <sys/wait.h>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <errno.h>

using namespace std;

// Based on example from "man wait"

/* Example of use:

           $ ./wait2.exe &
           Child PID is xxxxx
           [1] 32359
           $ kill -STOP xxxxx
           stopped by signal 19
           $ kill -CONT xxxxx
           continued
           $ kill -TERM xxxxx
           killed by signal 15
           [1]+  Done                    ./wait2.exe
*/ 


// To see process state codes, use "man ps -Ostat"
// To see parent id's, use "ps -Oppid"
// To add multiple columns, use "ps -Ostat,ppid" or column id's of your choice

/*   Here are the most common process state codes:
       R    Running or runnable (on run queue)
       S    Interruptible sleep (waiting for an event to complete)

     Less common states:
       T    Stopped - needs SIGCONT signal to continue
       Z    Defunct ("zombie") process, terminated but not waited on
            by its parent
       D    Uninterruptible sleep (stuck unless problematic I/O event completes)


     Secondary codes about priorities:
               <    high-priority (not nice to other users)
               N    low-priority (nice to other users)

     Secondary codes about memory:
               L    has pages locked into memory (for real-time and custom IO)

     Secondary codes about process hierarchy:
               s    is a session leader
               +    is in the foreground process group
               l    is multi-threaded (using CLONE_THREAD, like NPTL pthreads do)

  A session leader is the initial process controlled by a given terminal,
  thus usually the shell.

  When a user logs out of a system, the kernel needs to terminate all
  the processes s/he had running. To simplify this task, processes
  are organized into sessions.
  session ID = pid of the process that created the session = session leader

  Every session is tied to a terminal from which processes in the
  session get their input & send their output = controlling terminal.

  Within a session, processes can be divided into process groups that
  can be foregrounded/stopped together. A group of programs connected
  by pipes would be in the same process group. The first one would be
  the process group leader.

  The process group receives input from the terminal. When the process
  group receives cntl-Z, all the processes stop & return control to
  the terminal.

  For more about sessions and process groups see:
  http://www.informit.com/articles/article.aspx?p=397655&seqNum=6
  http://www.cs.ucsb.edu/~almeroth/classes/W99.276/assignment1/signals.html

  For more about process state codes see:
  http://slack-linux.blogspot.com/2009/07/linux-process-state-codes.html
  http://linuxtipsblog.com/?p=42

*/


int main(int argc, char *argv[])
{
  pid_t pid;
  pid_t w;
  int status;

  pid = fork();
  if (pid == -1)                       // Fork error
    {
       perror("fork");
       exit(EXIT_FAILURE);
    }

  if (pid == 0)                       // Child
    {
      cout << "Child PID is " << getpid() << endl;
       if (argc == 1)
         {
           pause();                      // Wait for signals
         }
       _exit(atoi(argv[1]));
    }
  else                               // Parent
    {
       do
         {
           w = waitpid(pid, &status, WUNTRACED | WCONTINUED);
           if (w == -1)
             {
                perror("waitpid");
                exit(EXIT_FAILURE);
             }

           if (WIFEXITED(status))
             { 
	       cout << "exited, status = " << WEXITSTATUS(status) << endl;
	     }
           else if (WIFSIGNALED(status))
             {
	       cout << "killed by signal " << WTERMSIG(status) << endl;
	     }
           else if (WIFSTOPPED(status))
             {
	       cout << "stopped by signal " << WSTOPSIG(status) << endl;
	     }
           else if (WIFCONTINUED(status))
             {
	       cout << "continued"<< endl;
	     }
	 } while (!WIFEXITED(status) && !WIFSIGNALED(status));
       exit(EXIT_SUCCESS);
    }
}
