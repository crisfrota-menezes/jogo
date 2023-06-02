#pragma once

#include <SFML/Graphics.hpp>
#include "../Gerenciadores/gerenciadorGrafico.hpp"
#include <iostream>
using namespace std;
#include "IDs.hpp"

namespace Escape_the_room
{
    namespace Entidades
    {
        class Entidade
        {
        protected:
            sf::RectangleShape corpo;
            sf::Vector2f pos;
            sf::Vector2f tam;
            const IDs::IDs ID;

        public:
            Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
            ~Entidade();
            const sf::RectangleShape getCorpo();
            void setPos(const sf::Vector2f pos);
            const sf::Vector2f getPos();
            const sf::Vector2f getTam();
            //sf::Vector2f posicaoAleatoria(float larguraJanela, float alturaJanela);
            const IDs::IDs getID() const;
            virtual void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
            virtual void atualizar() = 0;
        };
    }
    using namespace Entidades;
}
using namespace Escape_the_room;