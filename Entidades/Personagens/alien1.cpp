#include "alien1.hpp"

Alien1::Alien1(const sf::Vector2f pos, Jogador *jogador) : Inimigo(pos, sf::Vector2f(TAMANHO_Alien1_X, TAMANHO_Alien1_Y), jogador, IDs::IDs::Alien1)
{
    inicializa();
}

Alien1::~Alien1()
{
}

void Alien1::inicializa()
{
    animacao.addAnimacao("C:/Users/crisn/Desktop/projetoTecProg/Midia/AndaA1.png", "ANDA", 1, 0.12f, sf::Vector2f(2, 1));
    animacao.addAnimacao("C:/Users/crisn/Desktop/projetoTecProg/Midia/ParadoA1.png", "PARADO", 1, 0.12f, sf::Vector2f(2, 1));
    corpo.setOrigin(tam.x / 3.0f, tam.y / 3.0f);
}