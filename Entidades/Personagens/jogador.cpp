#include "jogador.hpp"
#include <cmath>

Jogador::Jogador(const sf::Vector2f pos) : Personagem(pos, sf::Vector2f(TAMANHO_JOGADOR_X, TAMANHO_JOGADOR_Y), VELOCIDADE_JOGADOR, IDs::IDs::jogador), noChao(false)
{
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
    case (IDs::IDs::Alien1):
    {
        cout << "Bateu no inimigoF" << endl;
    }
    break;
    case (IDs::IDs::Alien2):
    {
        cout << "Bateu no inimigoM" << endl;
    }
    break;
    case (IDs::IDs::Alien3):
    {
        cout << "Bateu no inimigoD" << endl;
    }
    break;
    case (IDs::IDs::plataforma):
    {
        cout << "Bateu na plataforma" << endl;
    }
    break;
    case (IDs::IDs::Arvore):
    {
        cout << "Bateu na plataforma" << endl;
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
    animacao.addAnimacao("C:/Users/crisn/Desktop/projetoTecProg/Midia/AndaJ.png", "ANDA", 1, 0.12f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/projetoTecProg/Midia/ParadoJ.png", "PARADO", 1, 0.12f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/projetoTecProg/Midia/PulaJ.png", "PULA", 1, 0.12f, sf::Vector2f(3, 1.5));
    animacao.addAnimacao("C:/Users/crisn/Desktop/projetoTecProg/Midia/CaiJ.png", "CAI", 1, 0.12f, sf::Vector2f(3, 1.5));
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