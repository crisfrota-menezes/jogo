#pragma once

// Gerenciadores
#include "Gerenciadores/gerenciadorGrafico.hpp"
#include "Gerenciadores/gerenciadorEvento.hpp"
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
        static GerenciadorEstado *pEstado;

    public:
        Jogo();
        ~Jogo();
        void run();
    };
}
using namespace SpaceHunt;