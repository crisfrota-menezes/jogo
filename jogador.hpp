#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include "Personagem.hpp"

namespace Entidades
{
    namespace Personagem
    {
        class Jogador : public Personagem
        {
        private:
            // sf::Vector2f vel;
            void inicializa();

        public:
            Jogador(const sf::Vector2f pos, const sf::Vector2f tam);
            Jogador(const sf::RectangleShape corpo);
            Jogador();
            ~Jogador();
            // const sf::RectangleShape getCorpo();
            void move();
        };
    }
    using namespace Personagem;
}
using namespace Entidades;