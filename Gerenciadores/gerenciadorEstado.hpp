#pragma once

#include "../Construtores/construtorEstado.hpp"
#include <stack>

namespace SpaceHunt
{
    namespace Gerenciadores
    {
        class GerenciadorEstado
        {
        private:
            std::stack<Estado *> pilhaEstados;

            ConstrutorEstado construtor;

            // padrão de projeto singleton
            static GerenciadorEstado *pGerenciadorEstado;
            GerenciadorEstado();

        public:
            ~GerenciadorEstado();
            static GerenciadorEstado *getGerenciadorEstado();
            void executar();
            void addEstado(const IDs::IDs ID);
            void removerEstado();
        };
    }
    using namespace Gerenciadores;
}
using namespace SpaceHunt;