CXX = g++
CXXFLAGS = -W -Wall -std=c++11 --save-temps
TARGET = test

SRCS := $(wildcard *.cpp)

OBJS := $(SRCS:.cpp=.o)
DEFS := $(SRCS:.cpp=.d)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ -lm

%.d : %.cpp
	$(CXX) -M -MP -MT "$(@:.d=.o) $@" -MF $@ $<

-include $(DEFS)

clean :
	rm -f *.ii *.o *.s *.d $(TARGET)
