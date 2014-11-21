all: compile
	g++ -o test -Wall *.o  -lGLEW -lGL -lglut -lGLU
compile:
	g++ -c *.cpp 
	
run: all
	./test
remove:
	rm -f *.o test

