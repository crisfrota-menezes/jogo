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
            int vida;
            int dano;
            bool hit;

        public:
            Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
            ~Entidade();
            const sf::RectangleShape getCorpo();
            void setPos(const sf::Vector2f pos);
            sf::Vector2f getPos();
            const sf::Vector2f getTam();
            virtual void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
            virtual void atualizar() = 0;
            // virtual void setVida(bool vida) = 0;
            void desenhar();
            void setVida(int vida);
            int getVida() const;
            void setDano(int dano);
            int getDano() const;
        };
    }
    using namespace Entidades;
}
using namespace SpaceHunt;