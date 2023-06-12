#pragma once

#include "menu.hpp"

#define CAMINHO_TEXTURA_MP "C:/Users/crisn/Desktop/SpaceHunt/Midia/background.jpg"
#define TAM_BOTAO_X 200
#define TAM_BOTAO_Y 50

namespace SpaceHunt
{
    namespace Menus
    {
        class MenuPrincipal : public Menu
        {
        protected:
            bool sair;

            void criarFundo();
            void criarBotoes();

        public:
            MenuPrincipal();
            ~MenuPrincipal();
            void setSair(const bool sair = true);
            const bool getSair() const;
            void executar();
        };
    }
    using namespace Menus;
}
using namespace SpaceHunt;