CC = gcc
CFLAGS = -W -Wall
TARGET = test

OBJ = $(patsubst %.c, %.o, $(wildcard *.c))

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean : 
	rm -rf *.o $(TARGET)
