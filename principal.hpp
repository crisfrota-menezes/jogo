#pragma once

#include "menu.hpp"
#include "jogador.hpp"
#include "inimigo.hpp"
#include "Personagem.hpp"
#include <vector>

class Jogo
{
private:
    sf::RenderWindow *window;
    sf::Texture *image;
    sf::Sprite *bg;
    std::vector<Entidades::Personagem::Personagem *> personagens;

public:
    Jogo();
    ~Jogo();
    void run();
};