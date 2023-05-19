#include "inimigo.hpp"

Entidades::Personagem::Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador *jogador) : Personagem(pos, tam), relogio(), jogador(jogador)
{
    corpo.setFillColor(sf::Color::Red);
    inicializa();
    srand(time(NULL));
    moveAleatorio = rand() % 4;
}

Entidades::Personagem::Inimigo::~Inimigo()
{
}

void Entidades::Personagem::Inimigo::inicializa()
{
    vel = sf::Vector2f(VELOCIDADE_INIMIGO_X, VELOCIDADE_INIMIGO_Y);
}

void Entidades::Personagem::Inimigo::perseguir(sf::Vector2f posJogador, sf::Vector2f posInimigo)
{
    if (posJogador.x - posInimigo.x > 0.0f)
    {
        corpo.move(vel.x, 0.0f);
    }
    else
    {
        corpo.move(-vel.x, 0.0f);
    }

    if (posJogador.y - posInimigo.y > 0.0f)
    {
        corpo.move(0.0f, vel.y);
    }
    else
    {
        corpo.move(0.0f, -vel.y);
    }
}

void Entidades::Personagem::Inimigo::movimentoAleatorio()
{
}

void Entidades::Personagem::Inimigo::move()
{
    sf::Vector2f posJogador = jogador->getCorpo().getPosition();
    sf::Vector2f posInimigo = corpo.getPosition();

    if (fabs(posJogador.x - posInimigo.x) <= RAIO_PERSEGUIR_X && fabs(posJogador.y - posInimigo.y) <= RAIO_PERSEGUIR_Y)
    {
        perseguir(posJogador, posInimigo);
    }
    else
    {
        movimentoAleatorio();
    }
}