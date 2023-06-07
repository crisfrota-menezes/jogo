#pragma once

#include "Personagem.hpp"
#include "../../Animacao/Animacao.hpp"

#define VELOCIDADE_JOGADOR 200.0f
#define TAMANHO_PULO 0.1f
#define TAMANHO_JOGADOR_X 50.0f
#define TAMANHO_JOGADOR_Y 90.0f

namespace SpaceHunt
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
                Jogador(const sf::Vector2f pos);
                ~Jogador();
                void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                void atualizar();
                void pular();
                void podePular();
                void animar();
            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;