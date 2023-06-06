#include "gerenciadorGrafico.hpp"

GerenciadorGrafico *GerenciadorGrafico::pGrafico = nullptr;

GerenciadorGrafico::GerenciadorGrafico() : window(new sf::RenderWindow(sf::VideoMode(1920, 1080), "Escape the room"))
{
    imagem = new sf::Texture();
    bg = new sf::Sprite();
    if (window == nullptr)
    {
        cout << "Erro ao criar janela" << endl;
        exit(1);
    }
}

GerenciadorGrafico::~GerenciadorGrafico()
{
    if (window)
    {
        delete window;
        window = nullptr;
    }
}

GerenciadorGrafico *GerenciadorGrafico::getGerenciadorGrafico()
{
    if (pGrafico == nullptr)
    {
        pGrafico = new GerenciadorGrafico();
    }
    return pGrafico;
}

sf::RenderWindow *GerenciadorGrafico::getWindow()
{
    return window;
}

void GerenciadorGrafico::limpar()
{
    window->clear();
}

void GerenciadorGrafico::desenhaElemento(sf::RectangleShape corpo)
{
    window->draw(corpo);
}

void GerenciadorGrafico::mostraElementos()
{
    window->display();
}

void GerenciadorGrafico::fechaJanela()
{
    window->close();
}

sf::Texture GerenciadorGrafico::carregarTextura(const char *caminho)
{
    sf::Texture textura;
    if (!textura.loadFromFile(caminho))
    {
        cout << "Erro ao carregar textura" << endl;
        exit(1);
    }
    return textura;
}

void GerenciadorGrafico::carregarBackground()
{
    if (!imagem->loadFromFile("C:/Users/crisn/Desktop/projetoTecProg/Midia/background.png"))
    {
        cout << "Erro ao carregar imagem" << endl;
        exit(1);
    }
    bg->setTexture(*imagem);
    window->draw(*bg);
}

const bool GerenciadorGrafico::janelaAberta()
{
    return window->isOpen();
}