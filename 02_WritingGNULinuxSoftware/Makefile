CFLAGS=-Wall -ggdb3 -pedantic
CC=gcc


all: 00_standard_streams 01_arglist 02_getopt_long 03_print-env 04_client

00_standard_streams: 00_standard_streams.c
	$(CC) $(CFLAGS) $< -o $@

01_arglist: 01_arglist.c
	$(CC) $(CFLAGS) $< -o $@

02_getopt_long: 02_getopt_long.c
	$(CC) $(CFLAGS) $< -o $@

03_print-env: 03_print-env.c
	$(CC) $(CFLAGS) $< -o $@

04_client: 04_client.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	find . -maxdepth 1 -type f -executable -delete

