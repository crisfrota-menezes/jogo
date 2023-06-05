#include "jogador.hpp"

Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam) : Personagem(pos, tam, VELOCIDADE_JOGADOR, IDs::IDs::jogador), noChao(false)
{
    corpo.setFillColor(sf::Color::Green);
    inicializa();
}

Jogador::~Jogador()
{
}

void Jogador::atualizar()
{
    atualizarPos();
}

void Jogador::colisao(Entidade *outraEnt, sf::Vector2f ds)
{
    switch (outraEnt->getID())
    {
    case (IDs::IDs::inimigo):
    {
        cout << "Bateu no inimigo" << endl;
    }
    break;
    case (IDs::IDs::plataforma):
    {
        cout << "Bateu na plataforma" << endl;
    }
    break;
    }
}

void Jogador::inicializa()
{
}

void Jogador::pular()
{
    if (noChao)
    {
        velFinal.y = -sqrt(2.0f * GRAVIDADE * ALTURA_PULO);
        noChao = false;
    }
}

void Jogador::podePular()
{
    if (pos.y + tam.y >= 1080)
    {
        velFinal.y = 0.0f;
        setPos(sf::Vector2f(pos.x, 1080 - tam.y));
        noChao = true;
    }
    noChao = true;
}