#include "botao.hpp"

Botao::Botao(const std::string texto, const sf::Vector2f posicao, const sf::Vector2f tamBotao) : Ente(IDs::IDs::botao), caixaTexto(pGrafico->carregarFonte(CAMINHO_FONTE), texto), selecionado(false), tempoTroca(0.5f), tempo(0.0f), relogio(), posicao(posicao), tamanho(tamanho)
{
    caixa.setPosition(posicao);
    caixa.setSize(tamBotao);
    sf::Vector2f tamTexto = caixaTexto.getTam();
    sf::Vector2f posTexto = sf::Vector2f(
        posicao.x + tamanho.x / 2.0f - tamTexto.x / 2.0f,
        posicao.y + tamanho.y / 2.0f - tamTexto.y * 1.5f);
    caixaTexto.setPosicao(posTexto);
    caixa.setFillColor(sf::Color::Transparent);
}

Botao::~Botao()
{
}

void Botao::setSelecionado(const bool selecionado)
{
    this->selecionado = selecionado;
}

void Botao::atualizar()
{
    const float dt = relogio.getElapsedTime().asSeconds();
    relogio.restart();
    tempo += dt;
    if (selecionado)
    {
        if (tempo > tempoTroca)
        {
            int transparente = caixaTexto.getTransparente();
            if (caixaTexto.getClareando())
            {
                // texto clareando
                transparente += 5;
                if (transparente > 255)
                {
                    transparente = 255;
                    caixaTexto.mudarClareando();
                }
            }
            else
            {
                // texto escurecendo
                transparente -= 5;
                if (transparente < 0)
                {
                    transparente = 0;
                    caixaTexto.mudarClareando();
                }
            }
            caixaTexto.setTransparente(transparente);
            tempo = 0.0f;
        }
    }
    else
    {
        tempo = 0.0f;
    }
}

void Botao::desenhar()
{
    atualizar();
    pGrafico->desenhaElemento(caixa);
    pGrafico->desenhaTexto(caixaTexto.getTexto());
}
