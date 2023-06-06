#pragma once

#include "inimigo.hpp"

#define TAMANHO_INIMIGOM_X 60.0f
#define TAMANHO_INIMIGOM_Y 60.0f

namespace Escape_the_room
{
    namespace Entidades
    {
        namespace Personagens
        {
            class InimigoM : public Inimigo
            {
            private:
                void inicializa();

            public:
                InimigoM(const sf::Vector2f pos, Jogador *jogador);
                ~InimigoM();

            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}