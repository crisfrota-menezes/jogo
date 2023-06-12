#include "menu.hpp"

Menu::Menu(const IDs::IDs ID, const sf::Vector2f tamBotao) : Ente(ID), botoes(), it(), textura(), tamBotao(tamBotao), tamJanela(pGrafico->getTamTela())
{
    fundo = sf::RectangleShape(tamJanela);
    fundo.setPosition(0, 0);
}

Menu::~Menu()
{
    if (!botoes.empty())
    {
        for (it = botoes.begin(); it != botoes.end(); it++)
        {
            delete (*it);
            *it = nullptr;
        }
        botoes.clear();
    }
}

void Menu::addBotao(const std::string texto, const sf::Vector2f posicao)
{
    Botao *botao = new Botao(texto, posicao, tamBotao);
    if (botao == nullptr)
    {
        throw("nao foi possivel criar um botao");
    }
    botoes.push_back(botao);
}

void Menu::desenhar()
{
    pGrafico->desenhaElemento(fundo);
    for (it = botoes.begin(); it != botoes.end(); it++)
    {
        Botao *botao = *it;
        botao->desenhar();
        botao = nullptr;
    }
}