#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

namespace SpaceHunt
{
    class Ranking
    {
    private:
        sf::RenderWindow window;
        sf::Font font;
        sf::Texture image;
        sf::Sprite bg;
        sf::Vector2i mousePos;
        sf::Vector2f mouseCoord;
        std::vector<const char *> options;
        std::vector<sf::Text> textos;
        std::vector<sf::Vector2f> coords;
        std::vector<std::size_t> sizes;

    public:
        Ranking();
        ~Ranking();

        void run();
        void draw();
    };
}
using namespace SpaceHunt;