#pragma once

#include "obstaculo.hpp"
#include "../Personagens/Personagem.hpp"

#define CAMINHO_TEXTURA "../Midia/obstaculoGenerico.jpg"

#define ESCALA_X 1.0f
#define ESCALA_Y 1.0f

namespace Escape_the_room
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Plataforma : public Obstaculo
            {
            public:
                Plataforma(const sf::Vector2f pos, const sf::Vector2f tam);
                ~Plataforma();
                void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                void colisaoObstaculo(sf::Vector2f ds, Personagem *pPersonagem);
            };
        }
        using namespace Obstaculos;
    }
    using namespace Entidades;
}
using namespace Escape_the_room;