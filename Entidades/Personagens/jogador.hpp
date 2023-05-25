#pragma once

#include "Personagem.hpp"
#include <cmath>

#define VELOCIDADE_JOGADOR 150.0f
#define ALTURA_PULO 0.08f

namespace Escape_the_room
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Jogador : public Personagem
            {
            private:
                void inicializa();
                bool noChao;

            public:
                Jogador(const sf::Vector2f pos, const sf::Vector2f tam);
                ~Jogador();
                void colisao(Entidade *outraEnt, sf::Vector2f ds);
                void atualizar();
                void pular();
                void podePular();
            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace Escape_the_room;