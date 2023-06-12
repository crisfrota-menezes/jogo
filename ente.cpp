#include "ente.hpp"

GerenciadorGrafico *pGrafico = getGerenciadorGrafico();

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
