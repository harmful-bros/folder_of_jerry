CC = gcc
CFLAGS = -W -Wall -O0 -std=gnu11 -g
TARGET = test

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^

.SUFFIXES : .c .o
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(TARGET)
