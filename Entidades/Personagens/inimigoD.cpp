#include "inimigoD.hpp"

InimigoD::InimigoD(const sf::Vector2f pos, Jogador *jogador) : Inimigo(pos, sf::Vector2f(TAMANHO_INIMIGOD_X, TAMANHO_INIMIGOD_Y), jogador, IDs::IDs::inimigoD)
{
    inicializa();
}

InimigoD::~InimigoD()
{
}

void InimigoD::inicializa()
{
    corpo.setFillColor(sf::Color::Red);
}