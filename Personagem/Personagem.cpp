#include "Personagem.hpp"

Entidades::Personagem::Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam) : corpo()
{
    corpo.setPosition(pos);
    corpo.setSize(tam);
}

Entidades::Personagem::Personagem::~Personagem()
{
}

const sf::RectangleShape Entidades::Personagem::Personagem::getCorpo()
{
    return corpo;
}