#include "gerenciadorEvento.hpp"

GerenciadorEvento *GerenciadorEvento::pEvento = nullptr;

GerenciadorEvento::GerenciadorEvento()
{
    pGrafico = GerenciadorGrafico::getGerenciadorGrafico();
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

void GerenciadorEvento::setJogador(Jogador *pJogador)
{
    this->pJogador = pJogador;
}

void GerenciadorEvento::verificaTeclaPressionada(sf::Keyboard::Key tecla)
{
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
    else if (tecla == sf::Keyboard::Escape)
    {
        pGrafico->fechaJanela();
    }
}

void GerenciadorEvento::verificaTeclaSolta(sf::Keyboard::Key tecla)
{
    if(tecla == sf::Keyboard::A || tecla == sf::Keyboard::D){
        pJogador->parar();
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
            verificaTeclaPressionada(evento.key.code);
        }
        else if (evento.type == sf::Event::KeyReleased)
        {
            verificaTeclaSolta(evento.key.code);
        }
    }
}