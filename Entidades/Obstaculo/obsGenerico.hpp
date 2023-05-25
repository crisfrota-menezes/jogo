#pragma once

#include "obstaculo.hpp"
#include "../Personagens/jogador.hpp"
#define ESCALA_X 1.0f
#define ESCALA_Y 1.0f

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
                void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                // void colisaoObstaculo(sf::Vector2f ds, Personagem *pPersonagem);
                void atualizar();
            };
        }
        using namespace Obstaculos;
    }
    using namespace Entidades;
}
using namespace Escape_the_room;