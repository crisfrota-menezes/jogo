#include "observadorMP.hpp"
#include "../Menus/menuPrincipal.hpp"
#include "../Gerenciadores/gerenciadorEstado.hpp"

GerenciadorEstado *ObservadorMenuPrincipal::gerenciadorEstado = GerenciadorEstado::getGerenciadorEstado();

ObservadorMenuPrincipal::ObservadorMenuPrincipal(Menus::MenuPrincipal *menuPrincipal) : Observador(), menuPrincipal(menuPrincipal)
{
}

ObservadorMenuPrincipal::~ObservadorMenuPrincipal()
{
    remove();
}

void ObservadorMenuPrincipal::teclaPressionada(const sf::Keyboard::Key tecla)
{
    switch (tecla)
    {
    case (sf::Keyboard::Enter):
    {
        switch (menuPrincipal->getBotaoSelecionado())
        {
        case (IDs::IDs::novo_jogo):
        {
            gerenciadorEstado->addEstado(IDs::IDs::jogar_Fase1);
        }
        break;
        }
        break;
    }
    }
}

void ObservadorMenuPrincipal::teclaSolta(const sf::Keyboard::Key tecla)
{
    switch (tecla)
    {
    case (sf::Keyboard::Up):
    {
        menuPrincipal->selecionaUp();
    }
    break;
    case (sf::Keyboard::Down):
    {
        menuPrincipal->selecionaDown();
    }
    break;
    }
}