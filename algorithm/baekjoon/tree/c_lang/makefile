CC = gcc
CFLAGS = -W -Wall
TARGET = test

OBJS = $(patsubst %.c, %.o, $(wildcard *.c))

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -rf *.o $(TARGET)
