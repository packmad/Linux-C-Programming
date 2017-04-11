CFLAGS=-Wall -ggdb3 -pedantic
LDFLAGS=-pthread
CC=gcc


all: 01_equals 02_detached 03_critical-section 04_tsd

01_detached: 01_equals.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

02_detached: 02_detached.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

03_critical-section: 03_critical-section.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
	
04_tsd: 04_tsd.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
	

clean:
	find . -maxdepth 1 -type f -executable -delete
	rm *.log 2> /dev/null

