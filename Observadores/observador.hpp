#pragma once

#include "SFML/Graphics.hpp"

namespace SpaceHunt
{
    namespace Gerenciadores
    {
        class GerenciadorEvento;
    }
    namespace Observadores
    {
        class Observador
        {
        private:
            static Gerenciadores::GerenciadorEvento *pEvento;

        public:
            Observador();
            ~Observador();
            virtual void teclaPressionada(const sf::Keyboard::Key tecla) = 0;
            virtual void teclaSolta(const sf::Keyboard::Key tecla) = 0;
        };
    }
    using namespace Observadores;
}
using namespace SpaceHunt;