#pragma once

#include "inimigo.hpp"

#define TAMANHO_Alien3_X 60.0f
#define TAMANHO_Alien3_Y 110.0f

namespace SpaceHunt
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Alien3 : public Inimigo
            {
            private:
                void inicializa();

            public:
                Alien3(const sf::Vector2f pos, Jogador *jogador);
                ~Alien3();

            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;