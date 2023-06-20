#include "gerenciadorEvento.hpp"
#include "gerenciadorEstado.hpp"

GerenciadorEvento* GerenciadorEvento::pEvento = nullptr;
GerenciadorGrafico* GerenciadorEvento::pGrafico = GerenciadorGrafico::getGerenciadorGrafico();
GerenciadorEstado* GerenciadorEvento::pEstado = GerenciadorEstado::getGerenciadorEstado();
ListaObservador* GerenciadorEvento::listaObservador = nullptr;

GerenciadorEvento::GerenciadorEvento()
{
    listaObservador = new ListaObservador();
    if (listaObservador == nullptr)
    {
        cout << "nao foi possivel criar uma Lista de Observadores" << endl;
        exit(1);
    }
}

GerenciadorEvento::~GerenciadorEvento()
{
    if (listaObservador)
    {
        delete listaObservador;
        listaObservador = nullptr;
    }
}

GerenciadorEvento *GerenciadorEvento::getGerenciadorEvento()
{
    if (pEvento == nullptr)
    {
        pEvento = new GerenciadorEvento();
    }
    return pEvento;
}

void GerenciadorEvento::addObservador(Observador* obs)
{
    listaObservador->addObservador(obs);
}

void GerenciadorEvento::removerObservador(Observador* obs)
{
    listaObservador->removerObservador(obs);
}

void GerenciadorEvento::removerObservador(int pos)
{
    listaObservador->removerObservador(pos);
}

void GerenciadorEvento::executar()
{
    sf::Event evento;
    while (pGrafico->getWindow()->pollEvent(evento))
    {
        if(evento.type == sf::Event::KeyPressed) {
            if(evento.key.code == sf::Keyboard::Q) {
                pEstado->addEstado(IDs::IDs::jogar_Fase1);
            }
            else if(evento.key.code == sf::Keyboard::Escape) {
                pEstado->removerEstado();
            }
            else
            {
                listaObservador->notificarTeclaPress(evento.key.code);
            }
        }
        else if(evento.type == sf::Event::KeyReleased) {
            listaObservador->notificarTeclaSolta(evento.key.code);
        }
        else if(evento.type == sf::Event::Closed) {
            pGrafico->fechaJanela();
        }
    }
}