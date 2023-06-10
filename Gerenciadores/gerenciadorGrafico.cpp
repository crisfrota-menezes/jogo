#include "gerenciadorGrafico.hpp"

GerenciadorGrafico *GerenciadorGrafico::pGrafico = nullptr;

GerenciadorGrafico::GerenciadorGrafico() : window(new sf::RenderWindow(sf::VideoMode(LARGURA_TELA, ALTURA_TELA), "Space Hunt")), camera(sf::Vector2f(LARGURA_TELA / 2.0f, ALTURA_TELA / 2.0f), sf::Vector2f(LARGURA_TELA, ALTURA_TELA))
{
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

const bool GerenciadorGrafico::janelaAberta()
{
    return window->isOpen();
}

void GerenciadorGrafico::atualizarCamera(const sf::Vector2f posJogador)
{
    camera.setCenter(posJogador.x, 540.0f);
    window->setView(camera);
}

const sf::View GerenciadorGrafico::getCamera()
{
    return camera;
}