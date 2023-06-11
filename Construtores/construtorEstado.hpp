#pragma once

#include "../MaquinaEstados/estadoJogar.hpp"

#include "construtorFase.hpp"

namespace SpaceHunt
{
    namespace Construtores
    {
        class ConstrutorEstado
        {
        public:
            ConstrutorEstado();
            ~ConstrutorEstado();
            Estado *criarEstado(const IDs::IDs ID);
        private:
            Estado *criarEstadoJogar(const IDs::IDs ID);
        };
    }
    using namespace Construtores;
}
using namespace SpaceHunt;