#pragma once

// Gerenciadores
#include "Gerenciadores/gerenciadorGrafico.hpp"
#include "Gerenciadores/gerenciadorEvento.hpp"

#include "Menus/menuPrincipal.hpp"

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
        MenuPrincipal *menu;
        Fase *fase;
        void criarFase();
        void criarMenu();

    public:
        Jogo();
        ~Jogo();
        void run();
    };
}
using namespace SpaceHunt;