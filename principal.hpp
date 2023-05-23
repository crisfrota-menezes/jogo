#pragma once

#include "menu.hpp"
#include "jogador.hpp"
#include "inimigo.hpp"
#include "Personagem.hpp"
#include "gerenciadorGrafico.hpp"
#include "listaEntidade.hpp"

class Jogo
{
private:
    GerenciadorGrafico *pGrafico;
    sf::Texture *image;
    sf::Sprite *bg;
    ListaEntidades listaEntidade;

public:
    Jogo();
    ~Jogo();
    void run();
    void instanciaEntidades();
};