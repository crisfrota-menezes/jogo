#pragma once

#include "inimigo.hpp"

#define TAMANHO_Alien2_X 50.0f
#define TAMANHO_Alien2_Y 90.0f

namespace SpaceHunt
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Alien2 : public Inimigo
            {
            private:
                void inicializa();

            public:
                Alien2(const sf::Vector2f pos, Jogador *jogador);
                ~Alien2();

            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;