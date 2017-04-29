CFLAGS=-Wall -ggdb3 -pedantic
LDFLAGS=-pthread
CC=gcc

all: thread-sync-01 thread-sync-02-sem_t thread-sync-03-mutex

thread-sync-01: thread-sync-01.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

thread-sync-02-sem_t: thread-sync-02-sem_t.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

thread-sync-03-mutex: thread-sync-03-mutex.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

clean:
	find . -maxdepth 1 -type f -executable -delete
	rm *.log 2> /dev/null

