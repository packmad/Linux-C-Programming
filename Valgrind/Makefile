CFLAGS=-Wall -pedantic -ggdb3
LDFLAGS=-pthread
CC=gcc

all: memory_leak race_condition quicksort

memory_leak: memory_leak.c  
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

quicksort: quicksort.c  
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

race_condition: race_condition.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

clean:
	find . -maxdepth 1 -type f -executable -delete

