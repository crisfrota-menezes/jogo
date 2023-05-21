
#include "principal.hpp"

Jogo::Jogo() : window(new sf::RenderWindow(sf::VideoMode(1920, 1080), "Game"))
{
    Jogador *jogador = new Jogador(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(100.0f, 100.0f));
    Inimigo *inimigo = new Inimigo(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(100.0f, 100.0f), jogador);

    Personagem *p1 = static_cast<Entidades::Personagem::Personagem *>(jogador);
    Personagem *p2 = static_cast<Entidades::Personagem::Personagem *>(inimigo);

    personagens.push_back(jogador);
    personagens.push_back(inimigo);

    image = new sf::Texture();
    bg = new sf::Sprite();
}

Jogo::~Jogo()
{
    for (int i = 0; i < personagens.size(); i++)
    {
        delete personagens[i];
    }
    delete image;
    delete bg;
}

void Jogo::run()
{
    image->loadFromFile("./Midia/background.png");
    bg->setTexture(*image);
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        window->clear();
        window->draw(*bg);
        for (int i = 0; i < personagens.size(); i++)
        {
            personagens.at(i)->move();
            window->draw(personagens.at(i)->getCorpo());
        }
        window->display();
    }
    personagens.clear();
}