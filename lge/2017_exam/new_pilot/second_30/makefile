CXX = g++
CXXFLAGS = -W -Wall -g -std=c++11
TARGET = test

SRCS := $(wildcard *.cpp)

OBJS := $(SRCS:.cpp=.o)
DEFS := $(SRCS:.cpp=.d)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.d : %.cpp
	$(CXX) -M -MP -MT "$(@:.d=.o) $@" -MF $@ $<

-include $(DEFS)

clean :
	rm -rf *.o $(TARGET)

