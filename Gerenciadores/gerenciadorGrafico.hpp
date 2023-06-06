#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

namespace Escape_the_room
{
    namespace Gerenciadores
    {
        class GerenciadorGrafico
        {
        private:
            sf::RenderWindow *window;
            sf::Texture *imagem;
            sf::Sprite *bg;
            static GerenciadorGrafico *pGrafico;
            /*utilizando padrão de projeto singleton na implementação*/
            GerenciadorGrafico();

        public:
            ~GerenciadorGrafico();
            static GerenciadorGrafico *getGerenciadorGrafico();
            sf::RenderWindow *getWindow();
            void limpar();
            void desenhaElemento(sf::RectangleShape corpo);
            void mostraElementos();
            void fechaJanela();
            void carregarBackground();
            sf::Texture carregarTextura(const char *caminho);
            const bool janelaAberta();
        };
    }
    using namespace Gerenciadores;
}
using namespace Escape_the_room;