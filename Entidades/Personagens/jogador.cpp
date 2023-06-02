#include "jogador.hpp"

Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam) : Personagem(pos, tam, VELOCIDADE_JOGADOR, IDs::IDs::jogador), noChao(false)
{
    sf::Vector2f posAleatoria = posicaoAleatoria(1920, 1080);
    setPos(posAleatoria);
    corpo.setFillColor(sf::Color::Green);
    inicializa();
}

Jogador::~Jogador()
{
}

void Jogador::atualizar()
{
    atualizarPos();
}

void Jogador::colisao(Entidade *outraEnt, sf::Vector2f ds)
{
    switch (outraEnt->getID())
    {
    case (IDs::IDs::inimigo):
    {
        std::cout << "Bateu no inimigo" << std::endl;
    }
    break;

    case (IDs::IDs::obsGenerico):
    {
        std::cout << "Bateu no obstaculo generico" << std::endl;
    }
    break;
    }
}

void Jogador::inicializa()
{
}