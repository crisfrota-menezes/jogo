#include "jogador.hpp"

Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam) : Personagem(pos, tam, VELOCIDADE_JOGADOR, IDs::IDs::jogador), animacao(&corpo)
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
    case (IDs::IDs::Crianca):
    {
        cout << "Bateu no inimigoF" << endl;
    }
    break;
    case (IDs::IDs::Mae):
    {
        cout << "Bateu no inimigoM" << endl;
    }
    break;
    case (IDs::IDs::Pai):
    {
        cout << "Bateu no inimigoD" << endl;
    }
    break;
    case (IDs::IDs::plataforma):
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
    animacao.addAnimacao("C:/Users/crisn/Desktop/projetoTecProg/Midia/Anda.png", "ANDA", 1, 0.12f, sf::Vector2f(2, 1));
    animacao.addAnimacao("C:/Users/crisn/Desktop/projetoTecProg/Midia/Parado.png", "PARADO", 1, 0.12f, sf::Vector2f(2, 1));
    animacao.addAnimacao("C:/Users/crisn/Desktop/projetoTecProg/Midia/Pula.png", "PULA", 1, 0.12f, sf::Vector2f(2, 1));
    animacao.addAnimacao("C:/Users/crisn/Desktop/projetoTecProg/Midia/Cai.png", "CAI", 1, 0.12f, sf::Vector2f(2, 1));
    corpo.setOrigin(tam.x / 3.0f, tam.y / 3.0f);
}