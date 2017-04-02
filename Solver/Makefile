CXX = g++
SOURCES = Graph/Graph.cpp Algorithms/Algorithms.cpp
CFLAGS = -Wall -g -Ofast
LDFLAGS = -lm -lglpk
.PHONY = clean

all: main

main: $(SOURCES:.cpp=.o) $(LDFLAGS)

clean:
	rm main
	rm Graph/*.o
	rm Algorithms/*.o
