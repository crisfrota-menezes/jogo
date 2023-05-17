#pragma once

#include "Menus/menu.hpp"
#include "Personagem/jogador.hpp"
class Jogo
{
private:
    sf::RenderWindow *window;
    sf::Texture *image;
    sf::Sprite *bg;
    Entidades::Personagem::Jogador jogador;

public:
    Jogo();
    ~Jogo();
    void run();
};