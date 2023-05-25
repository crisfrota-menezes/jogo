#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include "../entidade.hpp"

namespace Escape_the_room
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Personagem : public Entidade
            {
            protected:
                sf::Vector2f vel;
                // bool podeMover;
                // bool paraEsquerda;

            public:
                Personagem(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs id);
                ~Personagem();
                const sf::Vector2f getVel();
                // void andar(const bool esquerda);
                // void parar();
                virtual void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
                virtual void atualizar() = 0;
            };
        }
        using namespace Personagens;
    }
    using namespace Entidades;
}
using namespace Escape_the_room;