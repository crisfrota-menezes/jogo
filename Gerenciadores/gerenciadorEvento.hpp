#pragma once

#include "gerenciadorGrafico.hpp"
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