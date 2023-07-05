
// Using POSIX semaphores to provide mutex between child processes
// Based on work by Kay Robbins and Steve Robbins
// compile with -lrt

#include <semaphore.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstring>

#define TEN_MILLION 10000000L
#define BUFSIZE 1024

using namespace std;

// Without use of shared memory, the semaphore doesn't work across
// processes!  Of course it would work with threads in one process,
// since they share the process address space.

// uncomment the next line to start using shared memory for sem_t object
// #define USE_SHARED_MEMORY
 
void worker(int i, void * args);
 
int main(int argc, char *argv[])
{
  int error;
  int i;
  int id;
  sem_t *semlock;
  pid_t pids[10];
  int ret;
  const int const_0 = 0;
 
#ifdef USE_SHARED_MEMORY
  id = shmget(IPC_PRIVATE, sizeof(sem_t), (S_IRUSR|S_IWUSR));
  if (id == -1)
    {
      cout << "Failed to create shared memory segment" << endl;
      return 1;
    }

  semlock = (sem_t *)shmat(id, NULL, 0);
  if (semlock == (void *)-1)
    {
      cout << "Failed to attach memory segment" << endl;
      return 1;
    }
#else
  // try using ordinary process-private memory for sem_t variable
  semlock = new sem_t;
#endif

  // 1 in second arg = shared across processes
  ret = sem_init(semlock, 1, 1);
  if (ret == -1)
    {
      cout << "Failed to initialize semaphore" << endl;
    }
  else
    {
      for (i = 0; i < 10; i++)
        {
          ret = fork();
          if (ret < 0)
            {
	      cout << "Failed to create process: " << strerror(error) << endl;
	      return 1;
            }
	  else
            pids[i] = ret;

          if (pids[i] == 0)          // child
            {
	      worker(i, semlock);
	      exit(0);
            }
	}  // end for loop

      // parent
      for (i = 0; i < 10; i++)
        wait(const_0);
      cout << "workers all done" << endl;
    }

#ifdef USE_SHARED_MEMORY
  // shared memory detach
  ret = shmdt((void *)semlock);
  if (ret == -1)
    {
      cout << "Failed to detach shared memory segment" << endl;
      return 1;
    }

  // free the shared memory
  ret = shmctl(id, IPC_RMID, NULL); 
  if (ret == -1)
    {
      cout << "Failed to free the shared memory" << endl;
      return 1;
    }

#else
  delete semlock;
#endif
  return 0;
}


 
void worker(int i, void * args)
{
  char buffer[BUFSIZE];
  char *c;
  sem_t *semlockp;
  int ret;
  ostringstream oss;

  struct timespec sleeptime;
  sleeptime.tv_sec = 0;
  sleeptime.tv_nsec = TEN_MILLION;
 
  semlockp = (sem_t *)args;
  //  snprintf(buffer, BUFSIZE, "This is process %ld\n", (long)getpid());
  oss << "This is process " << (long)getpid();
  strncpy(buffer, oss.str().c_str(), BUFSIZE);
  c = buffer;

  // no buffering
  cout << unitbuf;

  // entry section
  ret = sem_wait(semlockp);
  while (ret == -1)
    {
      if(errno != EINTR)
        {
          cout << "Failed to lock semaphore" << endl;
          return;
        }
      ret = sem_wait(semlockp);
    }

  // critical section
  while (*c != '\0')
    {
      cout << *c;
      c++;
      nanosleep(&sleeptime, NULL);
    }
  cout << endl;

  // exit section
  ret = sem_post(semlockp);
  if (ret == -1)
    cout << "Failed to unlock semaphore" << endl;

  // remainder section
  return;
}
