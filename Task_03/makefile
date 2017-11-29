main: main.cpp Paper.o Pen.o Automaton.o Menu.o KeyPoint.o Point.o Shape.o Circle.o Line.o Square.o Polygon.o Bezier.o Ellipse.o Fill.o FillAlgorithm.o
	g++ main.cpp Paper.o Pen.o Automaton.o Menu.o KeyPoint.o Point.o Shape.o Circle.o Line.o Square.o Polygon.o Bezier.o Ellipse.o Fill.o FillAlgorithm.o\
		-framework OpenGL -framework GLUT -framework Foundation \
		-g -o main.cpp.out
Automaton.o: Automaton.cpp Automaton.h Menu.h LineAlgorithm.h
	g++ Automaton.cpp -c -g
Paper.o: Paper.cpp Paper.h
	g++ Paper.cpp -c -g
Pen.o: Pen.cpp Pen.h
	g++ Pen.cpp -c -g
Menu.o: Menu.cpp Menu.h
	g++ Menu.cpp -c -g
KeyPoint.o: KeyPoint.cpp KeyPoint.h 
	g++ KeyPoint.cpp -c -g
Point.o: Point.cpp Point.h
	g++ Point.cpp -c -g
Shape.o: Shape.cpp Shape.h
	g++ Shape.cpp -c -g
Circle.o: Circle.cpp Circle.h
	g++ Circle.cpp -c -g
Line.o: Line.cpp Line.h
	g++ Line.cpp -c -g
Square.o: Square.cpp Square.h
	g++ Square.cpp -c -g
Polygon.o: Polygon.cpp Polygon.h
	g++ Polygon.cpp -c -g
Bezier.o: Bezier.cpp Bezier.h
	g++ Bezier.cpp -c -g
Ellipse.o: Ellipse.cpp Ellipse.h
	g++ Ellipse.cpp -c -g
Fill.o: Fill.cpp Fill.h
	g++ Fill.cpp -c -g
FillAlgorithm.o: FillAlgorithm.cpp FillAlgorithm.h
	g++ FillAlgorithm.cpp -c -g
clean: 
	rm -r *.out* *.o
