#include "jogador.hpp"

Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam) : Personagem(pos, tam)
{
    corpo.setFillColor(sf::Color::Green);
    inicializa();
}

Jogador::~Jogador()
{
}

void Jogador::atualizar()
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