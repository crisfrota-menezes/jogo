#pragma once

#include <SFML/Graphics.hpp>
#include "../Listas/listaEntidade.hpp"
#include <cmath>

namespace SpaceHunt
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
using namespace SpaceHunt;