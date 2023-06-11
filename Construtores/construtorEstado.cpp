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
    if (estadoJogar == nullptr)
    {
        cout << "nao foi possivel criar um Estado Jogar" << endl;
        exit(1);
    }
    return static_cast<Estado *>(estadoJogar);
}

Estado *ConstrutorEstado::criarEstado(const IDs::IDs ID)
{
    if (ID == IDs::IDs::jogar_Fase1 || ID == IDs::IDs::jogar_Fase2)
    {
        return criarEstadoJogar(ID);
    }
    else
    {
        cout << "nao foi possivel criar um Estado" << endl;
    }
    return nullptr;
}