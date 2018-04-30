CFLAGS=-Wall -ggdb3 -pedantic
CC=gcc


all: 3.1_print-pid 3.2_system 3.3_fork 3.4_fork-exec 3.5_sigusr1 3.6_zombie 3.7_sigchld

3.1_print-pid: 3.1_print-pid.c
	$(CC) $(CFLAGS) $< -o $@
	
3.2_system: 3.2_system.c
	$(CC) $(CFLAGS) $< -o $@

3.3_fork: 3.3_fork.c
	$(CC) $(CFLAGS) $< -o $@

3.4_fork-exec: 3.4_fork-exec.c
	$(CC) $(CFLAGS) $< -o $@

3.5_sigusr1: 3.5_sigusr1.c
	$(CC) $(CFLAGS) $< -o $@

3.6_zombie: 3.6_zombie.c
	$(CC) $(CFLAGS) $< -o $@

3.7_sigchld: 3.7_sigchld.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	find . -maxdepth 1 -type f -executable -delete

