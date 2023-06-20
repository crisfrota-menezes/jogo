#pragma once

#include "menu.hpp"
#include "texto.hpp"
#include "../Observadores/observadorMP.hpp"

#define CAMINHO_TEXTURA_MP "C:/Users/crisn/Desktop/SpaceHunt/Midia/background.jpg"
#define TAM_BOTAO_X 500.0f
#define TAM_BOTAO_Y 100.0f

namespace SpaceHunt
{
    namespace Menus
    {
        class MenuPrincipal : public Menu
        {
        private:
            bool sair;
            Observadores::ObservadorMenuPrincipal* obsMenuPrincipal;

            void criarFundo();
            void criarBotoes();

        public:
            MenuPrincipal();
            ~MenuPrincipal();
            void setSair(const bool sair = true);
            const bool getSair() const;
            void selecionaUp();
            void selecionaDown();
            const IDs::IDs getBotaoSelecionado() const;
            void executar();
        };
    }
    using namespace Menus;
}
using namespace SpaceHunt;