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
            if (inicio)
            {
                Elemento<TL> *aux = inicio;
                Elemento<TL> *aux2 = nullptr;
                while (aux != nullptr)
                {
                    aux2 = aux->getProximo();
                    delete (aux->getElemento());
                    aux = nullptr;
                    aux = aux2;
                }
            }
            inicio = nullptr;
            fim = nullptr;
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
                else if (aux == fim)
                {
                    fim = aux2;
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
        int Lista<TL>::getTam()
        {
            return (int)tam;
        }
    }
    using namespace Listas;
}
using namespace Escape_the_room;