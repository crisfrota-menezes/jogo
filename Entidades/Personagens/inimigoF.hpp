#pragma once

#include "inimigo.hpp"

#define TAMANHO_INIMIGOF_X 50.0f
#define TAMANHO_INIMIGOF_Y 50.0f

namespace Escape_the_room
{
    namespace Entidades
    {
        namespace Personagens
        {
            class InimigoF : public Inimigo
            {
            private:
                void inicializa();

            public:
                InimigoF(const sf::Vector2f pos, Jogador *jogador);
                ~InimigoF();

            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}