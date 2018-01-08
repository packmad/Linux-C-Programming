PROJECT := sample_calc
CC = gcc
CFLAGS = -Wall -pedantic
DEBUG = -ggdb3 -D DEBUG
LDFLAGS = -pthread

HEADERS := $(wildcard *.h)
CFILES := $(wildcard *.c)
OBJECTS := $(wildcard *.o)


all: libcalc $(PROJECT)

libcalc: calc.c calc.h
	$(CC) -c $(CFLAGS) $<

$(PROJECT): main.c
	$(CC) $(CFLAGS) $(wildcard *.o) -o $(PROJECT)
	$(CC) -c $(CFLAGS) $<
	
clean:
	@rm $(PROJECT)
	@rm $(OBJECTS)
