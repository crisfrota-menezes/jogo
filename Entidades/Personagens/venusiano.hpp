#pragma once

#include "inimigo.hpp"

#define TAMANHO_Venusiano_X 60.0f
#define TAMANHO_Venusiano_Y 110.0f

namespace SpaceHunt
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Venusiano : public Inimigo
            {
            private:
                void inicializa();

            public:
                Venusiano(const sf::Vector2f pos, Jogador *jogador);
                ~Venusiano();
                //void disparar();
                //void setVida(bool vida);
                
            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace SpaceHunt;