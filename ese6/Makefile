CFLAGS=-Wall -ggdb3 -pedantic
LDFLAGS=-pthread
CC=gcc


all: 01_job-queue2

01_job-queue2: 01_job-queue2.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

clean:
	find . -maxdepth 1 -type f -executable -delete
	rm *.log 2> /dev/null

