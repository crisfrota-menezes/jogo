#pragma once

#include "menu.hpp"
#include "jogador.hpp"
class Principal
{
private:
    sf::RenderWindow *window;
    Entidades::Personagem::Jogador jogador;

public:
    Principal();
    ~Principal();
    void run();
};