#include "inimigo.hpp"

Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador *jogador) : Personagem(pos, tam, VELOCIDADE_INIMIGO, IDs::IDs::inimigo), jogador(jogador), dtAux(0.0f)
{
    corpo.setFillColor(sf::Color::Red);
    srand(time(NULL));
    moveAleatorio = rand() % 3;
    if (moveAleatorio == 0)
    {
        parar();
    }
    else if (moveAleatorio == 1)
    {
        andar(true);
    }
    else
    {
        andar(false);
    }
}

Inimigo::~Inimigo()
{
}

void Inimigo::inicializa()
{
    // animacao.addAnimacao("C:/Users/crisn/Desktop/projetoTecProg/Midia/Anda.png", "ANDA", 10, 0.12f, sf::Vector2f(6, 2));
}

void Inimigo::atualizaMoveAleatorio()
{
    if (dtAux > 1.0f)
    {
        moveAleatorio = rand() % 3;
        if (moveAleatorio == 0)
        {
            parar();
        }
        else if (moveAleatorio == 1)
        {
            andar(true);
        }
        else
        {
            andar(false);
        }
        dtAux = 0.0f;
    }
}

void Inimigo::colisao(Entidade *outraEntidade, sf::Vector2f ds)
{
    switch (outraEntidade->getID())
    {
    case (IDs::IDs::jogador):
    {
        cout << "Bateu no jogador" << endl;
    }
    break;
    case (IDs::IDs::plataforma):
    {
        cout << "Bateu na plataforma" << endl;
    }
    }
}

void Inimigo::atualizar()
{
    sf::Vector2f posJogador = jogador->getPos();
    sf::Vector2f posInimigo = getPos();
    if (fabs(posJogador.x - posInimigo.x) <= VISAO_INIMIGO_X && fabs(posJogador.y - posInimigo.y) <= VISAO_INIMIGO_Y)
    {
        if (posJogador.x - posInimigo.x > 0.0f)
        {
            andar(false);
        }
        else
        {
            andar(true);
        }
    }
    else
    {
        atualizaMoveAleatorio();
    }
    // moveInimigo();
    atualizarPos();
    dtAux += relogio.getElapsedTime().asSeconds();
    relogio.restart();
    // animar();
}

/*void Inimigo::animar()
{
    if (!noChao && velFinal.y > 0.0f)
    {
        animacao.atualizar(paraEsquerda, "CAI");
    }
    else if (noChao)
    {
        animacao.atualizar(paraEsquerda, "PULA");
    }
    else
    if (podeMover)
    {
        animacao.atualizar(paraEsquerda, "ANDA");
    }
    else
    {
        animacao.atualizar(paraEsquerda, "PARADO");
    }
}*/