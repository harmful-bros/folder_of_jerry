CXX = g++
CXXFLAGS = -W -Wall -std=c++11
TAREGET = test

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
DEFS := $(SRCS:.cpp=.d)

all : $(TAREGET)

$(TAREGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.d : %.cpp
	$(CXX) -M -MP -MT "$(@:.d=.o) $@" -MF $@ $<

-include $(DEFS)

clean :
	rm -rf *.d *.o $(TAREGET)
