#pragma once

#include "inimigo.hpp"

#define TAMANHO_INIMIGOD_X 70.0f
#define TAMANHO_INIMIGOD_Y 70.0f

namespace Escape_the_room
{
    namespace Entidades
    {
        namespace Personagens
        {
            class InimigoD : public Inimigo
            {
            private:
                void inicializa();

            public:
                InimigoD(const sf::Vector2f pos, Jogador *jogador);
                ~InimigoD();

            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}