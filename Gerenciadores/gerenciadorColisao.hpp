#pragma once

#include <SFML/Graphics.hpp>
#include "../Listas/listaEntidade.hpp"
#include "../Entidades/entidade.hpp"
#include <cmath>

namespace Escape_the_room
{
    namespace Gerenciadores
    {
        class GerenciadorColisao
        {
        private:
            ListaEntidades *listaPersonagem;
            ListaEntidades *listaObstaculo;

        public:
            GerenciadorColisao(ListaEntidades *listaPersonagem, ListaEntidades *listaObstaculo);
            ~GerenciadorColisao();
            const sf::Vector2f calculaColisao(Entidade *ent1, Entidade *ent2);
            void executar();
        };
    }
    using namespace Gerenciadores;
}
using namespace Escape_the_room;