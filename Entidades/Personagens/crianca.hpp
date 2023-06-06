#pragma once

#include "inimigo.hpp"

#define TAMANHO_Crianca_X 50.0f
#define TAMANHO_Crianca_Y 50.0f

namespace Escape_the_room
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Crianca : public Inimigo
            {
            private:
                void inicializa();

            public:
                Crianca(const sf::Vector2f pos, Jogador *jogador);
                ~Crianca();

            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}