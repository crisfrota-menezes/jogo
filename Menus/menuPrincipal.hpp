#pragma once

#include "../Gerenciadores/gerenciadorGrafico.hpp"

namespace SpaceHunt
{
    namespace Menus
    {
        class MenuPrincipal
        {
        private:
            GerenciadorGrafico *gg;
            Jogo *jogo;
            sf::RenderWindow *window;
            sf::Font *font;
            sf::Texture *image;
            sf::Sprite *bg;
            sf::Vector2i mousePos;
            sf::Vector2f mouseCoord;
            std::vector<const char *> options;
            std::vector<sf::Text> textos;
            std::vector<sf::Vector2f> coords;
            std::vector<std::size_t> sizes;
            int pos;
            bool pressed, select;

            void set_values();
            bool loop_events();
            void draw();

        public:
            MenuPrincipal(GerenciadorGrafico *pGrafico, Jogo *jogo);
            ~MenuPrincipal();
            bool run();
        };
    }
    using namespace Menus;
}
using namespace SpaceHunt;