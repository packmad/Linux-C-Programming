CFLAGS=-Wall -ggdb3 -pedantic
LDFLAGS=-pthread
CC=gcc


all: 4.11_job-queue-mutex 4.12_job-queue-semaphore 4.13_condvar 4.15_thread-pid 4.1_thread-create 4.2-3_thread-create2 4.4.1_pthread-equal 4.4_primes 4.5_detached 4.6_critical-section 4.7_tsd 4.8_cleanup

4.11_job-queue-mutex: 4.11_job-queue-mutex.c


4.12_job-queue-semaphore: 4.12_job-queue-semaphore.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
4.13_condvar: 4.13_condvar.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
4.15_thread-pid: 4.15_thread-pid.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
4.1_thread-create: 4.1_thread-create.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
4.2-3_thread-create2: 4.2-3_thread-create2.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
4.4.1_pthread-equal: 4.4.1_pthread-equal.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
4.4_primes: 4.4_primes.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
4.5_detached: 4.5_detached.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
4.6_critical-section: 4.6_critical-section.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
4.7_tsd: 4.7_tsd.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
4.8_cleanup: 4.8_cleanup.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

clean:
	find . -maxdepth 1 -type f -executable -delete
