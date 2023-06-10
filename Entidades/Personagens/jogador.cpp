#include "jogador.hpp"
#include <cmath>

Jogador::Jogador(const sf::Vector2f pos) : Personagem(pos, sf::Vector2f(TAMANHO_JOGADOR_X, TAMANHO_JOGADOR_Y), VELOCIDADE_JOGADOR, IDs::IDs::jogador), noChao(false)
{
    vida = 10;
    dano = 1;
    danoTomado = 0;
    // hit = false;
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
    switch (outraEnt->getID())
    {
    case (IDs::IDs::Projetil):
    {
        cout << "Jogador atingido" << endl;
    }
    case (IDs::IDs::Uraniano):
    {
        cout << "AI" << endl;
        // hit = true;
        // danoTomado = outraEnt->getDano();
        //vida -= danoTomado;
        // animar();
        if (vida <= 0)
        {
            delete this;
            cout << "GAME OVER" << endl;
            exit(0);
        }
        else
        {
            // Código que empurra o jogador para trás
            setPos(sf::Vector2f(outraEnt->getPos().x - 75.0f, getPos().y - 25.0f));
        }
    }
    break;
    case (IDs::IDs::Verme):
    {
        // hit = true;
        danoTomado = outraEnt->getDano();
        vida -= danoTomado;
        // animar();
        if (vida <= 0)
        {
            delete this;
            cout << "GAME OVER" << endl;
            exit(0);
        }
        else
        {
            // Código que empurra o jogador para trás
            setPos(sf::Vector2f(outraEnt->getPos().x - 75.0f, getPos().y - 25.0f));
        }
    }
    break;
    case (IDs::IDs::Venusiano):
    {
        // hit = true;
        danoTomado = outraEnt->getDano();
        vida -= danoTomado;
        // animar();
        if (vida <= 0)
        {
            delete this;
            cout << "GAME OVER" << endl;
            exit(0);
        }
        else
        {
            // Código que empurra o jogador para trás
            setPos(sf::Vector2f(outraEnt->getPos().x - 75.0f, getPos().y - 25.0f));
        }
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
    /*if (hit)
    {
        animacao.atualizar(paraEsquerda, "HIT");
        hit = false;
    }
    else */
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
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/AndaJ.png", "ANDA", 3, 0.15f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/ParadoJ.png", "PARADO", 10, 0.15f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/PulaJ.png", "PULA", 8, 0.15f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/CaiJ.png", "CAI", 1, 0.15f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/AtacaJ.png", "ATACA", 4, 0.15f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/SpaceHunt/Midia/HitJ.png", "HIT", 3, 0.15f, sf::Vector2f(3, 1.5));
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