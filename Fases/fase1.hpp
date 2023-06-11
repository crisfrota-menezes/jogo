#pragma once

#include "fase.hpp"
#include "../Entidades/Personagens/jogador.hpp"
#include "../Entidades/Personagens/Personagem.hpp"

namespace SpaceHunt
{
    namespace Fases
    {
        class Fase1 : public Fase
        {
        public:
            Fase1();
            ~Fase1();
            void criarMapa();
            void criarFundo();
        };
    }
    using namespace Fases;
}
using namespace SpaceHunt;