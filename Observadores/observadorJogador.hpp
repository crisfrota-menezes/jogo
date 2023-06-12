#pragma once

#include "observador.hpp"
#include "../Entidades/Personagens/jogador.hpp"

namespace SpaceHunt
{
    namespace Observadores
    {
        class ObservadorJ : public Observador
        {
        private:
            Jogador *pJogador;

        public:
            ObservadorJ(Jogador *pJogador);
            ~ObservadorJ();
            void teclaPressionada(const sf::Keyboard::Key tecla);
            void teclaSolta(const sf::Keyboard::Key tecla);
        };

    }

}