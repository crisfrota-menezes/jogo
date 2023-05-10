#include "menu.hpp"

Menu::Menu()
{
    window = new sf::RenderWindow();
    winclose = new sf::RectangleShape();
    font = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();
    set_values();
}

Menu::~Menu()
{
    delete window;
    delete winclose;
    delete font;
    delete image;
    delete bg;
}

void Menu::set_values()
{
    window->create(sf::VideoMode(1280, 720), "Menu");
    pos = 0;
    pressed = false;
    select = false;
    font->loadFromFile("./PressStart2P-Regular.ttf");
    image->loadFromFile("./background.png");
    bg->setTexture(*image);
    mousePos = sf::Mouse::getPosition(*window);
    mouseCoord = window->mapPixelToCoords(mousePos);
    options = {"Jogar", "Opcoes", "Sair"};
    textos.resize(3);
    coords = {{100, 100}, {100, 200}, {100, 300}};
    sizes = {50, 50, 50};
    for (std::size_t i{}; i < textos.size(); i++)
    {
        textos[i].setFont(*font);
        textos[i].setString(options[i]);
        textos[i].setCharacterSize(sizes[i]);
        textos[i].setOutlineColor(sf::Color::Black);
        textos[i].setPosition(coords[i]);
    }
    textos[0].setOutlineThickness(5);
}

void Menu::loop_events()
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed)
        {
            if (pos < 2)
            {
                pos++;
                pressed = true;
                textos[pos].setOutlineThickness(5);
                textos[pos - 1].setOutlineThickness(0);
                pressed = false;
                select = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed)
        {
            if (pos > 0)
            {
                pos--;
                pressed = true;
                textos[pos].setOutlineThickness(5);
                textos[pos + 1].setOutlineThickness(0);
                pressed = false;
                select = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !select)
        {
            std::cout << "Selecionado: " << options[pos] << std::endl;
            select = true;
        }
    }
}

void Menu::draw()
{
    window->clear();
    window->draw(*bg);
    for (auto t : textos)
        window->draw(t);
    window->display();
}

void Menu::run()
{
    while (window->isOpen())
    {
        loop_events();
        draw();
    }
}