#include "fase1.hpp"

Fase1::Fase1() : Fase(IDs::IDs::fase_Fase1, IDs::IDs::fundo_Fase1)
{
}

Fase1::~Fase1()
{
}

void Fase1::criarFundo()
{
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada1.png", 0.0f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada2.png", 0.0f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada3.png", 0.1f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada4.png", 0.2f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada5.png", 0.3f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada6.png", 0.5f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada7.png", 0.75f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada8.png", 1.5f);
}

void Fase1::criarMapa()
{
    criarJogador(sf::Vector2f(100.0f, 400.0f));

    for (int i = 0; i < 20; i++)
    {
        criarPlataforma(sf::Vector2f(i * 128.0f, 472.0f));
    }
    criarProjetil(sf::Vector2f(100.0f, 400.0f));

    for (int i = 0; i < 2; i++)
    {
        criaUraniano(sf::Vector2f(500.0f * (i + 1), 0.0f));
    }
    criarPlataforma(sf::Vector2f(500.0f, 200.0f));
    criarPlataforma(sf::Vector2f(900.0f, 200.0f));
    criarPlataforma(sf::Vector2f(1200.0f, 200.0f));
    criarPlataforma(sf::Vector2f(1100.0f, 125.0f));
    criarArvore(sf::Vector2f(400.0f, 500.0f));
    criarArvore(sf::Vector2f(1000.0f, 350.0f));
}