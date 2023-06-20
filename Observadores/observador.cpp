#include "observador.hpp"
#include "../Gerenciadores/gerenciadorEvento.hpp"

GerenciadorEvento *Observador::pEvento = GerenciadorEvento::getGerenciadorEvento();

Observador::Observador() : ativa(true)
{
    pEvento->addObservador(this);
}

Observador::~Observador()
{
}

void Observador::remove()
{
    pEvento->removerObservador(this);
}

void Observador::ativar()
{
    ativa = true;
}

void Observador::desativar()
{
    ativa = false;
}

const bool Observador::getAtiva() const
{
    return ativa;
}