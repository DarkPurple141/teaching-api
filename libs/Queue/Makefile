
CC = gcc
CFLAGS = -Wall -Werror 

BINS = main

OBJS = main.o queue.o

all : $(BINS)

main : main.o queue.o

main.o : main.c queue.h
queue.o : queue.c queue.h

clean :
	rm -f $(BINS) *.o core