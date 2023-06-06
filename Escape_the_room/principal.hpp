#pragma once

#include "../Menus/menu.hpp"
#include "../Entidades/Personagens/jogador.hpp"
#include "../Entidades/Personagens/inimigo.hpp"
#include "../Entidades/Personagens/alien1.hpp"
#include "../Entidades/Personagens/alien2.hpp"
#include "../Entidades/Personagens/alien3.hpp"
#include "../Entidades/Personagens/Personagem.hpp"
#include "../Gerenciadores/gerenciadorGrafico.hpp"
#include "../Listas/listaEntidade.hpp"
#include "../Entidades/Obstaculo/plataforma.hpp"
#include "../Gerenciadores/gerenciadorColisao.hpp"
#include "../Entidades/IDs.hpp"
#include "../Gerenciadores/gerenciadorEvento.hpp"

class Jogo
{
private:
    GerenciadorGrafico *pGrafico;
    GerenciadorEvento *pEvento;
    ListaEntidades listaPersonagem;
    ListaEntidades listaObstaculo;
    GerenciadorColisao colisor;

public:
    Jogo();
    ~Jogo();
    void instanciaEntidades();
    void run();
};