CFLAGS=-Wall -ggdb3 -pedantic
CC=gcc


all: 01_print-pid 02_system 03_fork 04_fork-exec 05_sigusr1 06_zombie 07_sigchld

01_print-pid: 01_print-pid.c
	$(CC) $(CFLAGS) $< -o $@
	
02_system: 02_system.c
	$(CC) $(CFLAGS) $< -o $@

03_fork: 03_fork.c
	$(CC) $(CFLAGS) $< -o $@

04_fork-exec: 04_fork-exec.c
	$(CC) $(CFLAGS) $< -o $@

05_sigusr1: 05_sigusr1.c
	$(CC) $(CFLAGS) $< -o $@

06_zombie: 06_zombie.c
	$(CC) $(CFLAGS) $< -o $@

07_sigchld: 07_sigchld.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	find . -maxdepth 1 -type f -executable -delete

