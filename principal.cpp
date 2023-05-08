#include "principal.hpp"

Background::Principal::Principal() : window(new sf::RenderWindow(sf::VideoMode(800, 600), "Game"))
{
    run();
}

Background::Principal::~Principal()
{
}

void Background::Principal::run()
{
    sf::RectangleShape jogador(sf::Vector2f(50, 50));
    jogador.setFillColor(sf::Color::Green);
    jogador.setPosition(370, 250);

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();
        window->draw(jogador);
        window->display();
    }
}
