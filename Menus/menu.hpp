#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "ranking.hpp"
#include "opcoes.hpp"

namespace SpaceHunt
{
    class Menu
    {
        int pos;
        bool pressed, select;

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

    protected:
        void set_values();
        bool loop_events();
        void draw();

    public:
        Menu();
        ~Menu();
        bool run();
    };
}
using namespace SpaceHunt;