
// Simple program demonstrating shared memory in POSIX systems.
// Based on textbook fig. 3.16

#include <sys/shm.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    // the identifier for the shared memory segment
    int segment_id;

    // a pointer to the shared memory segment
    char* shared_memory;

    // the size (in bytes) of the shared memory segment 
    const int segment_size = 4096;

    // allocate  a shared memory segment
    segment_id = shmget(IPC_PRIVATE, segment_size, S_IRUSR | S_IWUSR);

    // attach the shared memory segment
    shared_memory = (char *) shmat(segment_id, NULL, 0);
    fprintf(stdout, "shared memory segment %d attached at address %p\n",
       segment_id, shared_memory);

    // write a message to the shared memory segment  
    sprintf(shared_memory, "Hi there!");

    // now print out the string from shared memory
    fprintf(stdout, "|%s|\n", shared_memory);

    // now detach the shared memory segment 
    if (shmdt(shared_memory) == -1) {
        fprintf(stderr, "Unable to detach\n");
    }

    // now remove the shared memory segment
    if (shmctl(segment_id, IPC_RMID, NULL) == -1) {
        fprintf(stderr, "Unable to free shared memory\n");
    }

    return 0;
}
