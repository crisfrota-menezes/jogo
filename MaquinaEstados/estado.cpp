#include "estado.hpp"

Estado::Estado(const IDs::IDs ID) : Ente(ID), remover(false)
{
}

Estado::~Estado()
{
}

void Estado::desenhar()
{
}

const bool Estado::getRemover() const
{
    return remover;
}

void Estado::setRemover(const bool remover)
{
    this->remover = remover;
}