#pragma once

#include "../MaquinaEstados/estadoJogar.hpp"
#include "../MaquinaEstados/estadoMPrincipal.hpp"

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
            Estado *criarEstadoMenuPrincipal(const IDs::IDs ID = IDs::IDs::estadoMenuPrincipal);
        };
    }
    using namespace Construtores;
}
using namespace SpaceHunt;