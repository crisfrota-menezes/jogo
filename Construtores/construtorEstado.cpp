#include "construtorEstado.hpp"

ConstrutorEstado::ConstrutorEstado()
{
}

ConstrutorEstado::~ConstrutorEstado()
{
}

Estado *ConstrutorEstado::addEstadoJogar(const IDs::IDs ID)
{
    Fase *fase = nullptr;
    if (ID == IDs::IDs::jogar_Fase1)
    {
        fase = static_cast<Fase *>(new Fase1());
    }
    else
    {
        fase = static_cast<Fase *>(new Fase2());
    }
    if (fase == nullptr)
    {
        cout << "nao foi possivel criar uma fase" << endl;
        exit(1);
    }
    fase->criarFundo();
    fase->criarMapa();
    EstadoJogar *estadoJogar = new EstadoJogar(fase);
    if (estadoJogar == nullptr)
    {
        cout << "nao foi possivel criar um Estado Jogar" << endl;
        exit(1);
    }
    return static_cast<Estado *>(estadoJogar);
}