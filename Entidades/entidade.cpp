#include "entidade.hpp"

Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID) : corpo(sf::RectangleShape(tam)), Ente(ID), pos(pos), tam(tam)
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

sf::Vector2f Entidade::getPos()
{
    return pos;
}

const sf::Vector2f Entidade::getTam()
{
    return tam;
}

void Entidade::desenhar()
{
    pGrafico->desenhaElemento(corpo);
}

int Entidade::getDano()
{
    return dano;
}