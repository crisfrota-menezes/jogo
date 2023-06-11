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
        private:
            Fase* criarFase(const IDs::IDs ID);
        public:
            ConstrutorEstado();
            ~ConstrutorEstado();
            Estado *criarEstadoJogar(const IDs::IDs ID);
        };
    }
    using namespace Construtores;
}
using namespace SpaceHunt;