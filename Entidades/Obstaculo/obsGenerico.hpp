#pragma once

#include "obstaculo.hpp"

namespace Escape_the_room
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class ObsGenerico : public Obstaculo
            {
            public:
                ObsGenerico(const sf::Vector2f pos, const sf::Vector2f tam);
                ~ObsGenerico();
                void atualizar();
            };
        }
        using namespace Obstaculos;
    }
    using namespace Entidades;
}
using namespace Escape_the_room;