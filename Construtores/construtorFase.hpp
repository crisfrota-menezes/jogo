#pragma once

//personagens
#include "../Entidades/Personagens/jogador.hpp"
#include "../Entidades/Personagens/uraniano.hpp"
#include "../Entidades/Personagens/venusiano.hpp"
#include "../Entidades/entidade.hpp"

//obstaculos
#include "../Entidades/Obstaculo/rochas.hpp"
#include "../Entidades/Obstaculo/plataforma.hpp"
#include "../Entidades/Obstaculo/arvore.hpp"
//gerenciadores
#include "../Gerenciadores/gerenciadorEvento.hpp"

namespace SpaceHunt {

    namespace Construtores {

        class ConstrutorFase 
        {
        public:
            ConstrutorFase();
            ~ConstrutorFase();
            Entidade* criarVenusiano(const sf::Vector2f pos);
            Entidade* criarUraniano(const sf::Vector2f pos);
            Entidade* criarJogador(const sf::Vector2f pos);
            Entidade* criarPlataforma(const sf::Vector2f pos);
            Entidade* criarRocha(const sf::Vector2f pos);
            Entidade* criarArvore(const sf::Vector2f pos);
        };
    } 
    using namespace Construtores;
}
using namespace SpaceHunt;