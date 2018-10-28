TESTFILE = QueueTest.cpp

CXX = g++
CXXFLAGS = -Wall -std=c++11
DIR = ../firmware/
SRCS = $(TESTFILE) $(DIR)Queue.cpp $(DIR)Node.cpp
OBJS = ${SRCS:.cpp=.o}

all: linux

linux: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o VM_application
	chmod +x VM_application

Queue: $@.cpp $@.hpp
	$(CXX) $(CXXFLAGS) $@.cpp -c

Node: $@.cpp $@.hpp
	$(CXX) $(CXXFLAGS) $@.cpp -c

main: $@.cpp $@.hpp $(OBJS)
	$(CXX) $(CXXFLAGS) $@.cpp -c

clean:
	rm -rf *.o VM_application