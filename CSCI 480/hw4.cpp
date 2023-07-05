/********************************************************************

 Program:   Assignment 4
 Author:    Mason Greig
 Z-number:  z1768935
 Date Due:  05/03/18

 Purpose:   This program simulates a 4-way stop light at the
 intersection of Annie Glidden and Lincoln Highway.

 *********************************************************************/
#include <semaphore.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>
#include "Street.h"

using namespace std;

struct sema
	{
		sem_t arr[5];
	};

void worker(int i, sema * args, Street streets[4]);
void processStreetActivity(int i, int j, int startSection, int endSection, sema *semlockp, Street streets[4]);
void semaphoreWait(sem_t *);
void unlockSemaphore(sem_t *semlockp);

int main(int argc, char *argv[])
	{
		cout << unitbuf;
  		int error;
  		int i;
  		int id;
		Street streets[4] = {{1, "Lincoln Hwy", "West", "NE", "NW"}, {2, "Annie Glidden", "North", "SE", "NE"},
                                    {3, "Lincoln Hwy", "East", "SW", "SE"}, {4, "Annie Glidden", "South", "NW", "SW"}};
		sema *semlock;
  		pid_t pids[5];
  		int ret;

  		// Get the address location of the shared memory:
  		id = shmget(IPC_PRIVATE, sizeof(sema), (S_IRUSR|S_IWUSR));

  		// If shmget fails:
  		if (id == -1)
    			{
      				cout << "Failed to create shared memory segment" << endl;
      				return 1;
    			}

  		cout << "Got shared memory with id " << id << endl;

  		// Attach a memory segment to the structure:
  		semlock = (sema *)shmat(id, NULL, 0);

  		// If the attachment fails:
  		if (semlock == (void *)-1)
    			{
      				cout << "Failed to attach memory segment" << endl;
      				return 1;
    			}

  		cout << "Attached to shared memory at " << semlock << endl;

  		// Initialize 5 semaphores for the shared memory:
  		for(int i = 0; i < 5; i++)
    			{
     				 ret = sem_init(&(semlock->arr[i]), 1, 1);

      				// If the initalization fails:
      				if (ret == -1)
					{
	  					cout << "Failed to initialize semaphore" << endl;
					}
				else
					{
            					if(i == 0)
							{
                						cout << "Initialized semaphore # 0: (NE) to 1" << endl;
            						}
            					if(i == 1)
							{
                						cout << "Initialized semaphore # 1: (NW) to 1" << endl;
            						}
            					if(i == 2)
							{
                						cout << "Initialized semaphore # 2: (SE) to 1" << endl;
            						}
            					if(i == 3)
							{
                						cout << "Initialized semaphore # 3: (SW) to 1" << endl;
            						}
            					if(i == 4)
							{
               							 cout << "Initialized semaphore # 4 for cout." << endl << endl;
            						}
        				}
    			}
      		// Loop 4 times for the 4 processes:
      		for (i = 0; i < 4; i++)
        		{
	  			// Fork a child:
          			ret = fork();
				if(ret < 0)
					{
						cout << "Failed to create process: " << strerror(error) << endl;
            					return 1;
        				}
	  			pids[i] = ret;
	  			// Child process:
          			if (pids[i] == 0)
            				{
	      					worker(i, semlock, streets);
            				}
			}
    					// Parent process:
		for (i = 0; i < 4; i++)
			{
				wait(0);
			}

  		// Shared memory detach:
  		ret = shmdt((void *)semlock);
  		if (ret == -1)
    			{
      				cout << "Failed to detach shared memory segment" << endl;
      				return 1;
    			}

  		// Free the shared memory
  		ret = shmctl(id, IPC_RMID, NULL); 
  		if (ret == -1)
    			{
      				cout << "Failed to free the shared memory" << endl;
      				return 1;
    			}

  		return 0;
	}

