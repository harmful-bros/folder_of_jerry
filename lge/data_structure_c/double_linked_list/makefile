CC = gcc
CFLAGS = -W -Wall
TARGET = test

OBJ = $(patsubst %.c, %.o, $(wildcard *.c))

all : $(TARGET)

$(TARGET) : $(OBJ) ../single_linked_list/linked_list.o
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -rf *.o $(TARGET)
