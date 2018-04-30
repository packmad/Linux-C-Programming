CFLAGS=-Wall -ggdb3 -pedantic
CC=gcc


all: 5.1.1_shm-server 5.1.2_shm-client 5.5_mmap-write 5.6_mmap-read 5.7_pipe 5.8_dup2 5.9_popen 5.10_socket-server 5.11_socket-client 5.12_socket-inet

5.1.1_shm-server: 5.1.1_shm-server.c
	$(CC) $(CFLAGS) $< -o $@

5.1.2_shm-client: 5.1.2_shm-client.c
	$(CC) $(CFLAGS) $< -o $@

5.5_mmap-write: 5.5_mmap-write.c
	$(CC) $(CFLAGS) $< -o $@

5.6_mmap-read: 5.6_mmap-read.c
	$(CC) $(CFLAGS) $< -o $@

5.7_pipe: 5.7_pipe.c
	$(CC) $(CFLAGS) $< -o $@

5.8_dup2: 5.8_dup2.c
	$(CC) $(CFLAGS) $< -o $@

5.9_popen: 5.9_popen.c
	$(CC) $(CFLAGS) $< -o $@

5.10_socket-server: 5.10_socket-server.c
	$(CC) $(CFLAGS) $< -o $@

5.11_socket-client: 5.11_socket-client.c
	$(CC) $(CFLAGS) $< -o $@

5.12_socket-inet: 5.12_socket-inet.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	find . -maxdepth 1 -type f -executable -delete

