CFLAGS=-Wall -pedantic
LDFLAGS=-pthread
CC=gcc

all: bof-simple valgrind

bof-simple: bof-simple.c
	$(CC) $(CFLAGS) -fno-stack-protector $< -o $@

valgrind: valgrind.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
clean:
	find . -maxdepth 1 -type f -executable -delete
