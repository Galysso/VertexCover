CXX = g++
SOURCES = Graph/Graph.cpp Algorithms/Algorithms.cpp Algorithms/Functions.cpp
CXXFLAGS = -std=c++11 
CFLAGS = -Wall -g -Ofast
LDFLAGS = -lm -lglpk
.PHONY = clean

all: main

main: $(SOURCES:.cpp=.o) $(LDFLAGS)

clean:
	rm main
	rm Graph/*.o
	rm Algorithms/*.o
