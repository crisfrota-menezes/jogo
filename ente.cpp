#include "ente.hpp"

GerenciadorGrafico *pGrafico = GerenciadorGrafico::getGerenciadorGrafico();

Ente::Ente(const IDs::IDs ID) : ID(ID)
{
}

Ente::~Ente()
{
}

const IDs::IDs Ente::getID() const
{
    return ID;
}
