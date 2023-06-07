#include "fase1.hpp"

Fase1::Fase1() : Fase(IDs::IDs::fase_Fase1)
{
}

Fase1::~Fase1()
{
}

void Fase1::criarMapa()
{
    criarJogador(sf::Vector2f(100.0f, 400.0f));

    for (int i = 0; i < 10; i++)
    {
        criarPlataforma(sf::Vector2f(i * 300.0f, 1000.0f));
    }

    for (int i = 0; i < 1; i++)
    {
        criaAlien1(sf::Vector2f(500.0f * (i + 1), 0.0f));
    }

    for (int i = 0; i < 1; i++)
    {
        criaAlien2(sf::Vector2f(600.0f * (i + 1), 0.0f));
    }

    for (int i = 0; i < 1; i++)
    {
        criaAlien3(sf::Vector2f(700.0f * (i + 1), 0.0f));
    }

    criarPlataforma(sf::Vector2f(1000.0f, 700.0f));

    criarArvore(sf::Vector2f(300.0f, 800.0f));

    criarRochas(sf::Vector2f(800.0f, 900.0f));
}
