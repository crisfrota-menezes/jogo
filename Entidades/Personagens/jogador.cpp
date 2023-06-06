#include "jogador.hpp"

Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam) : Personagem(pos, tam, VELOCIDADE_JOGADOR, IDs::IDs::jogador)
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