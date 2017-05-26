CFLAGS=-Wall -ggdb3 -pedantic
CC=gcc


all: 01_print-pid 02_system 03_fork 04_fork-exec

01_print-pid: 01_print-pid.c
	$(CC) $(CFLAGS) $< -o $@
	
02_system: 02_system.c
	$(CC) $(CFLAGS) $< -o $@

03_fork: 03_fork.c
	$(CC) $(CFLAGS) $< -o $@

04_fork-exec: 04_fork-exec.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	find . -maxdepth 1 -type f -executable -delete

