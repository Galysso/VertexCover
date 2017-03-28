CXX = g++
SOURCES = Graph/Graph.cpp Functions/Functions.cpp
CFLAGS = -Wall -g -Ofast
LDFLAGS =
.PHONY = clean

all: main

main: $(SOURCES:.cpp=.o) $(LDFLAGS)

clean:
	rm main
	rm Graph/*.o
