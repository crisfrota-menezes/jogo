#include "texto.hpp"

Texto::Texto(sf::Font fonte, const std::string texto) : fonte(fonte), texto(), info(texto), tamTexto(80), transparente(255), corTexto(sf::Color::White), corBorda(sf::Color::Black), clareando(true)
{
    inicializa();
}

Texto::~Texto()
{
}

void Texto::inicializa()
{
    texto.setString(info);
    texto.setCharacterSize(tamTexto);
    texto.setFont(fonte);
    texto.setOutlineThickness(5);
    texto.setOutlineColor(corBorda);
    texto.setFillColor(corTexto);
    tam = sf::Vector2f(texto.getGlobalBounds().width, texto.getGlobalBounds().height);
}

void Texto::setString(const std::string texto)
{
    info = texto;
    this->texto.setString(info);
}

const std::string Texto::getString()
{
    return info;
}

sf::Text Texto::getTexto()
{
    return texto;
}

void Texto::setPosicao(const sf::Vector2f posicao)
{
    texto.setPosition(posicao);
}

sf::Vector2f Texto::getTam()
{
    return tam;
}

void Texto::mudarClareando()
{
    clareando = (clareando) ? false : true;
}

const bool Texto::getClareando() const
{
    return clareando;
}

const int Texto::getTransparente() const
{
    return transparente;
}

void Texto::setTransparente(int transparente)
{
    this->transparente = transparente;
    atualizar();
}

void Texto::resetar()
{
    transparente = 255;
    atualizar();
}

void Texto::atualizar()
{
    corBorda = sf::Color{0, 0, 0, (sf::Uint8)this->transparente};
    corTexto = sf::Color{255, 255, 255, (sf::Uint8)this->transparente};
    texto.setOutlineColor(corBorda);
    texto.setFillColor(corTexto);
}