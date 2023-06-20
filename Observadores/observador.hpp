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
        protected:
            static Gerenciadores::GerenciadorEvento *pEvento;

        private:
            bool ativa;

        public:
            Observador();
            ~Observador();
            void ativar();
            void desativar();
            const bool getAtiva() const;
            void remove();
            virtual void teclaPressionada(const sf::Keyboard::Key tecla) = 0;
            virtual void teclaSolta(const sf::Keyboard::Key tecla) = 0;
        };
    }
    using namespace Observadores;
}
using namespace SpaceHunt;