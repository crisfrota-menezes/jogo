#pragma once

#include "../entidade.hpp"
#include "../Personagens/jogador.hpp"
#include "../Personagens/inimigo.hpp"

#include "../../Animacao/animacao.hpp"

namespace SpaceHunt
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Obstaculo : public Entidade
            {
            protected:
                sf::Texture textura;

            public:
                Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID, const char *caminhoTextura);
                ~Obstaculo();
                virtual void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
                void atualizar();
                virtual void colisaoObstaculo(sf::Vector2f ds, Personagem* pPersonagem);
            };
        }
        using namespace Obstaculos;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;