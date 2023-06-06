#pragma once

#include "../entidade.hpp"
#include "../../Gerenciadores/gerenciadorColisao.hpp"
#include "../../Animacao/animacao.hpp"
#include <cmath>

#define GRAVIDADE 0.5f

#define ALTURA_PULO 0.08f

namespace Escape_the_room
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Personagem : public Entidade
            {
            protected:
                sf::Vector2f velFinal;
                const float velMax;
                bool podeMover;
                bool paraEsquerda;
                sf::Clock relogio;
                float dt;
                bool noChao;
                //Animacao animacao;
                //virtual void animar() = 0;

            public:
                Personagem(const sf::Vector2f pos, const sf::Vector2f tam, const float vel, const IDs::IDs ID);
                ~Personagem();
                void setVelFinal(const sf::Vector2f velFinal);
                const sf::Vector2f getVelFinal();
                void andar(const bool paraEsquerda);
                void parar();
                void podePular();
                void pular();
                void atualizarPos();
                void verificaColisao();
                virtual void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
                virtual void atualizar() = 0;
            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace Escape_the_room;