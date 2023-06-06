#pragma once

#include "../entidade.hpp"
#include "../Personagens/jogador.hpp"
#include "../Personagens/inimigo.hpp"

#define CAMINHO_TEXTURA "C:/Users/crisn/Desktop/projetoTecProg/Midia/obstaculoGenerico.jpg"

namespace Escape_the_room
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            class Obstaculo : public Entidade
            {
            protected:
                sf::Texture textura;
                const char *caminho;

            public:
                Obstaculo(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
                ~Obstaculo();
                virtual void colisao(Entidade *outraEnt, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
                void atualizar();
            };
        }
        using namespace Obstaculos;
    }
    using namespace Entidades;
}
using namespace Escape_the_room;