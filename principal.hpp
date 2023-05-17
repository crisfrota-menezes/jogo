#pragma once

#include "Menus/menu.hpp"
#include "Personagem/jogador.hpp"
class Jogo
{
private:
    sf::RenderWindow *window;
    Entidades::Personagem::Jogador jogador;

public:
    Jogo();
    ~Jogo();
    void run();
};