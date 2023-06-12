#include "observador.hpp"
#include "../Gerenciadores/gerenciadorEvento.hpp"

GerenciadorEvento *Observador::pEvento = GerenciadorEvento::getGerenciadorEvento();

Observador::Observador()
{
    pEvento->addObservador(this);
}

Observador::~Observador()
{
}