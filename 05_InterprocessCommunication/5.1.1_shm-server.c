#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sysexits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SHMSZ 27

int main() {
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    /*
     * We'll name our shared memory segment
     * "5678".
     */
    key = 5678;

    /*
     * Create the segment.
     */
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    /*
     * Now we attach the segment to our data space.
     */
    if ((shm = shmat(shmid, 0, 0)) == (char *) -1) {
        perror("Error");
        exit(EX_OSFILE);
    }

    /*
     * Now put some things into the memory for the
     * other process to read.
     */
    s = shm;

    for (c = 'a'; c <= 'z'; c++)
        *s++ = c;
    *s = 0x0;

    /*
     * we wait until the other process changes the first character 
     * of our memory to '*', indicating that it has read what 
     * we put there.
     * CAUTION: BUSY WAIT IS THE WRONG WAY!
     */
    while (*shm != '*') // WRONG!!!
        sleep(1);
        
    /* deallocate the shared memory segment */
	shmctl(shmid, IPC_RMID, 0);
    exit(0);
}

