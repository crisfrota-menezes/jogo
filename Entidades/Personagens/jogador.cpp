#include "jogador.hpp"
#include <cmath>

Jogador::Jogador(const sf::Vector2f pos) : Personagem(pos, sf::Vector2f(TAMANHO_JOGADOR_X, TAMANHO_JOGADOR_Y), VELOCIDADE_JOGADOR, IDs::IDs::jogador), noChao(false)
{
    vida = 10;
    dano = 1;
    inicializa();
}

Jogador::~Jogador()
{
}

void Jogador::atualizar()
{
    atualizarPos();
    animar();
}

void Jogador::colisao(Entidade *outraEnt, sf::Vector2f ds)
{
    int danoTomado = 0;
    switch (outraEnt->getID())
    {
    case (IDs::IDs::Uraniano):
    {
        danoTomado = outraEnt->getDano();
        vida -= danoTomado;
        if (vida <= 0)
        {
            delete this;
            cout << "GAME OVER" << endl;
            exit(0);
        }
        else
        {
            // Código que empurra o jogador para trás
            setPos(sf::Vector2f(outraEnt->getPos().x - 50.0f, getPos().y - 25.0f));
        }
    }
    break;
    case (IDs::IDs::Alien2):
    {
    }
    break;
    case (IDs::IDs::Alien3):
    {
    }
    break;
    case (IDs::IDs::plataforma):
    {
    }
    break;
    case (IDs::IDs::Arvore):
    {
    }
    break;
    case (IDs::IDs::Rochas):
    {
    }
    break;
    }
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

void Jogador::inicializa()
{
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/AndaJ.png", "ANDA", 1, 0.12f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/ParadoJ.png", "PARADO", 1, 0.12f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/PulaJ.png", "PULA", 1, 0.12f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/CaiJ.png", "CAI", 1, 0.12f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/AtacaJ.png", "ATACA", 1, 0.12f, sf::Vector2f(3, 1.5));
    corpo.setOrigin(tam.x / 2.0f, tam.y / 4.7f);
}

void Jogador::pular()
{
    if (noChao)
    {
        velFinal.y = -sqrtf(2.0f * GRAVIDADE * TAMANHO_PULO);
        noChao = false;
    }
}

void Jogador::podePular()
{
    noChao = true;
}