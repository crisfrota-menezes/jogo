#pragma once

#include "obstaculo.hpp"

#define CAMINHO_Rochas "C:/Users/crisn/Desktop/SpaceHunt/Midia/Rochas.png"

#define ESCALA_X 1
#define ESCALA_Y 1

#define TAMANHO_Rochas_X 100.0f
#define TAMANHO_Rochas_Y 100.0f

namespace SpaceHunt
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Rochas : public Obstaculo
            {
            public:
                Rochas(sf::Vector2f pos, sf::Vector2f tam);
                ~Rochas();
                void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
            };
        }
        using namespace Obstaculos;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;