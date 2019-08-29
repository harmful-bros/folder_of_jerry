CC = gcc
CFLAGS = -W -Wall
TARGEt = test

SRCS := $(wildcard *.c)
OBSj := $(SRCS:.c=.o)

all : $(TARGEt)

$(TARGEt) : $(OBSj)
	$(CC) -o $@ $^

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf *.o $(TARGEt)
