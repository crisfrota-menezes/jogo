#include "Personagem.hpp"

namespace Escape_the_room
{
    namespace Entidades
    {
        namespace Personagens
        {
            Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam) : corpo(sf::RectangleShape(tam))
            {
                corpo.setPosition(pos);
                corpo.setFillColor(sf::Color::Green);
            }

            Personagem::Personagem(const sf::RectangleShape corpo) : corpo(corpo)
            {
            }

            Personagem::Personagem() : corpo()
            {
            }

            Personagem::~Personagem()
            {
            }

            const sf::RectangleShape Personagem::getCorpo()
            {
                return corpo;
            }
        }
    }
}