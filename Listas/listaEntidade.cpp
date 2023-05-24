#include "listaEntidade.hpp"

ListaEntidades::ListaEntidades()
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

void ListaEntidades::executar(sf::RenderWindow *window)
{
    int tam = lista.getTam();
    Entidade *aux = nullptr;
    for (int i = 0; i < tam; i++)
    {
        aux = lista.operator[](i);
        aux->atualizar();
        window->draw(aux->getCorpo());
    }
}