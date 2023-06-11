#pragma once

#include "../MaquinaEstados/estadoJogar.hpp"
#include "../Fases/fase1.hpp"
#include "../Fases/fase2.hpp"

namespace SpaceHunt
{
    namespace Construtores
    {
        class ConstrutorEstado
        {
        public:
            ConstrutorEstado();
            ~ConstrutorEstado();
            Estado *addEstadoJogar(const IDs::IDs ID);
        };
    }
    using namespace Construtores;
}
using namespace SpaceHunt;