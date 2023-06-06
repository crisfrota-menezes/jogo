#include "pai.hpp"

Pai::Pai(const sf::Vector2f pos, Jogador *jogador) : Inimigo(pos, sf::Vector2f(TAMANHO_Pai_X, TAMANHO_Pai_Y), jogador, IDs::IDs::Pai)
{
    inicializa();
}

Pai::~Pai()
{
}

void Pai::inicializa()
{
    corpo.setFillColor(sf::Color::Red);
}