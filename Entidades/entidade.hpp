#pragma once

#include "../ente.hpp"

namespace SpaceHunt
{
    namespace Entidades
    {
        class Entidade : public Ente
        {
        protected:
            sf::RectangleShape corpo;
            sf::Vector2f pos;
            sf::Vector2f tam;
            int dano;
            bool hit;
            int danoTomado;

        public:
            int vida;
            Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
            ~Entidade();
            const sf::RectangleShape getCorpo();
            void setPos(sf::Vector2f pos);
            sf::Vector2f getPos();
            const sf::Vector2f getTam();
            virtual void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
            virtual void atualizar() = 0;
            void desenhar();
            int getDano();
        };
    }
    using namespace Entidades;
}
using namespace SpaceHunt;