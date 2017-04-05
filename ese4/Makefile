CFLAGS=-Wall -ggdb3 -pedantic
LDFLAGS=-pthread
CC=gcc


all: 01_zombie 02_sigusr1 03_thread-create 04_thread-create2 05_primes

01_zombie: 01_zombie.c
	$(CC) $(CFLAGS) $< -o $@	

02_sigusr1: 02_sigusr1.c
	$(CC) $(CFLAGS) $< -o $@	

03_thread-create: 03_thread-create.c  
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

04_thread-create2: 04_thread-create2.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

05_primes: 05_primes.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

clean:
	find . -maxdepth 1 -type f -executable -delete
