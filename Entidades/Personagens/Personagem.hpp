#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include "../entidade.hpp"

namespace Escape_the_room
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Personagem : public Entidade
            {
            protected:
                sf::Vector2f vel;

            public:
                Personagem(const sf::Vector2f pos, const sf::Vector2f tam);
                ~Personagem();
                const sf::Vector2f getVel();
                virtual void atualizar() = 0;
            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace Escape_the_room;