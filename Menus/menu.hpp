#pragma once

#include "../ente.hpp"
#include "botao.hpp"
#include <list>
using std::list;

namespace SpaceHunt
{
    namespace Menus
    {
        class Menu : public Ente
        {
        protected:
            sf::Texture textura;
            sf::RectangleShape fundo;
            list<Botao *> botoes;
            list<Botao *>::iterator it;
            const sf::Vector2f tamBotao;
            const sf::Vector2f tamJanela;

        public:
            Menu(const IDs::IDs ID, const sf::Vector2f tamBotao);
            ~Menu();
            void addBotao(const std::string texto, const sf::Vector2f posicao, const IDs::IDs ID);
            void desenhar();
            virtual void executar() = 0;
        };
    }
    using namespace Menus;
}
using namespace SpaceHunt;