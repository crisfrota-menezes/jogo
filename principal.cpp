#include "principal.hpp"

Principal::Principal() : window(new sf::RenderWindow(sf::VideoMode(800, 600), "Game")), jogador(sf::Vector2f(100.0f, 200.0f), sf::Vector2f(50.0f, 50.0f))
{
    run();
}

Principal::~Principal()
{
}

void Principal::run()
{
    Menu *menu = new Menu();
    menu->run();
    delete menu;
    menu = nullptr;
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();
        jogador.move();
        window->draw(jogador.getCorpo());
        window->display();
    }
}
