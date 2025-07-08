# Title: Heaps
# Author: Muhammed Huseyin AYDIN
# ID: 22203683
# Section: 1
# Assignment: 2
# Description: Makefile

CXX = g++

CXXFLAGS = -Wall -c

.PHONY: all
.PHONY: test
.PHONY: clean

all: exe

exe: main.o RequestQueue.o Request.o simulator.o
	$(CXX) main.o RequestQueue.o Request.o simulator.o -o simulator

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main.o

simulator.o: simulator.cpp
	$(CXX) $(CXXFLAGS) simulator.cpp  -o simulator.o

RequestQueue.o: RequestQueue.cpp
	$(CXX) $(CXXFLAGS) RequestQueue.cpp -o RequestQueue.o

Request.o: Request.cpp
	$(CXX) $(CXXFLAGS) Request.cpp -o Request.o

clean:
	rm *.o simulator
