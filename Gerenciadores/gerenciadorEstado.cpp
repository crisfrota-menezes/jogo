#include "gerenciadorEstado.hpp"

GerenciadorEstado *GerenciadorEstado::pGerenciadorEstado = nullptr;

GerenciadorEstado::GerenciadorEstado() : pilhaEstados(), construtorEstado()
{
}

GerenciadorEstado *GerenciadorEstado::getGerenciadorEstado()
{
    if (pGerenciadorEstado == nullptr)
    {
        pGerenciadorEstado = new GerenciadorEstado();
    }
    return pGerenciadorEstado;
}

GerenciadorEstado::~GerenciadorEstado()
{
    // deleta todos os estados da minha pilha
    while (!pilhaEstados.empty())
    {
        delete (pilhaEstados.top());
        pilhaEstados.top() = nullptr;
        pilhaEstados.pop();
    }
    if (pGerenciadorEstado)
    {
        delete (pGerenciadorEstado);
        pGerenciadorEstado = nullptr;
    }
}

void GerenciadorEstado::ativarObservadores()
{
    Estado *estadoAtual = getEstadoAtual();
    switch (estadoAtual->getID())
    {
    case (IDs::IDs::jogar_Fase1):
    {
        EstadoJogar *estadoJogar = static_cast<EstadoJogar *>(estadoAtual);
        Jogador *pJogador = estadoJogar->getJogador();
        pJogador->ativaObs();
    }
    break;
    case (IDs::IDs::jogar_Fase2):
    {
        EstadoJogar *estadoJogar = static_cast<EstadoJogar *>(estadoAtual);
        Jogador *pJogador = estadoJogar->getJogador();
        pJogador->ativaObs();
    }
    break;
    case (IDs::IDs::estadoMenuPrincipal):
    {
    }
    break;
    }
}

void GerenciadorEstado::desativarObservadores()
{
    Estado *estadoAtual = getEstadoAtual();
    switch (estadoAtual->getID())
    {
    case (IDs::IDs::jogar_Fase1):
    {
        EstadoJogar *estadoJogar = static_cast<EstadoJogar *>(estadoAtual);
        Jogador *pJogador = estadoJogar->getJogador();
        pJogador->desativaObs();
    }
    break;
    case (IDs::IDs::jogar_Fase2):
    {
        EstadoJogar *estadoJogar = static_cast<EstadoJogar *>(estadoAtual);
        Jogador *pJogador = estadoJogar->getJogador();
        pJogador->desativaObs();
    }
    case (IDs::IDs::estadoMenuPrincipal):
    {
        // terminar...
    }
    break;
    }
}

void GerenciadorEstado::addEstado(const IDs::IDs ID)
{
    Estado *estado = construtorEstado.criarEstado(ID);
    if (estado == nullptr)
    {
        cout << "Erro ao criar estado" << endl;
        exit(0);
    }
    if (!pilhaEstados.empty())
    {
        desativarObservadores();
    }
    pilhaEstados.push(estado);
}

void GerenciadorEstado::removerEstado()
{
    if (pilhaEstados.top() != nullptr)
    {
        delete (pilhaEstados.top());
        pilhaEstados.top() = nullptr;
        pilhaEstados.pop();
    }
    if (!pilhaEstados.empty())
    {
        ativarObservadores();
    }
    else
    {
        GerenciadorGrafico *pGrafico = pGrafico->getGerenciadorGrafico();
        pGrafico->fechaJanela();
    }
}

Estado *GerenciadorEstado::getEstadoAtual()
{
    return pilhaEstados.top();
}

void GerenciadorEstado::executar()
{
    // executa o estado que está no topo da minha pilha
    if (!pilhaEstados.empty())
    {
        pilhaEstados.top()->executar();
    }
}