#pragma once

#include "../ente.hpp"

namespace Escape_the_room
{
    namespace Entidades
    {
        class Entidade : public Ente
        {
        protected:
            sf::RectangleShape corpo;
            sf::Vector2f pos;
            sf::Vector2f tam;

        public:
            Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
            ~Entidade();
            const sf::RectangleShape getCorpo();
            void setPos(const sf::Vector2f pos);
            const sf::Vector2f getPos();
            const sf::Vector2f getTam();
            virtual void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
            virtual void atualizar() = 0;
            virtual void parar() = 0;
            void desenhar();
        };
    }
    using namespace Entidades;
}
using namespace Escape_the_room;