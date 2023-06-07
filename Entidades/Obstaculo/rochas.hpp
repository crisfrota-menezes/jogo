#pragma once

#include "obstaculo.hpp"
#include "../Personagens/Personagem.hpp"

#define CAMINHO_Rochas "C:/Users/crisn/Desktop/projetoTecProg/Midia/Rochas.png"

#define ESCALA_X 1
#define ESCALA_Y 1

#define TAMANHO_Rochas_X 100.0f
#define TAMANHO_Rochas_Y 100.0f

namespace Escape_the_room
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Rochas : public Obstaculo
            {
            private:
                int dano = 10;
            public:
                Rochas(const sf::Vector2f pos);
                ~Rochas();
                void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                //void colisaoObstaculo(sf::Vector2f ds, Personagem *ent);
            };
        }
        using namespace Obstaculos;
    }
    using namespace Entidades;
}
using namespace Escape_the_room;