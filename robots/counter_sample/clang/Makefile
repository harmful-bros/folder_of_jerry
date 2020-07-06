TARGET = cmain

ROOT_DIR ?= $(shell pwd)
OUT_DIR = $(ROOT_DIR)/out
SRC_DIR = $(ROOT_DIR)/common

export CC = gcc
export CFLAGS = -W -Wall -g -ggdb
export INCLUDE := $(ROOT_DIR)/include

all: subdirs $(TARGET)

$(TARGET):
	$(CC) -static -o $@ $(wildcard $(OUT_DIR)/*.o) -lpthread
	@mv $(TARGET) $(OUT_DIR)

subdirs:
	@mkdir -p $(OUT_DIR)
	@for dir in $(SRC_DIR); do \
		make -C $$dir || exit $? ; \
	done

clean:
	@for dir in $(SRC_DIR); do \
		make clean -C $$dir; \
	done
	cd $(OUT_DIR) && rm -rf *.o $(TARGET)
