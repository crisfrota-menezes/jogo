#include "alien3.hpp"

Alien3::Alien3(const sf::Vector2f pos, Jogador *jogador) : Inimigo(pos, sf::Vector2f(TAMANHO_Alien3_X, TAMANHO_Alien3_Y), jogador, IDs::IDs::Alien3)
{
    inicializa();
}

Alien3::~Alien3()
{
}

void Alien3::inicializa()
{
    animacao.addAnimacao("C:/Users/crisn/Desktop/projetoTecProg/Midia/AndaA3.png", "ANDA", 1, 0.12f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/projetoTecProg/Midia/ParadoA3.png", "PARADO", 1, 0.12f, sf::Vector2f(3, 1.5));
    corpo.setOrigin(tam.x / 3.0f, tam.y / 3.0f);
}

void Alien3::disparar()
{
}