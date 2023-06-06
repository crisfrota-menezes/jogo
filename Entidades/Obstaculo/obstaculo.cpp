#include "obstaculo.hpp"

Obstaculo::Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID) : Entidade(pos, tam, ID), caminho(CAMINHO_TEXTURA)
{
    textura = pGrafico->carregarTextura(caminho);
    corpo.setTexture(&textura);
}

Obstaculo::~Obstaculo()
{
}

void Obstaculo::atualizar()
{
    desenhar();
}