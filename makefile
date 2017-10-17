test: test.cpp
	g++ -g -framework OpenGL -framework GLUT -framework Foundation -o test.cpp.out test.cpp
simple: simple.cpp
	g++ -g -framework OpenGL -framework GLUT -framework Foundation -o simple.cpp.out simple.cpp
