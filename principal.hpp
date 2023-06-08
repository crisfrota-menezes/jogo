#pragma once

// Gerenciadores
#include "Gerenciadores/gerenciadorGrafico.hpp"
#include "Gerenciadores/gerenciadorEvento.hpp"

// Fases
#include "Fases/fase1.hpp"
#include "Fases/fase2.hpp"

namespace SpaceHunt
{
    class Jogo
    {
    private:
        GerenciadorGrafico *pGrafico;
        GerenciadorEvento *pEvento;
        Fase *fase;
        void criarFase();

    public:
        Jogo();
        ~Jogo();
        void run();
    };
}
using namespace SpaceHunt;