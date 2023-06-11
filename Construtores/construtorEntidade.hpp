#pragma once

// personagens
#include "../Entidades/Personagens/jogador.hpp"
#include "../Entidades/Personagens/uraniano.hpp"
#include "../Entidades/Personagens/venusiano.hpp"

// obstaculos
#include "../Entidades/Obstaculo/rochas.hpp"
#include "../Entidades/Obstaculo/plataforma.hpp"

namespace SpaceHunt
{
    namespace Construtores
    {
        class ConstrutorEntidade
        {
        private:
            Jogador *pJogador;
            void verificaJogador();

        public:
            ConstrutorEntidade(Jogador *pJogador);
            ConstrutorEntidade();
            ~ConstrutorEntidade();
            Entidade *criarVenusiano(const sf::Vector2f pos);
            Entidade *criarUraniano(const sf::Vector2f pos);
            Entidade *criarJogador(const sf::Vector2f pos);
            Entidade *criarPlataforma(const sf::Vector2f pos);
            Entidade *criarRocha(const sf::Vector2f pos);
        };
    }
    using namespace Construtores;
}
using namespace SpaceHunt;