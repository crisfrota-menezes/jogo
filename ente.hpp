#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

#include "Entidades/IDs.hpp"
#include "Gerenciadores/gerenciadorGrafico.hpp"

namespace Escape_the_room
{
    class Ente
    {
    protected:
        GerenciadorGrafico *pGrafico;
        const IDs::IDs ID;

    public:
        Ente(const IDs::IDs ID);
        ~Ente();
        const IDs::IDs getID() const;
        virtual void desenhar() = 0;
    };
}
using namespace Escape_the_room;