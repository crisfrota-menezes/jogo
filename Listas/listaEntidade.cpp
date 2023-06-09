#include "listaEntidade.hpp"

ListaEntidades::ListaEntidades() : lista()
{
}

ListaEntidades::~ListaEntidades()
{
}

void ListaEntidades::inserir(Entidade *ent)
{
    lista.inserir(ent);
}

void ListaEntidades::remover(int pos)
{
    lista.remover(pos);
}

void ListaEntidades::remover(Entidade *ent)
{
    lista.remover(ent);
}

Entidade *ListaEntidades::operator[](int pos)
{
    return lista.operator[](pos);
}

int ListaEntidades::getTam()
{
    return lista.getTam();
}

bool ListaEntidades::vazia()
{
    return lista.vazia();
}

void ListaEntidades::executar()
{
    int tam = lista.getTam();
    Entidade *aux = nullptr;
    for (int i = 0; i < tam; i++)
    {
        aux = lista.operator[](i);
        aux->atualizar();
    }
}

void ListaEntidades::limpar()
{
    lista.limpar();
}