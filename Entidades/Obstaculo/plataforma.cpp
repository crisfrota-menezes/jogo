#include "plataforma.hpp"

Plataforma::Plataforma(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID, const char *caminhoTextura) : Obstaculo(pos, tam, ID, caminhoTextura)
{
}

Plataforma::~Plataforma()
{
}

void Plataforma::colisao(Entidade *outraEnt, sf::Vector2f ds)
{
    sf::Vector2f posOutro = outraEnt->getPos();
    sf::Vector2f tamOutro = outraEnt->getTam();

    if (outraEnt->getID() == IDs::IDs::jogador)
    {
        colisaoObstaculo(ds, static_cast<Personagem *>(outraEnt));
    }
    else if (outraEnt->getID() == IDs::IDs::inimigo)
    {
        colisaoObstaculo(ds, static_cast<Personagem *>(outraEnt));
    }
}