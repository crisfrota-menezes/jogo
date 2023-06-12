#include "gerenciadorEvento.hpp"
#include "gerenciadorEstado.hpp"

GerenciadorEvento* GerenciadorEvento::pEvento = nullptr;
GerenciadorGrafico* GerenciadorEvento::pGrafico = GerenciadorGrafico::getGerenciadorGrafico();
GerenciadorEstado* GerenciadorEvento::pEstado = GerenciadorEstado::getGerenciadorEstado();
ListaObservador* GerenciadorEvento::listaObservador = new ListaObservador();

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

void GerenciadorEvento::verificaTeclaPressionada(sf::Keyboard::Key tecla)
{
    if (pEstado->getEstadoAtual()->getID() == IDs::IDs::jogar_Fase1 || pEstado->getEstadoAtual()->getID() == IDs::IDs::jogar_Fase2)
    {
        EstadoJogar *estadoJogar = dynamic_cast<EstadoJogar *>(pEstado->getEstadoAtual());
        Jogador *pJogador = estadoJogar->getJogador();
        if (pJogador == nullptr)
        {
            cout << "pJogador eh nullptr" << endl;
            exit(1);
        }
        if (tecla == sf::Keyboard::A)
        {
            pJogador->andar(true);
        }
        else if (tecla == sf::Keyboard::D)
        {
            pJogador->andar(false);
        }
        else if (tecla == sf::Keyboard::W)
        {
            pJogador->pular();
        }
        else if (tecla == sf::Keyboard::S)
        {
            pJogador->atacar(true);
        }
    }
}

void GerenciadorEvento::verificaTeclaSolta(sf::Keyboard::Key tecla)
{
    if (pEstado->getEstadoAtual()->getID() == IDs::IDs::jogar_Fase1 || pEstado->getEstadoAtual()->getID() == IDs::IDs::jogar_Fase2)
    {
        EstadoJogar *estadoJogar = dynamic_cast<EstadoJogar *>(pEstado->getEstadoAtual());
        Jogador *pJogador = estadoJogar->getJogador();
        if (pJogador == nullptr)
        {
            cout << "pJogador eh nullptr" << endl;
            exit(1);
        }
        if (tecla == sf::Keyboard::A || tecla == sf::Keyboard::D)
        {
            pJogador->parar();
        }
    }
    if (tecla == sf::Keyboard::Escape)
    {
        pEstado->removerEstado();
    }
}

void GerenciadorEvento::executar()
{
    sf::Event evento;
    while (pGrafico->getWindow()->pollEvent(evento))
    {
        if (evento.type == sf::Event::Closed)
        {
            pGrafico->fechaJanela();
        }
        else if (evento.type == sf::Event::KeyPressed)
        {
            //verificaTeclaPressionada(evento.key.code);
            listaObservador->notificarTeclaPress(evento.key.code);
        }
        else if (evento.type == sf::Event::KeyReleased)
        {
            //verificaTeclaSolta(evento.key.code);
            listaObservador->notificarTeclaSolta(evento.key.code);
        }
    }
}