#pragma once

#include "lista.hpp"
#include "../Observadores/observador.hpp"
#include "SFML/Graphics.hpp"

namespace SpaceHunt
{
    namespace Listas
    {
        class ListaObservador
        {
        private:
            Lista<Observador> listaObs;
            
        public:
            ListaObservador();
            ~ListaObservador();
            void addObservador(Observador *observador);
            void removerObservador(Observador *observador);
            void removerObservador(int pos);
            int getTam();
            Observador *operator[](int pos);
            void notificarTeclaPress(const sf::Keyboard::Key tecla);
            void notificarTeclaSolta(const sf::Keyboard::Key tecla);
        };
    }
    using namespace Listas;
}
using namespace SpaceHunt;