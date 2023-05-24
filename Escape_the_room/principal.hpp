#pragma once

#include "../Menus/menu.hpp"
#include "../Entidades/Personagens/jogador.hpp"
#include "../Entidades/Personagens/inimigo.hpp"
#include "../Entidades/Personagens/Personagem.hpp"
#include "../Gerenciadores/GerenciadorGrafico.hpp"
#include "../Listas/listaEntidade.hpp"

class Jogo
{
private:
    GerenciadorGrafico *pGrafico;
    sf::Texture *image;
    sf::Sprite *bg;
    ListaEntidades listaPersonagem;

public:
    Jogo();
    ~Jogo();
    void instanciaEntidades();
    void run();
};