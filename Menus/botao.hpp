#pragma once

#include "../ente.hpp"
#include "texto.hpp"

#define CAMINHO_FONTE "C:/Users/crisn/Desktop/SpaceHunt/Midia/PressStart2P-Regular.ttf"

namespace SpaceHunt
{
    namespace Menus
    {
        namespace Botoes
        {
            class Botao : public Ente
            {
            private:
                sf::RectangleShape caixa;
                Texto caixaTexto;
                sf::Vector2f posicao;
                sf::Vector2f tamanho;
                bool selecionado;

                sf::Clock relogio;
                const float tempoTroca;
                float tempo;

            public:
                Botao(const std::string texto, const sf::Vector2f posicao, const sf::Vector2f tamanho);
                ~Botao();
                void desenhar();
                void setSelecionado(const bool selecionado = true);
                void atualizar();
            };
        }
        using namespace Botoes;
    }
    using namespace Menus;
}
using namespace SpaceHunt;