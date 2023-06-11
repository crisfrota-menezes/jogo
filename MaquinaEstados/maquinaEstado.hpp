#pragma once

#include "estadoJogar.hpp"
#include <stack>

namespace SpaceHunt
{
    namespace Estados
    {
        class MaquinaEstado
        {
        private:
            std::stack<Estado *> pilhaEstados;

            void addEstadoJogar(const IDs::IDs ID);

        public:
            MaquinaEstado();
            ~MaquinaEstado();
            void executar();
            void addEstado(const IDs::IDs ID);
            void removerEstado();
        };
    }
    using namespace Estados;
}
using namespace SpaceHunt;