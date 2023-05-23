#include "entidade.hpp"

Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f tam) : corpo(sf::RectangleShape(tam))
{
    corpo.setPosition(pos);
    corpo.setFillColor(sf::Color::Green);
}

Entidade::Entidade(const sf::RectangleShape corpo) : corpo(corpo)
{
}

Entidade::Entidade() : corpo()
{
}

Entidade::~Entidade()
{
}

const sf::RectangleShape Entidade::getCorpo()
{
    return corpo;
}
