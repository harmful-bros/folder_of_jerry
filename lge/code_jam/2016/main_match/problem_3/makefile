CXX = g++
CXXFLAGS = -W -Wall -std=c++11
TARGET = test

OBJS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $<

clean :
	rm -rf *.o $(TARGET)
