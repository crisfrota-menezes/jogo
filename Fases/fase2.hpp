#pragma once

#include "fase.hpp"

namespace SpaceHunt
{
    namespace Fases
    {
        class Fase2 : public Fase
        {
        public:
            Fase2();
            ~Fase2();
            void criarBackground();
            void criarMapa();
        };
    }
    using namespace Fases;
}
using namespace SpaceHunt;