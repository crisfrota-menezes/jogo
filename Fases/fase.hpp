#pragma once

//Classe Base
#include "../ente.hpp"

#include "../Parallax/fundo.hpp"

#include "../Construtores/construtorFase.hpp"

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
            Construtores::ConstrutorFase* construtor;
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
            bool concluida();
            virtual void criarFundo() = 0;
        };
    }
    using namespace Fases;
}
using namespace SpaceHunt;