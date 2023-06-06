#pragma once

#include "inimigo.hpp"

#define TAMANHO_Mae_X 60.0f
#define TAMANHO_Mae_Y 60.0f

namespace Escape_the_room
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Mae : public Inimigo
            {
            private:
                void inicializa();

            public:
                Mae(const sf::Vector2f pos, Jogador *jogador);
                ~Mae();

            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}