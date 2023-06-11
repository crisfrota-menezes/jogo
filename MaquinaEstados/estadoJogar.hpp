#pragma once

#include "estado.hpp"

// Gerenciador
#include "../Gerenciadores/gerenciadorGrafico.hpp"

// Fases
#include "../Fases/fase.hpp"
#include "../Fases/fase1.hpp"
#include "../Fases/fase2.hpp"

// Personagens
#include "../Entidades/Personagens/jogador.hpp"

// Construtores
#include "../Construtores/construtorEstado.hpp"

namespace SpaceHunt
{
    namespace Estados
    {
        class EstadoJogar : public Estado
        {
        private:
            Fase *fase;

        public:
            EstadoJogar(const IDs::IDs ID, Fase *fase);
            ~EstadoJogar();
            void executar();
            Jogador *getJogador();
        };
    }
    using namespace Estados;
}
using namespace SpaceHunt;