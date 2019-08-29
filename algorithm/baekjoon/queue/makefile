CC = c++
CFLAGS = -std=c++11 -stdlib=libc++ -W -Wall
TARGET = test

OBJS = $(patsubst *.cpp, %.o, $(wildcard *.cpp))

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -rf *.o $(TARGET)
