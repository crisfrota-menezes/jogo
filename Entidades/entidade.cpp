#include "entidade.hpp"

Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID) : corpo(sf::RectangleShape(tam)), ID(ID), pos(pos), tam(tam)
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

sf::Vector2f Entidade::posicaoAleatoria(float larguraJanela, float alturaJanela)
{
    float posX = 0.0f;
    float posY = 0.0f;
    posX = (float)(rand() % (int)(larguraJanela - tam.x));
    posY = (float)(rand() % (int)(alturaJanela - tam.y));
    return sf::Vector2f(posX, posY);
}

const IDs::IDs Entidade::getID() const
{
    return ID;
}