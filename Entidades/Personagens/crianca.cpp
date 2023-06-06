#include "crianca.hpp"

Crianca::Crianca(const sf::Vector2f pos, Jogador *jogador) : Inimigo(pos, sf::Vector2f(TAMANHO_Crianca_X, TAMANHO_Crianca_Y), jogador, IDs::IDs::Crianca)
{
    inicializa();
}

Crianca::~Crianca()
{
}

void Crianca::inicializa()
{
    corpo.setFillColor(sf::Color::White);
}
