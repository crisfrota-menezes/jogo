#pragma once

#include "observador.hpp"
#include "../Menus/botao.hpp"

namespace SpaceHunt
{
    namespace Menus
    {
        class MenuPrincipal;
    }
    namespace Gerenciadores
    {
        class GerenciadorEstado;
    }
    namespace Observadores
    {

        class ObservadorMenuPrincipal : public Observador
        {
        private:
            Menus::MenuPrincipal *menuPrincipal;
            static GerenciadorEstado *gerenciadorEstado;
        public:
            ObservadorMenuPrincipal(Menus::MenuPrincipal *menuPrincipal);
            ~ObservadorMenuPrincipal();
            void teclaPressionada(const sf::Keyboard::Key tecla);
            void teclaSolta(const sf::Keyboard::Key tecla);
        };
    }
    using namespace Observadores;
}
using namespace SpaceHunt;