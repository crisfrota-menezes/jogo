#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include "Personagem.hpp"

namespace Escape_the_room
{
    namespace Entidades
    {
        namespace Personagem
        {
            class Jogador : public Personagem
            {
            private:
                int pontos;
                void inicializa();

            public:
                Jogador(const sf::Vector2f pos, const sf::Vector2f tam);
                Jogador(const sf::RectangleShape corpo);
                Jogador();
                ~Jogador();
                void move();
            };
        }
        using namespace Personagem;
    }
    using namespace Entidades;
}
using namespace Escape_the_room;