#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include <math.h>
#include <time.h>
#include "jogador.hpp"
#include "Personagem.hpp"

#define VELOCIDADE_INIMIGO_X 0.50f
#define VELOCIDADE_INIMIGO_Y 0.50f

#define VISAO_INIMIGO_X 300.0f
#define VISAO_INIMIGO_Y 300.0f

namespace Entidades
{
    namespace Personagem
    {
        class Inimigo : public Personagem
        {
        private:
            Jogador *jogador;
            sf::Clock relogio;
            int moveAleatorio;
            void inicializa();

        public:
            Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador *jogador);
            ~Inimigo();
            void perseguir(sf::Vector2f posJogador, sf::Vector2f posInimigo);
            void movimentoAleatorio();
            void move();
        };
    }
    using namespace Personagem;
}
using namespace Entidades;