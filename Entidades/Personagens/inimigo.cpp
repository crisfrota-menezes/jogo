#include "inimigo.hpp"

Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador *jogador) : Personagem(pos, tam, VELOCIDADE_INIMIGO, IDs::IDs::inimigo), jogador(jogador), dtAux(0.0f)
{
    sf::Vector2f posAleatoria = posicaoAleatoria(1920, 1080);
    setPos(posAleatoria);
    corpo.setFillColor(sf::Color::Red);
    inicializa();
    srand(time(NULL));
    moveAleatorio = rand() % 4;
    if (moveAleatorio == 0)
    {
        parar();
    }
    else if (moveAleatorio == 1)
    {
        andar(true);
    }
    else
    {
        andar(false);
    }
    inicializa();
}

Inimigo::~Inimigo()
{
}

void Inimigo::inicializa()
{
}

void Inimigo::atualizaMoveAleatorio()
{
    if (dtAux > 3.0f)
    {
        moveAleatorio = rand() % 3;
        if (moveAleatorio == 0)
        {
            parar();
        }
        else if (moveAleatorio == 1)
        {
            andar(true);
        }
        else
        {
            andar(false);
        }
        dtAux = 0.0f;
    }
}

void Inimigo::colisao(Entidade *outraEntidade, sf::Vector2f ds)
{
}

void Inimigo::atualizar()
{
    sf::Vector2f posJogador = jogador->getPos();
    sf::Vector2f posInimigo = getPos();
    if (fabs(posJogador.x - posInimigo.x) < VISAO_INIMIGO_X && fabs(posJogador.y - posInimigo.y) < VISAO_INIMIGO_Y)
    {
        if (posJogador.x - posInimigo.x > 0.0f)
        {
            andar(false);
        }
        else
        {
            andar(true);
        }
    }
    else
    {
        atualizaMoveAleatorio();
    }
    atualizarPos();
    dtAux += relogio.getElapsedTime().asSeconds();
    relogio.restart();
}