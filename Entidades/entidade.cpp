#include "entidade.hpp"

Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f tam) : corpo(sf::RectangleShape(tam)), pos(pos), tam(tam)
{
    corpo.setPosition(pos);
}

Entidade::~Entidade()
{
}

const sf::RectangleShape Entidade::getCorpo()
{
    return corpo;
}

void Entidade::setPos(const sf::Vector2f pos)
{
    corpo.setPosition(pos);
    this->pos = pos;
}

const sf::Vector2f Entidade::getPos()
{
    return pos;
}

const sf::Vector2f Entidade::getTam()
{
    return tam;
}