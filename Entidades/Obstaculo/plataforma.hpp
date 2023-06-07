#pragma once

#include "obstaculo.hpp"
#include "../Personagens/Personagem.hpp"

#define CAMINHO_PLATAFORMA "C:/Users/crisn/Desktop/projetoTecProg/Midia/plataforma.png"

#define ESCALA_X 1
#define ESCALA_Y 1

#define TAMANHO_PLATAFORMA_X 300.0f
#define TAMANHO_PLATAFORMA_Y 128.0f

namespace Escape_the_room
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Plataforma : public Obstaculo
            {
            public:
                Plataforma(const sf::Vector2f pos);
                ~Plataforma();
                void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
            };
        }
        using namespace Obstaculos;
    }
    using namespace Entidades;
}
using namespace Escape_the_room;