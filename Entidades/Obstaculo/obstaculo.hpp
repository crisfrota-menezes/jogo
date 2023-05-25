#pragma once

#include <SFML/Graphics.hpp>
#include "../entidade.hpp"

namespace Escape_the_room
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
                Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs id);
                ~Obstaculo();
                virtual void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
                virtual void atualizar() = 0;
            };
        }
        using namespace Obstaculos;
    }
    using namespace Entidades;
}
using namespace Escape_the_room;