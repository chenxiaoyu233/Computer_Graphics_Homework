main: main.cpp Paper.o Automaton.o Menu.o 
	g++ main.cpp Paper.o Automaton.o Menu.o \
		-framework OpenGL -framework GLUT -framework Foundation \
		-g -o main.cpp.out
Automaton.o: Automaton.cpp Automaton.h Menu.h LineAlgorithm.h
	g++ Automaton.cpp -framework OpenGL -framework GLUT -framework Foundation -c -g
Paper.o: Paper.cpp Paper.h
	g++ Paper.cpp -framework OpenGL -framework GLUT -framework Foundation -c -g
Menu.o: Menu.cpp Menu.h
	g++ Menu.cpp -framework OpenGL -framework GLUT -framework Foundation -c -g
clean: 
	rm -r *.out* *.o
