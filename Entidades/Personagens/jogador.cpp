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
    
}

void Jogador::inicializa()
{
}