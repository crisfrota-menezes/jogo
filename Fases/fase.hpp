#pragma once

//Classe Base
#include "../ente.hpp"

//Personagens
#include "../Entidades/Personagens/jogador.hpp"
#include "../Entidades/Personagens/uraniano.hpp"
#include "../Entidades/Personagens/verme.hpp"
#include "../Entidades/Personagens/alien3.hpp"

//Obstaculos
#include "../Entidades/Obstaculo/arvore.hpp"
#include "../Entidades/Obstaculo/rochas.hpp"
#include "../Entidades/Obstaculo/plataforma.hpp"

//Gerenciadores
#include "../Gerenciadores/GerenciadorColisao.hpp"
#include "../Gerenciadores/GerenciadorEvento.hpp"

//Listas
#include "../Listas/listaEntidade.hpp"

#include <fstream>

namespace SpaceHunt {

    namespace Fases {

        class Fase : public Ente {
        protected:
            ListaEntidades listaPersonagens;
            ListaEntidades listaObstaculos;
            GerenciadorColisao* pColisao;
            
        public:
            Fase(const IDs::IDs ID_Fase);
            ~Fase();
            void criaUraniano(const sf::Vector2f pos);
            void criaVerme(const sf::Vector2f pos);
            void criaAlien3(const sf::Vector2f pos);
            void criarJogador(const sf::Vector2f pos);
            void criarPlataforma(const sf::Vector2f pos);
            void criarArvore(const sf::Vector2f pos);
            void criarRochas(const sf::Vector2f pos);
            virtual void criarMapa() = 0;
            void criarEntidade(char letra, const sf::Vector2i pos);
            void executar();
            void desenhar();
        };
    }
    using namespace Fases;
}
using namespace SpaceHunt;