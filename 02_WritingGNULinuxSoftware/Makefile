CFLAGS=-Wall -ggdb3 -pedantic
CC=gcc


all: 0.0_standard_streams 2.1_arglist 2.2_getopt_long 2.3_print-env 2.4_client

0.0_standard_streams: 0.0_standard_streams.c
	$(CC) $(CFLAGS) $< -o $@

2.1_arglist: 2.1_arglist.c
	$(CC) $(CFLAGS) $< -o $@

2.2_getopt_long: 2.2_getopt_long.c
	$(CC) $(CFLAGS) $< -o $@

2.3_print-env: 2.3_print-env.c
	$(CC) $(CFLAGS) $< -o $@

2.4_client: 2.4_client.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	find . -maxdepth 1 -type f -executable -delete

