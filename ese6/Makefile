CFLAGS=-Wall -ggdb3 -pedantic
LDFLAGS=-pthread
CC=gcc


all: 01_job-queue-mutex 02_job-queue-semaphore 03_condvar 04_pipe 05_dup2 06_popen 07_socket_client 07_socket_server


01_job-queue-mutex: 01_job-queue-mutex.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

02_job-queue-semaphore: 02_job-queue-semaphore.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

03_condvar: 03_condvar.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
	
04_pipe: 04_pipe.c
	$(CC) $(CFLAGS) $< -o $@
	
05_dup2: 05_dup2.c
	$(CC) $(CFLAGS) $< -o $@

06_popen: 06_popen.c
	$(CC) $(CFLAGS) $< -o $@
	
07_socket_client: 07_socket_client.c
	$(CC) $(CFLAGS) $< -o $@

07_socket_server: 07_socket_server.c
	$(CC) $(CFLAGS) $< -o $@


clean:
	find . -maxdepth 1 -type f -executable -delete
	rm *.log 2> /dev/null

