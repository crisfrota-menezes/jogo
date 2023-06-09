#pragma once

#include "elemento.hpp"

namespace SpaceHunt
{
    namespace Listas
    {
        template <class TL>
        class Lista
        {
        private:
            Elemento<TL> *inicio;
            Elemento<TL> *ultimo;
            unsigned int tam;

        public:
            Lista();
            ~Lista();
            void inserir(TL *elemento);
            void remover(int pos);
            void remover(TL *elemento);
            TL *operator[](int pos);
            void limpar();
            int getTam();
            bool vazia();
        };

        template <class TL>
        Lista<TL>::Lista() : inicio(nullptr),
                             ultimo(nullptr),
                             tam(0)
        {
        }

        template <class TL>
        Lista<TL>::~Lista()
        {
            limpar();
        }

        template <class TL>
        void Lista<TL>::inserir(TL *elemento)
        {
            if (elemento == nullptr)
            {
                std::cout << "ERROR::Lista elemento eh nullptr" << std::endl;
                exit(1);
            }
            Elemento<TL> *novo = new Elemento<TL>();
            novo->setElemento(elemento);
            if (novo == nullptr)
            {
                std::cout << "ERROR::Lista aux eh nullptr" << std::endl;
                exit(1);
            }
            novo->setElemento(elemento);
            if (this->inicio == nullptr)
            {
                this->inicio = novo;
                this->ultimo = novo;
            }
            else
            {
                this->ultimo->setProximo(novo);
                this->ultimo = novo;
            }
            this->tam++;
        }

        template <class TL>
        void Lista<TL>::remover(int pos)
        {
            TL *elemento = operator[](pos);
            return remover(elemento);
        }

        template <class TL>
        void Lista<TL>::remover(TL *elemento)
        {
            if (elemento == nullptr)
            {
                std::cout << "ERROR::Lista elemento eh nullptr" << std::endl;
                exit(1);
            }
            Elemento<TL> *aux = inicio;
            Elemento<TL> *aux2 = nullptr;
            while (aux != nullptr && aux->getElemento() != elemento)
            {
                aux2 = aux;
                aux = aux->getProximo();
            }
            if (aux->getElemento() == elemento)
            {
                if (aux == inicio)
                {
                    inicio = aux->getProximo();
                }
                else if (aux == ultimo)
                {
                    ultimo = aux2;
                }
                else
                {
                    aux2->setProximo(aux->getProximo());
                }
                tam--;
                delete (aux);
                aux = nullptr;
                aux2 = nullptr;
            }
        }

        template <class TL>
        TL *Lista<TL>::operator[](int pos)
        {
            if (pos >= (int)tam || pos < 0)
            {
                std::cout << "ERROR::Lista pos eh maior que o tamanho da lista" << std::endl;
                exit(1);
            }
            Elemento<TL> *aux = inicio;
            for (int i = 0; i < pos; i++)
            {
                aux = aux->getProximo();
            }
            return aux->getElemento();
        }

        template <class TL>
        void Lista<TL>::limpar()
        {
            Elemento<TL> *aux = inicio;
            Elemento<TL> *aux2 = nullptr;
            while (aux != nullptr)
            {
                aux2 = aux;
                aux = aux->getProximo();
                delete (aux2);
                aux2 = nullptr;
            }
            inicio = nullptr;
            ultimo = nullptr;
            tam = 0;
        }

        template <class TL>
        int Lista<TL>::getTam()
        {
            return (int)tam;
        }

        template <class TL>
        bool Lista<TL>::vazia()
        {
            return tam == 0;
        }
    }
    using namespace Listas;
}
using namespace SpaceHunt;