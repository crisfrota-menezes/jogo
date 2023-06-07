#include "arvore.hpp"

Arvore::Arvore(sf::Vector2f pos) : Obstaculo(pos, sf::Vector2f(TAMANHO_Arvore_X, TAMANHO_Arvore_Y), IDs::IDs::Arvore, CAMINHO_TEXTURA_Arvore)
{
}

Arvore::~Arvore()
{
}

void Arvore::colisao(Entidade *outraEnt, sf::Vector2f ds)
{
    sf::Vector2f posOutro = outraEnt->getPos();
    sf::Vector2f tamOutro = outraEnt->getTam();

    if (outraEnt->getID() == IDs::IDs::jogador || outraEnt->getID() == IDs::IDs::Alien1 || outraEnt->getID() == IDs::IDs::Alien2 || outraEnt->getID() == IDs::IDs::Alien3)
    {
        colisaoObstaculo(ds, static_cast<Personagem *>(outraEnt));
    }
}