
// Using POSIX semaphores to provide mutex between child processes
// Based on work by Kay Robbins and Steve Robbins
// compile with -lrt

#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>

#include <errno.h>
#include <unistd.h>
#define TEN_MILLION 10000000L
#define BUFSIZE 1024


// Without use of shared memory, the semaphore doesn't work across
// processes!  Of course it would work with threads in one process,
// since they share the process address space.

// uncomment the next line to start using shared memory for sem_t object
#define USE_SHARED_MEMORY
 
void worker(int i, void * args);
 
int main(int argc, char *argv[])
{
  int error;
  int i;
  int id;
  sem_t *semlock;
  pid_t pids[10];
  int ret;
 
#ifdef USE_SHARED_MEMORY
  id = shmget(IPC_PRIVATE, sizeof(sem_t), (S_IRUSR|S_IWUSR));
  if (id == -1)
    {
      perror("Failed to create shared memory segment");
      return 1;
    }

  semlock = (sem_t *)shmat(id, NULL, 0);
  if (semlock == (void *)-1)
    {
      perror("Failed to attach memory segment");
      return 1;
    }
#else
  // try using ordinary process-private memory for sem_t variable
  semlock = (sem_t *)malloc(sizeof(sem_t));
#endif

  // 1 in second arg = shared across processes
  ret = sem_init(semlock, 1, 1);
  if (ret == -1)
    {
      perror("Failed to initialize semaphore");
    }
  else
    {
      for (i = 0; i < 10; i++)
        {
          ret = fork();
          if (ret < 0)
            {
	      fprintf(stderr, "Failed to create process:%s\n", strerror(error));
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
        wait(0);
      fprintf(stderr, "workers all done\n");
    }

#ifdef USE_SHARED_MEMORY
  // shared memory detach
  ret = shmdt((void *)semlock);
  if (ret == -1)
    {
      perror("Failed to detach shared memory segment");
      return 1;
    }

  // now remove the shared memory segment
  ret = shmctl(id, IPC_RMID, NULL);
  if (ret == -1)
    {
      perror("Failed to free shared memory segment");
      return 1;
    }

#else
  free(semlock);
#endif
  return 0;
}


 
void worker(int i, void * args)
{
  char buffer[BUFSIZE];
  char *c;
  sem_t *semlockp;
  int ret;

  struct timespec sleeptime;
  sleeptime.tv_sec = 0;
  sleeptime.tv_nsec = TEN_MILLION;
 
  semlockp = (sem_t *)args;
  snprintf(buffer, BUFSIZE, "This is process %ld\n",
           (long)getpid());
  c = buffer;

  // no buffering
  setbuf(stderr, NULL);

  // entry section
  ret = sem_wait(semlockp);
  while (ret == -1)
    {
      if(errno != EINTR)
        {
          fprintf(stderr, "Failed to lock semaphore\n");
          return;
        }
      ret = sem_wait(semlockp);
    }

  // critical section
  while (*c != '\0')
    {
      fputc(*c, stderr);
      c++;
      nanosleep(&sleeptime, NULL);
    }

  // exit section
  ret = sem_post(semlockp);
  if (ret == -1)
    fprintf(stderr, "Failed to unlock semaphore\n");

  // remainder section
  return;
}
