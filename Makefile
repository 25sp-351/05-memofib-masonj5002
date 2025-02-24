all: factorial

CC = gcc
CFLAGS = -Wall

factorial: factorial.o
	gcc $(CFLAGS) factorial.o -o factorial

factorial.o: factorial.c
	gcc $(CFLAGS) -c factorial.c

clean:
	rm -f *.o factorial