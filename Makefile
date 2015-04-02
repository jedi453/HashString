
CC = gcc
CFLAGS =
LDFLAGS =

# Make Example Program
all: HashString.o main.o
	$(CC) -o HashString HashString.o main.o $(LDFLAGS)

HashString.o: HashString.h HashString.c
	$(CC) -c HashString.c $(CFLAGS)

main.o: HashString.h main.c
	$(CC) -c main.c $(CFLAGS)

.PHONY: clean
clean:
	rm *.o
	rm HashString

run: all
	./HashString

# vim: set noexpandtab:
