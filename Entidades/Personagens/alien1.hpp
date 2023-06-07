#pragma once

#include "inimigo.hpp"

#define TAMANHO_Alien1_X 50.0f
#define TAMANHO_Alien1_Y 90.0f

namespace SpaceHunt
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Alien1 : public Inimigo
            {
            private:
                int nivel = 1;
                void inicializa();

            public:
                Alien1(const sf::Vector2f pos, Jogador *jogador);
                ~Alien1();
                void setVida(bool vida);

            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;