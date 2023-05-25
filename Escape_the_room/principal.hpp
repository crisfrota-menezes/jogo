#pragma once

#include "../Menus/menu.hpp"
#include "../Entidades/Personagens/jogador.hpp"
#include "../Entidades/Personagens/inimigo.hpp"
#include "../Entidades/Personagens/Personagem.hpp"
#include "../Gerenciadores/gerenciadorGrafico.hpp"
#include "../Listas/listaEntidade.hpp"
#include "../Entidades/Obstaculo/obsGenerico.hpp"
#include "../Gerenciadores/gerenciadorColisao.hpp"

class Jogo
{
private:
    GerenciadorGrafico *pGrafico;
    sf::Texture *image;
    sf::Sprite *bg;
    ListaEntidades listaPersonagem;
    ListaEntidades listaObstaculo;
    GerenciadorColisao colisor;

public:
    Jogo();
    ~Jogo();
    void instanciaEntidades();
    void run();
};