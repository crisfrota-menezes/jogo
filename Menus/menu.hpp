#pragma once

#include "../ente.hpp"
#include "botao.hpp"

namespace SpaceHunt
{
    namespace Menus
    {
        class Menu : public Ente
        {
        private:
            sf::RectangleShape fundo;

        public:
            Menu(const IDs::IDs ID);
            ~Menu();
        };
    }
    using namespace Menus;
}
using namespace SpaceHunt;