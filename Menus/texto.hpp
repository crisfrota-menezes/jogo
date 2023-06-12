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
                std::string info;
                sf::Vector2f tam;
                unsigned int tamTexto;

                int transparente;
                sf::Color corTexto;
                sf::Color corBorda;
                bool clareando;

                void inicializa();

            public:
                Texto(sf::Font fonte, const std::string texto = "");
                ~Texto();
                void setString(const std::string texto);
                const std::string getString();
                sf::Text getTexto();
                void setPosicao(const sf::Vector2f posicao);
                sf::Vector2f getTam();
                void mudarClareando();
                const bool getClareando() const;
                const int getTransparente() const;
                void setTransparente(int transparente);
                void resetar();
                void atualizar();
            };
        }
        using namespace Botoes;
    }
    using namespace Menus;
}
using namespace SpaceHunt;