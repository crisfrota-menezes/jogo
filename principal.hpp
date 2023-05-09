#pragma once

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