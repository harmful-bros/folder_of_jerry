CXX = g++
CXXFLAGS = -W -Wall
TARGET = test

OBJS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean :
	rm -rf *.o %(TARGET)
