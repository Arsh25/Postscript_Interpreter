#Makefile for postscipt interpreter

#Usage: make main to compile wit our test main
#		make test to compile with catch 

COMPILER=g++
STD=c++11

FLAGS = -std=$(STD) -Wall -pedantic -Wno-deprecated-declarations 

main: main.cpp utils.cpp shape.cpp circle.cpp polygon.cpp
	$(COMPILER)  $^ $(FLAGS) -o $@

test: test.cpp utils.cpp shape.cpp circle.cpp polygon.cpp
	$(COMPILER)  $^ $(FLAGS) -o $@

clean:
	rm -rf test main
