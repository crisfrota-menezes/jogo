#include "jogador.hpp"
#include "../../Observadores/observadorJ.hpp"

#include <cmath>

Jogador::Jogador(const sf::Vector2f pos) : Personagem(pos, sf::Vector2f(TAMANHO_JOGADOR_X, TAMANHO_JOGADOR_Y), VELOCIDADE_JOGADOR, IDs::IDs::jogador), noChao(false), obsJogador(new ObservadorJ(this))
{
    //vida = 10;
    if (obsJogador == nullptr)
    {
        cout << "nao foi possivel criar um observador do jogador" << endl;
        exit(1);
    }
    inicializa();
}

Jogador::~Jogador()
{
    if (obsJogador)
    {
        delete obsJogador;
        obsJogador = nullptr;
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
    corpo.setOrigin(sf::Vector2f(tam.x / 2.0f, tam.y / 5.0f));
}

void Jogador::atualizar()
{
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
        cout << "AI" << endl;
        vida -= outraEntidade->getDano();
        if (vida <= 0)
        {
            cout << "MORTE POR URANIANO" << endl;
            delete this;
            cout << "GAME OVER" << endl;
            exit(0);
        }
        else
        {
            // Código que empurra o jogador para trás
            setPos(sf::Vector2f(pos.x, pos.y - 25.0f));
            noChao = false;
        }
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