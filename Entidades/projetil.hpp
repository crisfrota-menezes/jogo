#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "entidade.hpp"

namespace SpaceHunt
{
    namespace Entidades
    {
        namespace Personagens
        {
            // Forward declaration of classes
            class Jogador;
            class Venusiano;

            // Projectile class
            class Projetil : public Entidade
            {
            public:
                Projetil(const sf::Vector2f pos, Jogador *jogador);
                void atualizar();
                void colisao(Entidade *outraEnt, sf::Vector2f ds);

            private:
                int dano;
                float velocidade;
                Jogador *jogador;
            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;