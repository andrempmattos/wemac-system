TESTFILE = ProductTest.cpp

CXX = g++
CXXFLAGS = -Wall -std=c++11
DIR = ../firmware/
SRCS = $(TESTFILE) $(DIR)Queue.cpp $(DIR)Node.cpp $(DIR)Log.cpp $(DIR)Product.cpp
OBJS = ${SRCS:.cpp=.o}

all: linux

linux: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o VM_application_test
	chmod +x VM_application_test

Queue: $@.cpp $@.hpp
	$(CXX) $(CXXFLAGS) $@.cpp -c

Node: $@.cpp $@.hpp
	$(CXX) $(CXXFLAGS) $@.cpp -c

Log: $@.cpp $@.hpp
	$(CXX) $(CXXFLAGS) $@.cpp -c

Product: $@.cpp $@.hpp
	$(CXX) $(CXXFLAGS) $@.cpp -c	

main: $@.cpp $@.hpp $(OBJS)
	$(CXX) $(CXXFLAGS) $@.cpp -c

clean:
	rm -rf *.o VM_application_test