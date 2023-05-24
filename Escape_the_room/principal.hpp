#pragma once

#include "../Menus/menu.hpp"
#include "../Entidades/Personagens/jogador.hpp"
#include "../Entidades/Personagens/inimigo.hpp"
#include "../Entidades/Personagens/Personagem.hpp"
#include "../Gerenciadores/GerenciadorGrafico.hpp"
#include "../Listas/listaEntidade.hpp"
#include "../Entidades/Obstaculo/obstaculo.hpp"
#include "../Entidades/Obstaculo/obsGenerico.hpp"

class Jogo
{
private:
    GerenciadorGrafico *pGrafico;
    sf::Texture *image;
    sf::Sprite *bg;
    ListaEntidades listaPersonagem;
    ListaEntidades listaObstaculo;

public:
    Jogo();
    ~Jogo();
    void instanciaEntidades();
    void run();
};