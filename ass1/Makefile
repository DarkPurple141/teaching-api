
CC=gcc
CFLAGS=-Wall -Werror -std=c99 #-DDBUG=1

testBuffer: testBuffer.o textbuffer.o
testBuffer.o : textbuffer.h testBuffer.c
textbuffer.o : textbuffer.h textbuffer.c

mktrace : mktrace.c

clean:
	rm testBuffer *.o
