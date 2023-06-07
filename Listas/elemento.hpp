#pragma once

#include <iostream>

namespace SpaceHunt
{
    namespace Listas
    {
        template <class TE>
        class Elemento
        {
        private:
            TE *elemento;
            Elemento<TE> *proximo;

        public:
            Elemento();
            ~Elemento();
            TE *getElemento();
            Elemento<TE> *getProximo();
            void setProximo(Elemento<TE> *proximo);
            void setElemento(TE *elemento);
        };

        template <class TE>
        Elemento<TE>::Elemento() : proximo(nullptr),
                                   elemento(nullptr)
        {
        }

        template <class TE>
        Elemento<TE>::~Elemento()
        {
            delete this->elemento;
            this->proximo = nullptr;
        }

        template <class TE>
        TE *Elemento<TE>::getElemento()
        {
            return elemento;
        }

        template <class TE>
        Elemento<TE> *Elemento<TE>::getProximo()
        {
            return proximo;
        }

        template <class TE>
        void Elemento<TE>::setProximo(Elemento<TE> *proximo)
        {
            this->proximo = proximo;
        }

        template <class TE>
        void Elemento<TE>::setElemento(TE *elemento)
        {
            this->elemento = elemento;
        }
    }
    using namespace Listas;
}
using namespace SpaceHunt;