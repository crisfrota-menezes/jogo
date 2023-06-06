#pragma once

#include "inimigo.hpp"

#define TAMANHO_Pai_X 70.0f
#define TAMANHO_Pai_Y 70.0f

namespace Escape_the_room
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Pai : public Inimigo
            {
            private:
                void inicializa();

            public:
                Pai(const sf::Vector2f pos, Jogador *jogador);
                ~Pai();

            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}