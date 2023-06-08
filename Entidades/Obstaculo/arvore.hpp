#pragma once

#include "obstaculo.hpp"

#define CAMINHO_TEXTURA_Arvore "C:/Users/crisn/Desktop/SpaceHunt/Midia/arvore.png"
#define ESCALA_Arvore_X 1
#define ESCALA_Arvore_Y 1
#define TAMANHO_Arvore_X 200.0f
#define TAMANHO_Arvore_Y 200.0f

namespace SpaceHunt
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Arvore : public Obstaculo
            {
            private:
                const float flexibilidade;

            public:
                Arvore(sf::Vector2f pos);
                ~Arvore();
                void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
                void colisaoObstaculo(sf::Vector2f ds, Personagem* pPersonagem);
                //void setVida(bool vida);
            };

        }
        using namespace Obstaculos;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;