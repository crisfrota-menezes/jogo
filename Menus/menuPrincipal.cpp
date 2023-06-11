#include "menuPrincipal.hpp"

MenuPrincipal::MenuPrincipal() : gg(gg->getGerenciadorGrafico()), window(gg->getWindow()), pos(0), pressed(false), select(false)
{
    font = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();
    set_values();
}

MenuPrincipal::~MenuPrincipal()
{
    delete font;
    delete image;
    delete bg;
}

void MenuPrincipal::set_values()
{
    font->loadFromFile("./Midia/PressStart2P-Regular.ttf");
    image->loadFromFile("./Midia/background.jpg");
    bg->setTexture(*image);
    mousePos = sf::Mouse::getPosition(*window);
    mouseCoord = gg->getWindow()->mapPixelToCoords(mousePos);

    options = {"Fase 1", "Fase 2", "Ranking", "Opcoes", "Sair"};
    textos.resize(5);
    coords = {{100, 100}, {100, 200}, {100, 300}, {100, 400}, {100, 500}};
    sizes = {50, 50, 50, 50, 50};

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

bool MenuPrincipal::loop_events()
{
    sf::Event event;

    while (gg->janelaAberta())
    {
        if (event.type == sf::Event::Closed)
        {
            gg->fechaJanela();
            return false;
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Up)
            {
                if (pos > 0)
                {
                    textos[pos].setOutlineThickness(5);
                    textos[pos + 1].setOutlineThickness(0);
                    pos--;
                }
            }
            else if (event.key.code == sf::Keyboard::Down)
            {
                if (pos < options.size() - 1)
                {
                    textos[pos].setOutlineThickness(5);
                    textos[pos - 1].setOutlineThickness(0);
                    pos++;
                }
            }
            else if (event.key.code == sf::Keyboard::Enter)
            {
                select = true;
            }
        }
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                pressed = true;
            }
        }
        else if (event.type == sf::Event::MouseButtonReleased)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                pressed = false;
                select = true;
            }
        }
    }

    for (int i = 0; i < options.size(); i++)
    {
        if (mouseCoord.x >= coords[i].x && mouseCoord.x <= coords[i].x + sizes[i] && mouseCoord.y >= coords[i].y && mouseCoord.y <= coords[i].y + 50)
        {
            pos = i;
            if (pressed)
                select = true;
        }
    }

    return true;
}

void MenuPrincipal::draw()
{
    gg->limpar();
    gg->desenhaBackground(bg);

    for (int i = 0; i < options.size(); i++)
    {
        if (i == pos)
            textos[i].setFillColor(sf::Color::Red);
        else
            textos[i].setFillColor(sf::Color::White);

        textos[i].setPosition(coords[i]);
        gg->desenhaTexto(textos[i]);
    }

    gg->mostraElementos();
}

bool MenuPrincipal::run()
{
    while (loop_events())
    {
        if (select)
        {
            switch (pos)
            {
            case 0:
                return true;
                break;
            case 1:
                return true;
                break;
            case 2:
                // Ranking ranking;
                // ranking.run();
                break;
            case 3:
                // Opcoes opcoes;
                // opcoes.run();
                break;
            case 4:
                gg->fechaJanela();
                return false;
                break;
            }
            select = false;
        }
        draw();
    }
    return false;
}