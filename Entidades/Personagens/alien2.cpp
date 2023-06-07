#include "alien2.hpp"

Alien2::Alien2(const sf::Vector2f pos, Jogador *jogador) : Inimigo(pos, sf::Vector2f(TAMANHO_Alien2_X, TAMANHO_Alien2_Y), jogador, IDs::IDs::Alien2)
{
    inicializa();
}

Alien2::~Alien2()
{
}

void Alien2::inicializa()
{
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/AndaA2.png", "ANDA", 1, 0.12f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/ParadoA2.png", "PARADO", 1, 0.12f, sf::Vector2f(3, 1.5));
    corpo.setOrigin(tam.x / 3.0f, tam.y / 3.0f);
}

void Alien2::setVida(bool vida)
{
}