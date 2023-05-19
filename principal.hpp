#pragma once

#include "Menus/menu.hpp"
#include "Personagem/jogador.hpp"
#include "Personagem/inimigo.hpp"
#include "Personagem/Personagem.hpp"
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