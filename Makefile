# Make Example Program
all: HashString.o main.o
	gcc -o HashString HashString.o main.o

HashString.o: HashString.h HashString.c
	gcc -c HashString.c

main.o: HashString.h main.c
	gcc -c main.c

.PHONY: clean
clean:
	rm *.o
	rm HashString

# vim: set noexpandtab:
