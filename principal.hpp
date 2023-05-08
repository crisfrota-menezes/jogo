#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

namespace Background
{
    class Principal
    {
    private:
        sf::RenderWindow *window;

    public:
        Principal();
        ~Principal();
        void run();
    };
}