#include "maquinaEstado.hpp"

MaquinaEstado::MaquinaEstado() : pilhaEstados()
{
}

MaquinaEstado::~MaquinaEstado()
{
    // deleta todos os estados da minha pilha
    while (!pilhaEstados.empty())
    {
        delete (pilhaEstados.top());
        pilhaEstados.top() = nullptr;
        pilhaEstados.pop();
    }
}

void MaquinaEstado::addEstadoJogar(const IDs::IDs ID)
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
    pilhaEstados.push(static_cast<Estado *>(estadoJogar));
}

void MaquinaEstado::addEstado(const IDs::IDs ID)
{
    if (ID == IDs::IDs::jogar_Fase1 || ID == IDs::IDs::jogar_Fase2)
    {
        addEstadoJogar(ID);
    }
}

void MaquinaEstado::removerEstado()
{
    delete (pilhaEstados.top());
    pilhaEstados.top() = nullptr;
    pilhaEstados.pop();

    if (pilhaEstados.empty())
    {
        Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico()->fechaJanela();
    }
}

void MaquinaEstado::executar()
{
    // executa o estado que está no topo da minha pilha
    if (!pilhaEstados.empty())
    {
        pilhaEstados.top()->executar();
    }
}