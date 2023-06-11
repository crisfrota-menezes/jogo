#include "gerenciadorEstado.hpp"

GerenciadorEstado *GerenciadorEstado::pGerenciadorEstado = nullptr;

GerenciadorEstado::GerenciadorEstado() : pilhaEstados(), construtor()
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

void GerenciadorEstado::addEstado(const IDs::IDs ID)
{
    Estado *estado = nullptr;
    if (ID == IDs::IDs::jogar_Fase1 || ID == IDs::IDs::jogar_Fase2)
    {
        estado = construtor.criarEstadoJogar(ID);
    }
    pilhaEstados.push(estado);
}

void GerenciadorEstado::removerEstado()
{
    delete (pilhaEstados.top());
    pilhaEstados.top() = nullptr;
    pilhaEstados.pop();

    if (pilhaEstados.empty())
    {
        Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico()->fechaJanela();
    }
}

void GerenciadorEstado::executar()
{
    // executa o estado que está no topo da minha pilha
    if (!pilhaEstados.empty())
    {
        pilhaEstados.top()->executar();
    }
}