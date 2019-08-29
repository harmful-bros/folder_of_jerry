CC = gcc
CFLAGS = -W -Wall --save-temps
TARGET = test

SRCS := $(wildcard *.c)

OBJS := $(SRCS:.c=.o)
DEFS := $(SRCS:.c=.d)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.d : %.c
	$(CC) -M -MP -MT "$(@:.d=.o) $@" -MF $@ $<

-include $(DEFS)

clean :
	rm -rf *.o *.d *.i *.s *.bc $(TARGET)
