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
                Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam);
                ~Obstaculo();
                virtual void atualizar() = 0;
            };
        }
        using namespace Obstaculos;
    }
    using namespace Entidades;
}
using namespace Escape_the_room;