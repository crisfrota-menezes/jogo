all: compile link

compile:
	g++ -IsrcSFML/include -c *.cpp

link:
	g++ *.o -o main -LsrcSFML/lib -lsfml-graphics -lsfml-window -lsfml-system