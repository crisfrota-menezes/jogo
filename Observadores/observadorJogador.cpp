#include "observadorJogador.hpp"

ObservadorJ::ObservadorJ(Jogador *pJogador) : pJogador(pJogador)
{
}

ObservadorJ::~ObservadorJ()
{
}

void ObservadorJ::teclaPressionada(const sf::Keyboard::Key tecla)
{
    switch (tecla)
    {
    case (sf::Keyboard::A):
    {
        pJogador->andar(true);
    }
    break;
    case (sf::Keyboard::D):
    {
        pJogador->andar(false);
    }
    break;
    case (sf::Keyboard::W):
    {
        pJogador->pular();
    }
    break;
    case (sf::Keyboard::S):
    {
        pJogador->atacar(true);
    }
    break;
        ;
    }
}

void ObservadorJ::teclaSolta(const sf::Keyboard::Key tecla)
{
    switch (tecla)
    {
    case (sf::Keyboard::A):
    {
        pJogador->parar();
    }
    break;
    case (sf::Keyboard::D):
    {
        pJogador->parar();
    }
    break;
    }
}