#pragma once

#include "../Construtores/construtorEstado.hpp"
#include "gerenciadorGrafico.hpp"
#include <stack>

namespace SpaceHunt
{
    namespace Gerenciadores
    {
        class GerenciadorEstado
        {
        private:
            std::stack<Estado *> pilhaEstados;

            ConstrutorEstado construtorEstado;

            // padrão de projeto singleton
            static GerenciadorEstado *pGerenciadorEstado;
            GerenciadorEstado();

        public:
            ~GerenciadorEstado();
            static GerenciadorEstado *getGerenciadorEstado();
            void executar();
            void addEstado(const IDs::IDs ID);
            void removerEstado();
            Estado *getEstadoAtual();
        };
    }
    using namespace Gerenciadores;
}
using namespace SpaceHunt;