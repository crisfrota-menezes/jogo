#include "arvore.hpp"

Arvore::Arvore(sf::Vector2f pos) : Obstaculo(pos, sf::Vector2f(TAMANHO_Arvore_X, TAMANHO_Arvore_Y), IDs::IDs::Arvore, CAMINHO_TEXTURA_Arvore), flexibilidade(0.25f)
{
    // terminar...
}

Arvore::~Arvore()
{
}

void Arvore::colisao(Entidade *outraEntidade, sf::Vector2f ds)
{
    sf::Vector2f posOutro = outraEntidade->getPos();
    sf::Vector2f tamOutro = outraEntidade->getTam();

    if (outraEntidade->getID() == IDs::IDs::jogador || outraEntidade->getID() == IDs::IDs::Uraniano)
    {
        colisaoObstaculo(ds, static_cast<Personagem *>(outraEntidade));
    }
}

void Arvore::colisaoObstaculo(sf::Vector2f ds, Personagem *pPersonagem)
{
    sf::Vector2f posOutro = pPersonagem->getPos();
    sf::Vector2f tamOutro = pPersonagem->getTam();
    sf::Vector2f velFinal = pPersonagem->getVelFinal();
    if (ds.x < 0.0f && ds.y < 0.0f)
    { // houve colisao
        if (ds.x > ds.y)
        {
            if (pPersonagem->getID() == IDs::IDs::jogador)
            {
                velFinal.x *= flexibilidade;
                if (posOutro.x < pos.x)
                { // colisão em x
                    pos.x -= ds.x;
                }
                else
                {
                    pos.x += ds.x;
                }
                setPos(pos);
            }
            else
            {
                if (posOutro.x < pos.x)
                { // colisão em x
                    posOutro.x += ds.x;
                }
                else
                {
                    posOutro.x -= ds.x;
                }
            }
        }
        else
        {
            if (posOutro.y < pos.y)
            { // colisão em y
                posOutro.y += ds.y;
                if (pPersonagem->getID() == IDs::IDs::jogador)
                {
                    Jogador *pJogador = static_cast<Jogador *>(pPersonagem);
                    pJogador->podePular();
                }
            }
            else
            {
                posOutro.y -= ds.y;
            }
            velFinal.y = 0.0f;
        }
    }
    pPersonagem->setPos(posOutro);
    pPersonagem->setVelFinal(velFinal);
}