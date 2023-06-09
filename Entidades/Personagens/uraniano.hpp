#pragma once

#include "inimigo.hpp"

#define TAMANHO_Uraniano_X 50.0f
#define TAMANHO_Uraniano_Y 90.0f

namespace SpaceHunt
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Uraniano : public Inimigo
            {
            private:
                void inicializa();

            public:
                Uraniano(const sf::Vector2f pos, Jogador *jogador);
                ~Uraniano();

            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;