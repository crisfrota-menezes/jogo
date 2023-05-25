#pragma once

#include <cmath>
#include <time.h>
#include "jogador.hpp"
#include "Personagem.hpp"

#define VELOCIDADE_INIMIGO_X 0.50f
#define VELOCIDADE_INIMIGO_Y 0.50f

#define VISAO_INIMIGO_X 300.0f
#define VISAO_INIMIGO_Y 300.0f

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
                sf::Clock relogio;
                int moveAleatorio;
                void inicializa();

            public:
                Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador *jogador);
                ~Inimigo();
                void perseguir(sf::Vector2f posJogador, sf::Vector2f posInimigo);
                void movimentoAleatorio();
                void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                void atualizar();
            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace Escape_the_room;