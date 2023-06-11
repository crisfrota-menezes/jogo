#pragma once

#include "../Fases/fase1.hpp"
#include "../Fases/fase2.hpp"

namespace SpaceHunt {

    namespace Construtores {

        class ConstrutorFase 
        {
        public:
            ConstrutorFase();
            ~ConstrutorFase();
            Fase *criarFase(const IDs::IDs ID);
        private:
            Fase *criarFase1();
            Fase *criarFase2();
        };
    } 
    using namespace Construtores;
}
using namespace SpaceHunt;