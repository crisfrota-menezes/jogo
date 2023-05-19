#include "principal.hpp"

Jogo::Jogo() : window(new sf::RenderWindow(sf::VideoMode(1920, 1080), "Game"))
{
    Entidades::Personagem::Jogador *jogador = new Entidades::Personagem::Jogador(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(100.0f, 100.0f));
    Entidades::Personagem::Inimigo *inimigo = new Entidades::Personagem::Inimigo(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(100.0f, 100.0f), jogador);

    Entidades::Personagem::Personagem *p1 = static_cast<Entidades::Personagem::Personagem *>(jogador);
    Entidades::Personagem::Personagem *p2 = static_cast<Entidades::Personagem::Personagem *>(inimigo);

    personagens.push_back(p1);
    personagens.push_back(p2);

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
        /*for (int i = 0; i < personagens.size(); i++)
        {
            personagens.at(i)->move();
            window->draw(personagens.at(i)->getCorpo());
        }*/
        window->display();
    }
    personagens.clear();
}