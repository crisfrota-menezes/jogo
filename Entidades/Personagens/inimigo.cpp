#include "inimigo.hpp"

Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador *jogador, IDs::IDs ID) : Personagem(pos, tam, VELOCIDADE_INIMIGO, ID), jogador(jogador), dtAux(0.0f)
{
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
    atualizarPos();
    dtAux += relogio.getElapsedTime().asSeconds() * 100;
    relogio.restart();
    animar();
}

void Inimigo::colisao(Entidade *outraEntidade, sf::Vector2f ds)
{
    switch (outraEntidade->getID())
    {
    case (IDs::IDs::jogador):
    {
    }
    break;
    }
}