void worker(int i, sema *semlockp, Street streets[4])
	{

  		// No buffering
		cout << unitbuf;

		for (int j = 1; j < 10; j++)
    			{
      				// Lincoln Highway west:
      				if (i == 0)
					{
						processStreetActivity(i, j, 0, 1, semlockp, streets);
					}
				//Annie Glidden North
				if (i == 1)
                                        {
						processStreetActivity(i, j, 2, 0, semlockp, streets);
                                        }
				if (i == 2)
                                        {
						processStreetActivity(i, j, 3, 2, semlockp, streets);
                                        }
				if (i == 3)
                                        {
						processStreetActivity(i, j, 1, 3, semlockp, streets);
                                        }
			}

  		exit(0);
	}

void semaphoreWait(sem_t *semlockp)
	{
  		// Wait for the semophore lock and take when available:
  		int ret = sem_wait(semlockp);

 		 // If the semaphore lock isn't available, wait again:
  		while (ret == -1)
    			{
      				// Print error message:
      				if(errno != EINTR)
					{
	  					cout << "Failed to lock semaphore" << endl;
	  					return;
					}
      				// Wait for the semaphore again:
      				ret = sem_wait(semlockp);
    			}
	}

void unlockSemaphore(sem_t *semlockp)
	{
  		// Unlock the semaphore to give access to it:
  		int ret = sem_post(semlockp);

  		if (ret == -1)
			{
    				cout << "Failed to unlock semaphore" << endl;
			}
	}

void processStreetActivity(int i, int j, int startSection, int endSection, sema *semlockp, Street streets[4])
	{
		if(j == 1)
              		{
                        	// Print initializing semaphore message:
                                semaphoreWait(&(semlockp->arr[4]));
                                cout << "Starting process for street " << streets[i].getStreetNumber() << ": " 
                                << streets[i].getStreetName() << " " << streets[i].getTravelDirection() << endl;
                                unlockSemaphore(&(semlockp->arr[4]));
                        }
                // Wait for the first lock:
                semaphoreWait(&(semlockp->arr[startSection]));

                // First semaphore obtained:
                semaphoreWait(&(semlockp->arr[4]));
                cout << "On "<< streets[i].getStreetName() << " " << streets[i].getTravelDirection() << ", car " 
                << j << " has obtained lock for " << streets[i].getFirstSection() << endl;
                unlockSemaphore(&(semlockp->arr[4]));

                // Wait for the second lock:
                semaphoreWait(&(semlockp->arr[endSection]));

                // Second semaphore obtained:
                semaphoreWait(&(semlockp->arr[4]));
                cout << "On " << streets[i].getStreetName() << " " << streets[i].getTravelDirection() << ", car " 
                << j << " has obtained lock for " << streets[i].getSecondSection() << endl << "On " << streets[i].getStreetName() << " " 
                << streets[i].getTravelDirection() << ", car " << j << " has obtained both locks." << endl;
                unlockSemaphore(&(semlockp->arr[4]));

                // After succesffully crossing:
                semaphoreWait(&(semlockp->arr[4]));
                cout << "On " << streets[i].getStreetName() << " " << streets[i].getTravelDirection() << ", car " << j << " has crossed." << endl;
                unlockSemaphore(&(semlockp->arr[4]));

                // Release the first lock:
                unlockSemaphore(&(semlockp->arr[startSection]));

                semaphoreWait(&(semlockp->arr[4]));
                cout << "On " << streets[i].getStreetName() << " " << streets[i].getTravelDirection() << ", car " << j << " has unlocked " << streets[i].getFirstSection() << endl;
                unlockSemaphore(&(semlockp->arr[4]));

                // Release the second lock:
                unlockSemaphore(&(semlockp->arr[endSection]));

                semaphoreWait(&(semlockp->arr[4]));
                cout << "On " << streets[i].getStreetName() << " " << streets[i].getTravelDirection() << ", car " << j << " has unlocked " << streets[i].getSecondSection() << endl << endl;
                unlockSemaphore(&(semlockp->arr[4]));

	}

