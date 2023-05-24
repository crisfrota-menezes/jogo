#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include "Personagem.hpp"

namespace Escape_the_room
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Jogador : public Personagem
            {
            private:
                void inicializa();

            public:
                Jogador(const sf::Vector2f pos, const sf::Vector2f tam);
                ~Jogador();
                void atualizar();
            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace Escape_the_room;