CFLAGS=-Wall -fno-stack-protector
CC=gcc

all: 01_bof-simple

01_bof-simple: 01_bof-simple.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	find . -maxdepth 1 -type f -executable -delete
