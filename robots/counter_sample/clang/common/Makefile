OBJS = $(patsubst %c, %o, $(wildcard *.c))

ROOT_DIR ?= ..
INCLUDE ?= ../include

all: $(OBJS)
	@mv *.o $(ROOT_DIR)/out

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I$(INCLUDE)

clean:
	rm -rf *.o
