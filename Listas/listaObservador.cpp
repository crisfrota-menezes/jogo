#include "listaObservador.hpp"

ListaObservador::ListaObservador() : listaObs()
{
}

ListaObservador::~ListaObservador()
{
    listaObs.limparLista();
}

void ListaObservador::addObservador(Observador::Observador *observador)
{
    listaObs.addElemento(observador);
}

void ListaObservador::removerObservador(Observador::Observador *observador)
{
    listaObs.removerElemento(observador);
}

void ListaObservador::removerObservador(int pos)
{
    listaObs.removerElemento(pos);
}

int ListaObservador::getTam()
{
    return listaObs.getTam();
}

Observador::Observador *ListaObservador::operator[](int pos)
{
    return listaObs.operator[](pos);
}

void ListaObservador::notificarTeclaPress(const sf::Keyboard::Key tecla)
{
    for (int i = 0; i < listaObs.getTam(); i++)
    {
        Observador *observador = listaObs.operator[](i);
        observador->teclaPressionada(tecla);
        observador = nullptr;
    }
}

void ListaObservador::notificarTeclaSolta(const sf::Keyboard::Key tecla)
{
    for (int i = 0; i < listaObs.getTam(); i++)
    {
        Observador *observador = listaObs.operator[](i);
        observador->teclaSolta(tecla);
        observador = nullptr;
    }
}