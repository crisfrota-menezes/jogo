#pragma once

//Classe Base
#include "../ente.hpp"

//fundo
#include "../Parallax/fundo.hpp"

//Gerenciadores
#include "../Gerenciadores/GerenciadorColisao.hpp"

//Listas
#include "../Listas/listaEntidade.hpp"

//Construtores
#include "../Construtores/construtorEntidade.hpp"

#include <fstream>

namespace SpaceHunt {

    namespace Fases {

        class Fase : public Ente {
        protected:
            ConstrutorEntidade construtorEnt;
            ListaEntidades listaPersonagens;
            ListaEntidades listaObstaculos;
            GerenciadorColisao* pColisao;
            Fundo fundo;
            
        public:
            Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo);
            ~Fase();
            virtual void criarMapa() = 0;
            void criarEntidade(char letra, const sf::Vector2i pos);
            void executar();
            void desenhar();
            virtual void criarFundo() = 0;
            Jogador* getJogador();
        };
    }
    using namespace Fases;
}
using namespace SpaceHunt;