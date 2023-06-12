#pragma once

// Gerenciadores
#include "Gerenciadores/gerenciadorGrafico.hpp"
#include "Gerenciadores/gerenciadorEvento.hpp"

//#include "Menus/menuPrincipal.hpp"

#include "Gerenciadores/gerenciadorEstado.hpp"

// Fases
#include "Fases/fase1.hpp"
#include "Fases/fase2.hpp"

namespace SpaceHunt
{
    class Jogo
    {
    private:
        static GerenciadorGrafico *pGrafico;
        static GerenciadorEvento *pEvento;
        static GerenciadorEstado *pGerenciadorEstado;

    public:
        Jogo();
        ~Jogo();
        void run();
    };
}
using namespace SpaceHunt;