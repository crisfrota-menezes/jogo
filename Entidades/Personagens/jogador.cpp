#include "jogador.hpp"

#include <cmath>

Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam) : Personagem(pos, tam, VELOCIDADE_JOGADOR, IDs::IDs::jogador), noChao(false)

{
    inicializa();
}

void Jogador::inicializa()
{
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/AndaJ.png", "ANDA", 3, 0.15f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/ParadoJ.png", "PARADO", 10, 0.15f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/PulaJ.png", "PULA", 8, 0.15f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/CaiJ.png", "CAI", 1, 0.15f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/AtacaJ.png", "ATACA", 4, 0.15f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/HitJ.png", "HIT", 3, 0.15f, sf::Vector2f(3, 1.5));
    corpo.setOrigin(sf::Vector2f(tam.x / 2.0f, tam.y / 4.7f));
}

void Jogador::atualizar()
{
    /**
     * @ return void
     *
     * Faz o movimeto do jogador e atualiza animação
     */
    atualizarPos();
    animar();
    pGrafico->atualizarCamera(pos);
}

void Jogador::animar()
{
    if (!noChao && velFinal.y > 0.0f)
    {
        animacao.atualizar(paraEsquerda, "CAI");
    }
    else if (!noChao)
    {
        animacao.atualizar(paraEsquerda, "PULA");
    }
    else if (atacando)
    {
        animacao.atualizar(paraEsquerda, "ATACA");
    }
    else if (podeMover)
    {
        animacao.atualizar(paraEsquerda, "ANDA");
    }
    else
    {
        animacao.atualizar(paraEsquerda, "PARADO");
    }
}

void Jogador::colisao(Entidade *outraEntidade, sf::Vector2f ds)
{
    switch (outraEntidade->getID())
    {
    case (IDs::IDs::Uraniano):
    {
    }
    break;
    case (IDs::IDs::plataforma):
    {
    }
    }
}

void Jogador::pular()
{
    if (noChao)
    {
        velFinal.y = -sqrt(2.0f * GRAVIDADE * TAMANHO_PULO);
        noChao = false;
    }
}

void Jogador::podePular()
{
    noChao = true;
}