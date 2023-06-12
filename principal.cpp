
#include "principal.hpp"

GerenciadorGrafico *pGrafico = getGerenciadorGrafico();
GerenciadorEvento *pEvento = getGerenciadorEvento();
GerenciadorEstado *pEstado = getGerenciadorEstado();

Jogo::Jogo()
{
    if (pGrafico == nullptr)
    {
        cout << "Erro ao criar o gerenciador grafico" << endl;
        exit(1);
    }

    if (pEvento == nullptr)
    {
        cout << "Erro ao criar o gerenciador de eventos" << endl;
        exit(1);
    }

    if (pEstado == nullptr)
    {
        cout << "nao foi possivel criar um GerenciadorEstado" << endl;
        exit(1);
    }
    pEstado->addEstado(IDs::IDs::jogar_Fase1);
    run();
}

Jogo::~Jogo()
{
}

void Jogo::run()
{
    while (pGrafico->janelaAberta())
    {
        pEvento->executar();
        pGrafico->limpar();
        pEstado->executar();
        pGrafico->mostraElementos();
    }
}