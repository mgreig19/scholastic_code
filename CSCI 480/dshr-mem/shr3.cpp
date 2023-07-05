
// Shared memory using System V API
// Based on textbook fig. 3.16
// (incorrectly called POSIX API in book)

#include <sys/shm.h>
#include <sys/stat.h>

#include <cstring>
#include <cstdlib>

#include <iostream>
#include <iomanip>


using namespace std;

int main()
{
    // the identifier for the shared memory segment
    int segment_id;

    // a pointer to the shared memory segment
    char* shared_memory;

    // the size (in bytes) of the shared memory segment 
    const int segment_size = 4096;

    // temp. return code
    int ret;

    // allocate  a shared memory segment
    segment_id = shmget(IPC_PRIVATE, segment_size, S_IRUSR | S_IWUSR);
    if (segment_id == -1)
      {
        cout << "Failed to allocate shared memory" << endl;
        return 1;
      }

    // attach the shared memory segment
    shared_memory = (char *) shmat(segment_id, NULL, 0);
    if (shared_memory == (char *)-1)
      {
        cout << "Failed to attach to shared memory" << endl;
        return 1;
      }

    cout << "shared memory segment " << segment_id
         << " attached at address "  << (void *)shared_memory << endl;

    // write a message to the shared memory segment  
    strcpy(shared_memory, "Hi there!");

    // now print out the string from shared memory
    cout << "value at that address is |" << shared_memory << "|" << endl;

    // now detach the shared memory segment 

    ret = shmdt(shared_memory);
    if (ret == -1)
      {
        cout << "Unable to detach" << endl;
        return 1;
      }

    // now remove the shared memory segment
    ret = shmctl(segment_id, IPC_RMID, NULL); 
    if (ret == -1)
      {
        cout << "Unable to free the shared memory" << endl;
        return 1;
      }

    return 0;
}
