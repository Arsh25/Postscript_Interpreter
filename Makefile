#Makefile for postscipt interpreter

#Usage: make main to compile wit our test main
#		make test to compile with catch 

COMPILER=g++-4.9
STD=c++11

FLAGS = -std=$(STD)  -Wall -pedantic -Wno-deprecated-declarations 

# Add new source files here
FILES = utils.cpp shape.cpp circle.cpp polygon.cpp rectangle.cpp scaled.cpp shape_decorator.cpp rotate.cpp

main: main.cpp $(FILES) 
	$(COMPILER)  $^ $(FLAGS) -o $@

test: test.cpp $(FILES)
	$(COMPILER)  $^ $(FLAGS) -o $@

travis: test.cpp $(FILES)
	$(COMPILER) $^ -std=c++0x -Wall -pedantic -Wno-deprecated-declarations -o $@

clean:
	rm -rf test main travis
