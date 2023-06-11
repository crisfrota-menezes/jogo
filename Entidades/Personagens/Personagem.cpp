#include "Personagem.hpp"

Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam, const float vel, const IDs::IDs ID) : Entidade(pos, tam, ID), podeMover(false), paraEsquerda(false), relogio(),
                                                                                                             dt(0.0f), velFinal(sf::Vector2f(vel, 0.0f)), velMax(vel), atacando(false),
                                                                                                             animacao(&corpo)
{
}

Personagem::~Personagem()
{
}

void Personagem::andar(const bool paraEsquerda)
{
    atacando = false;
    podeMover = true;
    this->paraEsquerda = paraEsquerda;
}

void Personagem::parar()
{
    podeMover = false;
}

void Personagem::atacar(const bool atacando)
{
    podeMover = false;
    this->atacando = atacando;
}

void Personagem::atualizarPos()
{
    dt = relogio.getElapsedTime().asSeconds();
    relogio.restart();
    sf::Vector2f ds(0.0f, 0.0f);

    // move na horizontal
    if (podeMover)
    {
        ds.x = velFinal.x * dt;
        if (paraEsquerda)
        {
            ds.x *= -1;
        }
    }

    // sofre o efeito da gravidade
    velFinal.y += GRAVIDADE * dt;
    ds.y = velFinal.y * GRAVIDADE;

    // atualiza posição
    setPos(sf::Vector2f(pos.x + ds.x, pos.y + ds.y));

    // atualiza velocidade na horizontal
    velFinal.x = velMax;

    // desenha na janela
    desenhar();
}

void Personagem::setVelFinal(sf::Vector2f velFinal)
{
    this->velFinal = velFinal;
}

const sf::Vector2f Personagem::getVelFinal() const
{
    return velFinal;
}

void Personagem::animar()
{
    if (podeMover)
    {
        animacao.atualizar(paraEsquerda, "ANDA");
    }
    else
    {
        animacao.atualizar(paraEsquerda, "PARADO");
    }
}

bool Personagem::getAtacando()
{
    atacando = true;
    return atacando;
}