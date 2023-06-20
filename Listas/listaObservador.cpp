#include "listaObservador.hpp"

ListaObservador::ListaObservador() : listaObs()
{
}

ListaObservador::~ListaObservador()
{
    listaObs.limpar();
}

void ListaObservador::addObservador(Observador *observador)
{
    listaObs.inserir(observador);
}

void ListaObservador::removerObservador(Observador *observador)
{
    listaObs.remover(observador);
}

void ListaObservador::removerObservador(int pos)
{
    listaObs.remover(pos);
}

int ListaObservador::getTam()
{
    return listaObs.getTam();
}

Observador *ListaObservador::operator[](int pos)
{
    return listaObs.operator[](pos);
}

void ListaObservador::notificarTeclaPress(const sf::Keyboard::Key tecla)
{
    for (int i = 0; i < listaObs.getTam(); i++)
    {
        Observador *observador = listaObs.operator[](i);
        if(observador->getAtiva()) {
            observador->teclaPressionada(tecla);
        }
        observador = nullptr;
    }
}

void ListaObservador::notificarTeclaSolta(const sf::Keyboard::Key tecla)
{
    for (int i = 0; i < listaObs.getTam(); i++)
    {
        Observador *observador = listaObs.operator[](i);
        if(observador->getAtiva()) {
            observador->teclaSolta(tecla);
        }
        observador = nullptr;
    }
}