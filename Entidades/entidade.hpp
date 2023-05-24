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
            sf::Vector2f pos;
            sf::Vector2f tam;

        public:
            Entidade(const sf::Vector2f pos, const sf::Vector2f tam);
            ~Entidade();
            const sf::RectangleShape getCorpo();
            void setPos(const sf::Vector2f pos);
            const sf::Vector2f getPos();
            const sf::Vector2f getTam();
            virtual void atualizar() = 0;
        };
    }
    using namespace Entidades;
}
using namespace Escape_the_room;