#include "obstaculo.hpp"

Obstaculo::Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID) : Entidade(pos, tam, ID)
{
    textura = pGrafico->carregarTextura(caminhoTextura);
    corpo.setTexture(textura);
}

Obstaculo::~Obstaculo()
{
}
