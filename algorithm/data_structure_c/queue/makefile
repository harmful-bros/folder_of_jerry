CC = gcc
CFLAGS = -W -Wall -g -ggdb
TARGET = test

INCD = ../stack

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
INC_OPTS := -I$(INCD)

all : $(TARGET)

$(TARGET) : $(OBJS) $(INCD)/linked_list.o
	$(CC) -o $@ $^

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) $(INC_OPTS) -c $< -o $@

clean:
	rm -rf *.o $(TARGET)
