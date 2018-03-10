CFLAGS=-Wall -ggdb3 -pedantic
LDFLAGS=-pthread
CC=gcc


all: 01_thread-create 02-03_thread-create2 04_primes 05_detached 06_critical-section 07_tsd 08_cleanup 11_job-queue-mutex 12_job-queue-semaphore 13_condvar 15_thread-pid pthread_equal

01_thread-create: 01_thread-create.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

02-03_thread-create2: 02-03_thread-create2.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

04_primes: 04_primes.c  
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

04_thread-create2: 04_thread-create2.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

05_detached: 05_detached.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

06_critical-section: 06_critical-section.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

07_tsd: 07_tsd.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

08_cleanup: 08_cleanup.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

11_job-queue-mutex: 11_job-queue-mutex.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

12_job-queue-semaphore: 12_job-queue-semaphore.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

13_condvar: 13_condvar.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

15_thread-pid: 15_thread-pid.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

pthread_equal: pthread_equal.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

clean:
	find . -maxdepth 1 -type f -executable -delete
