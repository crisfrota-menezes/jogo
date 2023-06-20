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

void Menu::addBotao(const std::string texto, const sf::Vector2f posicao, const IDs::IDs ID)
{
    Botao *botao = new Botao(texto, posicao, tamBotao, ID);
    if (botao == nullptr)
    {
        throw("nao foi possivel criar um botao");
    }
    botoes.push_back(botao);
}

void Menu::desenhar()
{
    pGrafico->resetarJanela();
    pGrafico->desenhaElemento(fundo);
    list<Botao *>::iterator aux;
    for (aux = botoes.begin(); aux != botoes.end(); aux++)
    {
        Botao *botao = *aux;
        botao->desenhar();
        botao = nullptr;
    }
}