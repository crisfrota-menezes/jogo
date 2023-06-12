#include "estadoMPrincipal.hpp"

EstadoMenuPrincipal::EstadoMenuPrincipal(const IDs::IDs ID) : Estado(ID), menuPrincipal()
{
}

EstadoMenuPrincipal::~EstadoMenuPrincipal()
{
}

void EstadoMenuPrincipal::executar()
{
    menuPrincipal.executar();
}