#pragma once

#include "../Menus/menuPrincipal.hpp"
#include "estado.hpp"

namespace SpaceHunt
{
    namespace Estados
    {
        class EstadoMenuPrincipal : public Estado
        {
        private:
            MenuPrincipal menuPrincipal;

        public:
            EstadoMenuPrincipal(const IDs::IDs ID = IDs::IDs::estadoMenuPrincipal);
            ~EstadoMenuPrincipal();
            void executar();
        };
    }

}