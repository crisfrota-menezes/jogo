#pragma once

#include "../Entidades/entidade.hpp"
#include "lista.hpp"

namespace SpaceHunt
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
            bool vazia();
            void executar();
            void limpar();
        };
    }
    using namespace Listas;
}
using namespace SpaceHunt;