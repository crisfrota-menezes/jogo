#pragma once

#include "gerenciadorGrafico.hpp"
#include "gerenciadorEstado.hpp"
#include "../Entidades/Personagens/jogador.hpp"
#include "../Listas/listaObservador.hpp"

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
            static ListaObservador* listaObservador;
            // singleton
            static GerenciadorEvento *pEvento;
            GerenciadorEvento();
            void verificaTeclaPressionada(sf::Keyboard::Key tecla);
            void verificaTeclaSolta(sf::Keyboard::Key tecla);

        public:
            ~GerenciadorEvento();
            static GerenciadorEvento *getGerenciadorEvento();
            void addObservador(Observador* obs);
            void removerObservador(Observador* obs);
            void removerObservador(int pos);
            void executar();
        };
    }
    using namespace Gerenciadores;
}
using namespace SpaceHunt;