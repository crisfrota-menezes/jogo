#pragma once

#include "GerenciadorGrafico.hpp"
#include "../Entidades/Personagens/jogador.hpp"

namespace SpaceHunt
{
    namespace Gerenciadores
    {
        class GerenciadorEstado;

        class GerenciadorEvento
        {
        private:
            static GerenciadorGrafico *pGrafico;
            static GerenciadorEstado *pEstado;
            // padrão de projeto singleton
            static GerenciadorEvento *pEvento;
            GerenciadorEvento();

        public:
            ~GerenciadorEvento();
            static GerenciadorEvento *getGerenciadorEvento();
            void verificaTeclaPressionada(sf::Keyboard::Key tecla);
            void verificaTeclaSolta(sf::Keyboard::Key tecla);
            void executar();
        };
    }
    using namespace Gerenciadores;
}
using namespace SpaceHunt;