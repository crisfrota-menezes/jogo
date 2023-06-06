#include "mae.hpp"

Mae::Mae(const sf::Vector2f pos, Jogador *jogador) : Inimigo(pos, sf::Vector2f(TAMANHO_Mae_X, TAMANHO_Mae_Y), jogador, IDs::IDs::Mae)
{
    inicializa();
}

Mae::~Mae()
{
}

void Mae::inicializa()
{
    corpo.setFillColor(sf::Color::Blue);
}