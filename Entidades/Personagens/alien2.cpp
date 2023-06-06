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
    animacao.addAnimacao("C:/Users/crisn/Desktop/projetoTecProg/Midia/AndaA2.png", "ANDA", 1, 0.12f, sf::Vector2f(2, 1));
    animacao.addAnimacao("C:/Users/crisn/Desktop/projetoTecProg/Midia/ParadoA2.png", "PARADO", 1, 0.12f, sf::Vector2f(2, 1));
    corpo.setOrigin(tam.x / 3.0f, tam.y / 3.0f);
}