#include "jogador.hpp"

Entidades::Personagem::Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam) : corpo(sf::RectangleShape(tam))
{
    corpo.setPosition(pos);
    corpo.setFillColor(sf::Color::Green);
    inicializa();
}

Entidades::Personagem::Jogador::Jogador(const sf::RectangleShape corpo) : corpo(corpo)
{
    inicializa();
}

Entidades::Personagem::Jogador::Jogador() : corpo()
{
    inicializa();
}

Entidades::Personagem::Jogador::~Jogador()
{
}

const sf::RectangleShape Entidades::Personagem::Jogador::getCorpo()
{
    return corpo;
}

void Entidades::Personagem::Jogador::move()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        corpo.move(-vel.x, 0.0f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        corpo.move(vel.x, 0.0f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        corpo.move(0.0f, -vel.y);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        corpo.move(0.0f, vel.y);
    }
}

void Entidades::Personagem::Jogador::inicializa()
{
    vel = sf::Vector2f(0.1f, 0.1f);
}