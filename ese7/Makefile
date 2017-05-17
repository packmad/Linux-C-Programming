CFLAGS=-Wall -ggdb3 -pedantic
CC=gcc


all: 01_shm-client 01_shm-server 02_mmap-read 02_mmap-write

01_shm-client: 01_shm-client.c
	$(CC) $(CFLAGS) $< -o $@

01_shm-server: 01_shm-server.c
	$(CC) $(CFLAGS) $< -o $@

02_mmap-read: 02_mmap-read.c
	$(CC) $(CFLAGS) $< -o $@

02_mmap-write: 02_mmap-write.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	find . -maxdepth 1 -type f -executable -delete

