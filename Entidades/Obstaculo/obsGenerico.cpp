#include "obsGenerico.hpp"

ObsGenerico::ObsGenerico(const sf::Vector2f pos, const sf::Vector2f tam) : Obstaculo(pos, tam)
{
    corpo.setFillColor(sf::Color::Blue);
}

ObsGenerico::~ObsGenerico()
{
}

void ObsGenerico::atualizar()
{
}