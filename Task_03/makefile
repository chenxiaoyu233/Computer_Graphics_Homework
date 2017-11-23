main: main.cpp Paper.o Automaton.o Menu.o KeyPoint.o Point.o Shape.o Circle.o Line.o Square.o Polygon.o Bezier.o
	g++ main.cpp Paper.o Automaton.o Menu.o KeyPoint.o Point.o Shape.o Circle.o Line.o Square.o Polygon.o Bezier.o\
		-framework OpenGL -framework GLUT -framework Foundation \
		-g -o main.cpp.out
Automaton.o: Automaton.cpp Automaton.h Menu.h LineAlgorithm.h
	g++ Automaton.cpp -framework OpenGL -framework GLUT -framework Foundation -c -g
Paper.o: Paper.cpp Paper.h
	g++ Paper.cpp -framework OpenGL -framework GLUT -framework Foundation -c -g
Menu.o: Menu.cpp Menu.h
	g++ Menu.cpp -framework OpenGL -framework GLUT -framework Foundation -c -g
KeyPoint.o: KeyPoint.cpp KeyPoint.h 
	g++ KeyPoint.cpp -framework OpenGL -framework GLUT -framework Foundation -c -g
Point.o: Point.cpp Point.h
	g++ Point.cpp -framework OpenGL -framework GLUT -framework Foundation -c -g
Shape.o: Shape.cpp Shape.h
	g++ Shape.cpp -framework OpenGL -framework GLUT -framework Foundation -c -g
Circle.o: Circle.cpp Circle.h
	g++ Circle.cpp -framework OpenGL -framework GLUT -framework Foundation -c -g
Line.o: Line.cpp Line.h
	g++ Line.cpp -framework OpenGL -framework GLUT -framework Foundation -c -g
Square.o: Square.cpp Square.h
	g++ Square.cpp -framework OpenGL -framework GLUT -framework Foundation -c -g
Polygon.o: Polygon.cpp Polygon.h
	g++ Polygon.cpp -framework OpenGL -framework GLUT -framework Foundation -c -g
Bezier.o: Bezier.cpp Bezier.h
	g++ Bezier.cpp -framework OpenGL -framework GLUT -framework Foundation -c -g
clean: 
	rm -r *.out* *.o
