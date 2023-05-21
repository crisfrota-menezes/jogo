#pragma once

#include "menu.hpp"
#include "jogador.hpp"
#include "inimigo.hpp"
#include "Personagem.hpp"
#include "gerenciadorGrafico.hpp"
#include <vector>

class Jogo
{
private:
    GerenciadorGrafico *pGrafico;
    sf::Texture *image;
    sf::Sprite *bg;
    std::vector<Entidades::Personagens::Personagem *> personagens;

public:
    Jogo();
    ~Jogo();
    void run();
};