#pragma once

#include "../entidade.hpp"
#include "../../Animacao/animacao.hpp"

#define GRAVIDADE 1.0f

namespace SpaceHunt
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
                bool atacando;
                sf::Clock relogio;
                float dt;
                Animacao animacao;

            public:
                Personagem(const sf::Vector2f pos, const sf::Vector2f tam, const float vel, const IDs::IDs ID);
                virtual ~Personagem();
                void setVelFinal(sf::Vector2f velFinal);
                const sf::Vector2f getVelFinal() const;
                void andar(const bool paraEsquerda);
                void parar();
                void atacar(const bool atacando);
                void atualizarPos();
                virtual void animar();
                virtual void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
                virtual void atualizar() = 0;
                bool getNoChao() const;
                void setNoChao(bool noChao);
                bool getAtacando();
            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;