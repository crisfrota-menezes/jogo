#include "Personagem.hpp"

Personagem::Personagem(const sf::Vector2f pos, const sf::Vector2f tam, const float vel, const IDs::IDs ID) : Entidade(pos, tam, ID), velFinal(sf::Vector2f(vel, 0.0f)), podeMover(false), paraEsquerda(false), relogio(), dt(0.0f), velMax(vel)
{
}

Personagem::~Personagem()
{
}

void Personagem::setVelFinal(const sf::Vector2f vel)
{
    this->velFinal = velFinal;
}

const sf::Vector2f Personagem::getVelFinal()
{
    return velFinal;
}

void Personagem::andar(const bool paraEsquerda)
{
    podeMover = true;
    this->paraEsquerda = paraEsquerda;
}

void Personagem::parar()
{
    podeMover = false;
    // velFinal.x = 0.0f;
}

void Personagem::atualizarPos()
{
    dt = relogio.getElapsedTime().asSeconds();
    if (dt > 0.3f)
    {
        dt = 0.0f;
    }
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

    // para de cair quando chega no chão
    /*if (pos.y + tam.y >= 1080)
    {
        velFinal.y = 0.0f;
        setPos(sf::Vector2f(pos.x, 1080 - tam.y));
        noChao = true;
    }*/

    // desenhar
    desenhar();
}