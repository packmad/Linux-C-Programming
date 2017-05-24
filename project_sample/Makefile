PROJECT := sample_calc
CC = gcc
CFLAGS = -Wall -pedantic
DEBUG = -ggdb3 -D DEBUG
LDFLAGS = -pthread
OBJECTS := $(wildcard *.o)


all: libcalc main $(PROJECT)

libcalc: calc.c calc.h
	$(CC) -c $(CFLAGS) $<

main: main.c
	$(CC) -c $(CFLAGS) $<
	
$(PROJECT): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(PROJECT)
	
clean:
	@rm $(PROJECT)
	@rm $(OBJECTS)
