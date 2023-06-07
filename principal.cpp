
#include "principal.hpp"

Jogo::Jogo() : pGrafico(pGrafico->getGerenciadorGrafico()), pEvento(pEvento->getGerenciadorEvento()), fase(nullptr)
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

    criarFase();
    run();
}

Jogo::~Jogo()
{
    if (fase)
    {
        delete fase;
        fase = nullptr;
    }
}

void Jogo::criarFase()
{
    Fase1 *aux = new Fase1();
    if (aux == nullptr)
    {
        cout << "Erro ao criar a fase" << endl;
        exit(1);
    }
    fase = static_cast<Fase *>(aux);
    fase->criarMapa();
}

void Jogo::run()
{
    while (pGrafico->janelaAberta())
    {
        pEvento->executar();
        pGrafico->limpar();
        pGrafico->carregarBackground();
        fase->executar();
        pGrafico->mostraElementos();
    }
}