#pragma once

#include "Personagem.hpp"

#define VELOCIDADE_JOGADOR 150.0f

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

            public:
                Jogador(const sf::Vector2f pos, const sf::Vector2f tam);
                ~Jogador();
                void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                void atualizar();

            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace Escape_the_room;