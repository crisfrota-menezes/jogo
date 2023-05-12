all: compile link

compile:
	g++ -ISFML/include -c *.cpp

link:
	g++ *.o -o main -LSFML/lib -lsfml-graphics -lsfml-window -lsfml-system