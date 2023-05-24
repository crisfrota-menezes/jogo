#include "jogador.hpp"

Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam) : Personagem(sf::RectangleShape(tam))
{
    corpo.setPosition(pos);
    corpo.setFillColor(sf::Color::Green);
    inicializa();
}

Jogador::Jogador(const sf::RectangleShape corpo) : Personagem(corpo)
{
    inicializa();
}

Jogador::Jogador() : Personagem()
{
    inicializa();
}

Jogador::~Jogador()
{
}

void Jogador::move()
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

void Jogador::inicializa()
{
    vel = sf::Vector2f(1.0f, 1.0f);
}