#include "principal.hpp"

Jogo::Jogo() : window(new sf::RenderWindow(sf::VideoMode(1920, 1080), "Game")), jogador(sf::Vector2f(100.0f, 200.0f), sf::Vector2f(50.0f, 50.0f))
{
    image = new sf::Texture();
    bg = new sf::Sprite();
    run();
}

Jogo::~Jogo()
{
    delete image;
    delete bg;
}

void Jogo::run()
{
    // image->loadFromFile("./Midia/background.png");
    // bg->setTexture(*image);
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        window->clear();
        // window->draw(*bg);
        jogador.move();
        window->draw(jogador.getCorpo());
        window->display();
    }
}