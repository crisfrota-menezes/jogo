#pragma once

#include "menu.hpp"
#include "./include/Personagem/Jogador/jogador.hpp"
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