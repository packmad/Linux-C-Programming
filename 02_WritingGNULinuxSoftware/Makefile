CFLAGS=-Wall -ggdb3 -pedantic
CC=gcc


all: 01_arglist 02_getopt_long 03_check_buffer

01_arglist: 01_arglist.c
	$(CC) $(CFLAGS) $< -o $@

02_getopt_long: 02_getopt_long.c
	$(CC) $(CFLAGS) $< -o $@

03_check_buffer: 03_check_buffer.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	find . -maxdepth 1 -type f -executable -delete

