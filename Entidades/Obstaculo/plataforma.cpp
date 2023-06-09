#include "plataforma.hpp"

Plataforma::Plataforma(const sf::Vector2f pos) : Obstaculo(pos, sf::Vector2f(TAMANHO_PLATAFORMA_X, TAMANHO_PLATAFORMA_Y), IDs::IDs::plataforma, CAMINHO_PLATAFORMA)
{
}

Plataforma::~Plataforma()
{
}

void Plataforma::colisao(Entidade *outraEnt, sf::Vector2f ds)
{
    sf::Vector2f posOutro = outraEnt->getPos();
    sf::Vector2f tamOutro = outraEnt->getTam();

    if (outraEnt->getID() == IDs::IDs::jogador || outraEnt->getID() == IDs::IDs::Uraniano || outraEnt->getID() == IDs::IDs::Alien2 || outraEnt->getID() == IDs::IDs::Alien3)
    {
        colisaoObstaculo(ds, static_cast<Personagem *>(outraEnt));
    }
}