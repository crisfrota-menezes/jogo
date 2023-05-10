#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Menu
{
    int pos;
    bool pressed, select;

    sf::RenderWindow *window;
    sf::RectangleShape *winclose;
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
    void loop_events();
    void draw();

public:
    Menu();
    ~Menu();
    void run();
};