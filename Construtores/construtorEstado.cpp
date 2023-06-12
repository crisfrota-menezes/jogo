#include "construtorEstado.hpp"

ConstrutorEstado::ConstrutorEstado()
{
}

ConstrutorEstado::~ConstrutorEstado()
{
}

Estado *ConstrutorEstado::criarEstadoJogar(const IDs::IDs ID)
{
    Fase *fase = nullptr;

    ConstrutorFase construtorFase;

    fase = construtorFase.criarFase(ID);
    EstadoJogar *estadoJogar = new EstadoJogar(ID, fase);
    return static_cast<Estado *>(estadoJogar);
}

Estado *ConstrutorEstado::criarEstadoMenuPrincipal(const IDs::IDs ID)
{
    Estado *estado = static_cast<Estado *>(new EstadoMenuPrincipal(ID));
    return estado;
}

Estado *ConstrutorEstado::criarEstado(const IDs::IDs ID)
{
    if (ID == IDs::IDs::jogar_Fase1 || ID == IDs::IDs::jogar_Fase2)
    {
        return criarEstadoJogar(ID);
    }
    else if (ID == IDs::IDs::estadoMenuPrincipal)
    {
        return criarEstadoMenuPrincipal(ID);
    }
    return nullptr;
}