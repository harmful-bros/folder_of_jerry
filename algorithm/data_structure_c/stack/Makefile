CC = gcc
CFLAGS = -W -Wall
TARGET = test

INCD = .

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
INC_OPTS := -I$(INCD)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) $(INC_OPTS) -c $< -o $@

clean:
	rm -rf *.o $(TARGET)

