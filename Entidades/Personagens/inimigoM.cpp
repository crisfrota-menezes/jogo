#include "inimigoM.hpp"

InimigoM::InimigoM(const sf::Vector2f pos, Jogador *jogador) : Inimigo(pos, sf::Vector2f(TAMANHO_INIMIGOM_X, TAMANHO_INIMIGOM_Y), jogador, IDs::IDs::inimigoM)
{
    inicializa();
}

InimigoM::~InimigoM()
{
}

void InimigoM::inicializa()
{
    corpo.setFillColor(sf::Color::Blue);
}