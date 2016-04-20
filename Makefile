#Makefile for postscipt interpreter

#Usage: make main to compile wit our test main
#		make test to compile with catch 

COMPILER=g++
STD=c++11

FLAGS = -std=$(STD)  -Wall -pedantic -Wno-deprecated-declarations 

# Add new source files here
FILES = utils.cpp shape.cpp circle.cpp polygon.cpp rectangle.cpp scaled.cpp rotate.cpp layered.cpp spacer.cpp

main: main.cpp $(FILES) 
	$(COMPILER)  $^ $(FLAGS) -o $@

test: test.cpp $(FILES)
	$(COMPILER)  $^ $(FLAGS) -o $@

clean:
	rm -rf test main travis
