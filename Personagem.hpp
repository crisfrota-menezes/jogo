#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

namespace Escape_the_room
{
    namespace Entidades
    {
        namespace Personagem
        {
            class Personagem
            {
            protected:
                sf::RectangleShape corpo;
                sf::Vector2f vel;
                int vida;

            public:
                Personagem(const sf::Vector2f pos, const sf::Vector2f tam);
                Personagem(const sf::RectangleShape corpo);
                Personagem();
                ~Personagem();
                const sf::RectangleShape getCorpo();
                virtual void move() = 0;
            };
        }
        using namespace Personagem;
    }
    using namespace Entidades;
}
using namespace Escape_the_room;