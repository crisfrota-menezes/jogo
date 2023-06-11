#include "estadoJogar.hpp"

EstadoJogar::EstadoJogar(const IDs::IDs ID, Fase *fase) : Estado(ID), fase(fase)
{
}

EstadoJogar::~EstadoJogar()
{
}

void EstadoJogar::executar()
{
    fase->executar();
}

Jogador *EstadoJogar::getJogador()
{
    return fase->getJogador();
}