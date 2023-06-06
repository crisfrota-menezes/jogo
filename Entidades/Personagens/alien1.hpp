#pragma once

#include "inimigo.hpp"

#define TAMANHO_Alien1_X 50.0f
#define TAMANHO_Alien1_Y 90.0f

namespace Escape_the_room
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Alien1 : public Inimigo
            {
            private:
                void inicializa();

            public:
                Alien1(const sf::Vector2f pos, Jogador *jogador);
                ~Alien1();

            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}