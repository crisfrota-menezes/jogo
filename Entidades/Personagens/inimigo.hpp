#pragma once

#include <cmath>
#include <time.h>
#include "jogador.hpp"
#include "Personagem.hpp"

#define VELOCIDADE_INIMIGO 60.0f

#define VISAO_INIMIGO_X 200.0f
#define VISAO_INIMIGO_Y 200.0f

namespace Escape_the_room
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Inimigo : public Personagem
            {
            private:
                Jogador *jogador;
                float dtAux;
                int moveAleatorio;
                void moveInimigo();
                void atualizaMoveAleatorio();

            public:
                Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador *jogador, IDs::IDs ID);
                ~Inimigo();
                void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                void atualizar();
            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace Escape_the_room;