#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#define FILE_LENGTH 0x100

/**
 * Listing 5.5 (mmap-write.c) Write a Random Number to a Memory-Mapped File
 */


int random_range(unsigned const low, unsigned const high)
{
    unsigned const range = high - low + 1;
    return low + (int)(((double)range)*rand()/(RAND_MAX + 1.0));
}


int main(int argc, char* const argv[])
{
    int fd;
    void* file_memory;

	/* Seed the random number generator. */
    srand(time(NULL));

	if (argc != 2)
		exit(-1);
	/* Prepare a file large enough to hold an unsigned integer. */
    fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    lseek(fd, FILE_LENGTH+1, SEEK_SET);
    write(fd, "", 1);
    lseek(fd, 0, SEEK_SET);

	/* Create the memory mapping. */
    file_memory = mmap(0, FILE_LENGTH, PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);

	/* Write a random integer to memory-mapped area. */
    sprintf((char*)file_memory, "%d\n", random_range(-100, 100));

	/* Release the memory (unnecessary because the program exits). */
    munmap(file_memory, FILE_LENGTH);

    return 0;
}


/*
The flags argument determines whether updates to the mapping are visible
to other processes mapping the same region, and whether updates are 
carried through to the underlying file. 
This behavior is determined by including exactly one of the
following values in flags:

MAP_SHARED
	  Share this mapping.  Updates to the mapping are visible to other processes
	  that map this file, and are carried through to the underlying  file.   (To
	  precisely  control when updates are carried through to the underlying file
	  requires the use of msync(2).)

MAP_PRIVATE
	  Create a private copy-on-write mapping.  Updates to the  mapping  are  not
	  visible  to  other  processes  mapping  the same file, and are not carried
	  through to the underlying file.  It is unspecified whether changes made to
	  the file after the mmap() call are visible in the mapped region.

*/
