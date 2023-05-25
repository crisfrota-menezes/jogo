#include "inimigo.hpp"

Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador *jogador) : Personagem(pos, tam, IDs::IDs::inimigo), jogador(jogador)
{
    corpo.setFillColor(sf::Color::Red);
    inicializa();
    srand(time(NULL));
    moveAleatorio = rand() % 4;
}

Inimigo::~Inimigo()
{
}

void Inimigo::inicializa()
{
    vel = sf::Vector2f(VELOCIDADE_INIMIGO_X, VELOCIDADE_INIMIGO_Y);
}

void Inimigo::perseguir(sf::Vector2f posJogador, sf::Vector2f posInimigo)
{
    if (posJogador.x - posInimigo.x > 0.0f)
        corpo.move(vel.x, 0.0f);
    else
        corpo.move(-vel.x, 0.0f);
    if (posJogador.y - posInimigo.y > 0.0f)
        corpo.move(0.0f, vel.y);
    else
        corpo.move(0.0f, -vel.y);
}

void Inimigo::movimentoAleatorio()
{
    if (moveAleatorio == 0)
        corpo.move(vel.x, 0.0f);
    else if (moveAleatorio == 1)
        corpo.move(-vel.x, 0.0f);
    else if (moveAleatorio == 2)
        corpo.move(0.0f, vel.y);
    else
        corpo.move(0.0f, -vel.y);

    float dt = relogio.getElapsedTime().asSeconds();
    if (dt >= 1.0f)
    {
        moveAleatorio = rand() % 4;
        relogio.restart();
    }
}

void Inimigo::colisao(Entidade *outraEntidade, sf::Vector2f ds)
{
    switch (outraEntidade->getID())
    {
    case (IDs::IDs::jogador):
    {
        std::cout << "Bate jogador e jogador pode bater no inimigo" << std::endl;
    }
    break;
    case (IDs::IDs::inimigo):
    {
        std::cout << "Empurra inimigo" << std::endl;
    }
    break;
    }
}

void Inimigo::atualizar()
{
    sf::Vector2f posJogador = jogador->getCorpo().getPosition();
    sf::Vector2f posInimigo = corpo.getPosition();

    if (fabs(posJogador.x - posInimigo.x) <= VISAO_INIMIGO_X && fabs(posJogador.y - posInimigo.y) <= VISAO_INIMIGO_Y)
    {
        perseguir(posJogador, posInimigo);
    }
    else
    {
        movimentoAleatorio();
    }
}