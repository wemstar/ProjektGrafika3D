all: compile
	g++ -o test -Wall *.o  -lGLEW -lGL -lglut -lGLU -lSOIL -L/home/wemstar/ClionProjects/OpenGLTest
compile:
	g++ -c *.cpp 
	
run: all
	./test
remove:
	rm -f *.o

