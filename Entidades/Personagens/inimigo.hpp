#pragma once

#include <cmath>
#include <time.h>
#include "jogador.hpp"
#include "Personagem.hpp"

#define VELOCIDADE_INIMIGO 60.0f

#define VISAO_INIMIGO_X 200.0f
#define VISAO_INIMIGO_Y 200.0f

namespace SpaceHunt
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

            public:
                Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador *jogador, IDs::IDs ID);
                ~Inimigo();
                void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                void atualizar();
                void atualizaMoveAleatorio();
                virtual int getVida() = 0;
            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;