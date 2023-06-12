#pragma once

#include "../ente.hpp"
#include "texto.hpp"

#define CAMINHO_FONTE "C:/Users/crisn/Desktop/SpaceHunt/Midia/PressStart2P-Regular.ttf"

namespace SpaceHunt
{
    namespace Menus
    {
        namespace Botoes
        {
            class Botao : public Ente
            {
            private:
                sf::RectangleShape caixa;
                Texto caixaTexto;
                bool selecionado;

            public:
                Botao(const std::string texto);
                ~Botao();
                void desenhar();
            };
        }
        using namespace Botoes;
    }
    using namespace Menus;
}
using namespace SpaceHunt;