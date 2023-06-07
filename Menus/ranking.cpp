#include "ranking.hpp"

Ranking::Ranking()
{
    window.create(sf::VideoMode(800, 600), "Ranking");
    font.loadFromFile("C:/Users/crisn/Desktop/SpaceHunt/Midia/PressStart2P-Regular.ttf");
    image.loadFromFile("C:/Users/crisn/Desktop/SpaceHunt/Midia/background.jpg");
    bg.setTexture(image);
    mousePos = sf::Mouse::getPosition(window);
    mouseCoord = window.mapPixelToCoords(mousePos);
    options = {"Fulano", "Cicrano", "Beltrano", "Seila"};
    textos.resize(4);
    coords = {{100, 100}, {100, 200}, {100, 300}, {100, 400}};
    sizes = {50, 50, 50, 50};
    for (std::size_t i{}; i < textos.size(); i++)
    {
        textos[i].setFont(font);
        textos[i].setString(options[i]);
        textos[i].setCharacterSize(sizes[i]);
        textos[i].setPosition(coords[i]);
    }
}

Ranking::~Ranking()
{
}

void Ranking::run()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        draw();
        window.display();
    }
}

void Ranking::draw()
{
    window.draw(bg);
    for (auto &texto : textos)
    {
        window.draw(texto);
    }
}