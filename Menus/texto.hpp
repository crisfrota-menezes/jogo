#pragma once

#include <SFML/Graphics.hpp>
//#include <string>

namespace SpaceHunt
{
    namespace Menus
    {
        namespace Botoes
        {
            class Texto
            {
            private:
                sf::Text texto;
                sf::Font fonte;

                void inicializa();

            public:
                Texto(sf::Font fonte, const std::string texto = "");
                ~Texto();
                void setString(const std::string texto);
                const std::string getString();
                sf::Text getTexto();
            };
        }
        using namespace Botoes;
    }
    using namespace Menus;
}
using namespace SpaceHunt;