#include "construtorFase.hpp"

ConstrutorFase::ConstrutorFase()
{
}

ConstrutorFase::~ConstrutorFase()
{
}

Fase *ConstrutorFase::criarFase1()
{
    Fase *fase = static_cast<Fase *>(new Fase1());
    if (fase == nullptr)
    {
        cout << "nao foi possivel criar uma Fase1" << endl;
        exit(1);
    }
    return fase;
}

Fase *ConstrutorFase::criarFase2()
{
    Fase *fase = static_cast<Fase *>(new Fase2());
    if (fase == nullptr)
    {
        cout << "nao foi possivel criar uma Fase2" << endl;
        exit(1);
    }
    return fase;
}

Fase *ConstrutorFase::criarFase(const IDs::IDs ID)
{
    Fase *fase = nullptr;
    switch (ID)
    {
    case (IDs::IDs::jogar_Fase1):
    {
        fase = criarFase1();
    }
    break;
    case (IDs::IDs::jogar_Fase2):
    {
        fase = criarFase2();
    }
    break;
    default:
    {
        cout << "ID da Fase invalido" << endl;
        exit(1);
    }
    break;
    }
    fase->criarFundo();
    fase->criarMapa();
    return fase;
}