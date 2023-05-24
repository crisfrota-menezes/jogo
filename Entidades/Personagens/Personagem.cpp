#include "Personagem.hpp"

Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam) : Entidade(pos, tam), vel(sf::Vector2f(0, 0))
{
}

Personagem::~Personagem()
{
}

const sf::Vector2f Personagem::getVel()
{
    return vel;
}