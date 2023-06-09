#include "venusiano.hpp"

Venusiano::Venusiano(const sf::Vector2f pos, Jogador *jogador) : Inimigo(pos, sf::Vector2f(TAMANHO_Venusiano_X, TAMANHO_Venusiano_Y), jogador, IDs::IDs::Venusiano)
{
    vida = 4;
    dano = 2;
    inicializa();
}

Venusiano::~Venusiano()
{
}

void Venusiano::inicializa()
{
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/AndaA3.png", "ANDA", 8, 0.15f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/ParadoA3.png", "PARADO", 8, 0.15f, sf::Vector2f(3, 1.5));
    corpo.setOrigin(tam.x / 3.0f, tam.y / 3.0f);
}