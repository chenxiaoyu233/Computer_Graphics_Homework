main: main.cpp Paper.o
	g++ main.cpp Paper.o -framework OpenGL -framework GLUT -framework Foundation -g -o main.cpp.out
Paper.o: Paper.cpp Paper.h
	g++ Paper.cpp -framework OpenGL -framework GLUT -framework Foundation -c -g
clean: *.out* *.o
	rm -r *.out* *.o
