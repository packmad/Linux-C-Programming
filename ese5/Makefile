CFLAGS=-Wall -ggdb3 -pedantic
LDFLAGS=-pthread
CC=gcc


all: 00_array_sum 01_equals 02_detached 03_critical-section 04_tsd 05_cleanup 06_valgrind

00_array_sum: 00_array_sum.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

01_detached: 01_equals.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

02_detached: 02_detached.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

03_critical-section: 03_critical-section.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
	
04_tsd: 04_tsd.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
	
05_cleanup: 05_cleanup.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
	
06_valgrind: 06_valgrind.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

clean:
	find . -maxdepth 1 -type f -executable -delete

