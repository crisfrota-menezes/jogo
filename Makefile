all: compile link execute clean

compile:
	g++ -c Escape_the_room/*.cpp Entidades/*.cpp Entidades/Personagens/*.cpp Entidades/Obstaculo/*.cpp Gerenciadores/*.cpp Listas/*.cpp Menus/*.cpp -I"SFML/include"

link:
	g++ *.o -Wall -o main -L"SFML/lib" -lsfml-graphics -lsfml-window -lsfml-system

execute:
	./main.exe

clean:
	del *.o
	cls