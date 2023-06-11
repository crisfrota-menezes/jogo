all: compile link clean

compile:
	g++ -c *.cpp Entidades/*.cpp Fases/*.cpp Entidades/Personagens/*.cpp Entidades/Obstaculo/*.cpp Gerenciadores/*.cpp Listas/*.cpp Animacao/*.cpp Parallax/*.cpp MaquinaEstados/*.cpp Construtores/*.cpp -I"SFML/include"

link:
	g++ *.o -Wall -o main -L"SFML/lib" -lsfml-graphics -lsfml-window -lsfml-system

clean:
	del *.o