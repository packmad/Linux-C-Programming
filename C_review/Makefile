CFLAGS=-Wall -ggdb3 -pedantic
CC=gcc


all: 00_bad_things  01_data_types  02_array  03_pointers  04_function-pointers  05_malloc 06_union 07_enum


00_bad_things: 00_bad_things.c
	$(CC) $(CFLAGS) $< -o $@

01_data_types: 01_data_types.c
	$(CC) $(CFLAGS) $< -o $@

02_array: 02_array.c
	$(CC) $(CFLAGS) $< -o $@

03_pointers: 03_pointers.c
	$(CC) $(CFLAGS) $< -o $@

04_function-pointers: 04_function-pointers.c
	$(CC) $(CFLAGS) $< -o $@

05_malloc: 05_malloc.c
	$(CC) $(CFLAGS) $< -o $@

06_union: 06_union.c
	$(CC) $(CFLAGS) $< -o $@

07_enum: 07_enum.c
	$(CC) $(CFLAGS) $< -o $@


clean:
	find . -maxdepth 1 -type f -executable -delete

