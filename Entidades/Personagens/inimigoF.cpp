#include "inimigoF.hpp"

InimigoF::InimigoF(const sf::Vector2f pos, Jogador *jogador) : Inimigo(pos, sf::Vector2f(TAMANHO_INIMIGOF_X, TAMANHO_INIMIGOF_Y), jogador, IDs::IDs::inimigoF)
{
    inicializa();
}

InimigoF::~InimigoF()
{
}

void InimigoF::inicializa()
{
    corpo.setFillColor(sf::Color::White);
}
