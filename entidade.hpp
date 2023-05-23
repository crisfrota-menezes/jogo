#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

namespace Escape_the_room
{
    namespace Entidades
    {
        class Entidade
        {
        protected:
            sf::RectangleShape corpo;

        public:
            Entidade(cons sf::Vector2f pos, const sf::Vector2f tam);
            ~Entidade();
            const sf::RectangleShape getCorpo() const;
            virtual void atualizar() = 0;
        };
    }
    using namespace Entidades;
}
using namespace Escape_the_room;