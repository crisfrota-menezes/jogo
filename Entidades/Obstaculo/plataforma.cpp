#include "plataforma.hpp"

Plataforma::Plataforma(sf::Vector2f pos) : Obstaculo(pos, sf::Vector2f(TAMANHO_PLATAFORMA_X, TAMANHO_PLATAFORMA_Y), IDs::IDs::plataforma, CAMINHO_PLATAFORMA)
{
}

Plataforma::~Plataforma()
{
}

void Plataforma::colisao(Entidade *outraEntidade, sf::Vector2f ds)
{
    sf::Vector2f posOutro = outraEntidade->getPos();
    sf::Vector2f tamOutro = outraEntidade->getTam();

    if (outraEntidade->getID() == IDs::IDs::jogador || outraEntidade->getID() == IDs::IDs::Uraniano)
    {
        colisaoObstaculo(ds, static_cast<Personagem *>(outraEntidade));
    }
}