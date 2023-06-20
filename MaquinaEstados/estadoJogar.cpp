#include "estadoJogar.hpp"

EstadoJogar::EstadoJogar(const IDs::IDs ID, Fase *fase) : Estado(ID), fase(fase)
{
}

EstadoJogar::~EstadoJogar()
{
    if (fase)
    {
        delete fase;
        fase = nullptr;
    }
}

void EstadoJogar::executar()
{
    fase->executar();
}

Jogador *EstadoJogar::getJogador()
{
    return fase->getJogador();
}