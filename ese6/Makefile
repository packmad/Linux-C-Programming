CFLAGS=-Wall -ggdb3 -pedantic
LDFLAGS=-pthread
CC=gcc


all: 01_job-queue-mutex 02_job-queue-semaphore

01_job-queue-mutex: 01_job-queue-mutex.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

02_job-queue-semaphore: 02_job-queue-semaphore.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@


clean:
	find . -maxdepth 1 -type f -executable -delete
	rm *.log 2> /dev/null

