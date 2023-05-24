all: compile link clean

compile:
	g++ -c Escape_the_room/*.cpp Entidades/*.cpp Entidades/Personagens/*.cpp Gerenciadores/*.cpp Listas/*.cpp Menus/*.cpp -ISFML/include

link:
	g++ *.o -o main -LSFML/lib -lsfml-graphics -lsfml-window -lsfml-system

clean:
	del *.o
	cls