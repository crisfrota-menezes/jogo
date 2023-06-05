#pragma once

#include "GerenciadorGrafico.hpp"
#include "../Entidades/Personagens/jogador.hpp"
#include "../Entidades/Personagens/Personagem.hpp"

namespace Escape_the_room
{
    namespace Gerenciadores
    {
        class GerenciadorEvento
        {
        private:
            GerenciadorGrafico *pGrafico;
            Personagem *pPersonagem;
            Jogador *pJogador;
            // padrão de projeto singleton
            static GerenciadorEvento *pEvento;
            GerenciadorEvento();

        public:
            ~GerenciadorEvento();
            static GerenciadorEvento *getGerenciadorEvento();
            void setJogador(Jogador *pJogador);
            void verificaTeclaPressionada(sf::Keyboard::Key tecla);
            void verificaTeclaSolta(sf::Keyboard::Key tecla);
            void executar();
        };
    }
    using namespace Gerenciadores;
}
using namespace Escape_the_room;