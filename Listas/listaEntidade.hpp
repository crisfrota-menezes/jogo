#pragma once

#include "../Entidades/entidade.hpp"
#include "lista.hpp"

namespace Escape_the_room
{
    namespace Listas
    {
        class ListaEntidades
        {
        private:
            Lista<Entidade> lista;

        public:
            ListaEntidades();
            ~ListaEntidades();
            void inserir(Entidade *ent);
            void remover(int pos);
            void remover(Entidade *ent);
            Entidade *operator[](int pos);
            int getTam();
            void executar(sf::RenderWindow *window);
            void limpar();
        };
    }
    using namespace Listas;
}
using namespace Escape_the_room;