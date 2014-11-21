all:
	g++ -o test -Wall main.cpp -lGLEW -lGL -lglut -lGLU
run:
	./test

