#pragma once

#include "elemento.hpp"

namespace Escape_the_room
{
    namespace Listas
    {
        template <class TL>
        class Lista
        {
        private:
            Elemento<TL> *inicio;
            Elemento<TL> *fim;
            unsigned int tam;

        public:
            Lista();
            ~Lista();
            void inserir(TL *elemento);
            void remover(int pos);
            void remover(TL *elemento);
            TL *operator[](int pos);
            int getTam();
        };

        template <class TL>
        Lista<TL>::Lista() : inicio(nullptr),
                             fim(nullptr),
                             tam(0)
        {
        }

        template <class TL>
        Lista<TL>::~Lista()
        {
            Elemento<TL> *aux = this->inicio;
            while (aux != nullptr)
            {
                Elemento<TL> *aux2 = aux->getProximo();
                delete aux;
                aux = aux2;
            }
        }

        template <class TL>
        void Lista<TL>::inserir(TL *elemento)
        {
            Elemento<TL> *novo = new Elemento<TL>();
            novo->setElemento(elemento);
            if (this->inicio == nullptr)
            {
                this->inicio = novo;
                this->fim = novo;
            }
            else
            {
                this->fim->setProximo(novo);
                this->fim = novo;
            }
            this->tam++;
        }

        template <class TL>
        void Lista<TL>::remover(int pos)
        {
            if (pos >= 0 && pos < this->tam)
            {
                Elemento<TL> *aux = this->inicio;
                if (pos == 0)
                {
                    this->inicio = aux->getProximo();
                    delete aux;
                }
                else
                {
                    for (int i = 0; i < pos - 1; i++)
                    {
                        aux = aux->getProximo();
                    }
                    Elemento<TL> *aux2 = aux->getProximo();
                    aux->setProximo(aux2->getProximo());
                    delete aux2;
                }
                this->tam--;
            }
        }

        template <class TL>
        void Lista<TL>::remover(TL *elemento)
        {
            Elemento<TL> *aux = this->inicio;
            int pos = 0;
            while (aux != nullptr)
            {
                if (aux->getElemento() == elemento)
                {
                    this->remover(pos);
                    break;
                }
                aux = aux->getProximo();
                pos++;
            }
        }

        template <class TL>
        TL *Lista<TL>::operator[](int pos)
        {
            if (pos >= 0 && pos < this->tam)
            {
                Elemento<TL> *aux = this->inicio;
                for (int i = 0; i < pos; i++)
                {
                    aux = aux->getProximo();
                }
                return aux->getElemento();
            }
            return nullptr;
        }

        template <class TL>
        int Lista<TL>::getTam()
        {
            return this->tam;
        }
    }
    using namespace Listas;
}
using namespace Escape_the_room;