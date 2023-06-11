#include "rochas.hpp"

Rochas::Rochas(sf::Vector2f pos, sf::Vector2f tam) : Obstaculo(pos, sf::Vector2f(TAMANHO_Rochas_X, TAMANHO_Rochas_Y), IDs::IDs::Rochas, CAMINHO_Rochas)
{
}

Rochas::~Rochas()
{
}

void Rochas::colisao(Entidade *outraEnt, sf::Vector2f ds)
{
    sf::Vector2f posOutro = outraEnt->getPos();
    sf::Vector2f tamOutro = outraEnt->getTam();

    if (outraEnt->getID() == IDs::IDs::jogador)
    {
        /*outraEnt->vida -= dano;
        outraEnt->setPos(sf::Vector2f(posOutro.x - 75.0f, posOutro.y - 25.0f));
        if(outraEnt->vida <= 0)
        {
            delete outraEnt;
            cout << "MORTE POR ROCHA" << endl;
            cout << "GAME OVER" << endl;
            exit(0);
        }*/
        colisaoObstaculo(ds, static_cast<Personagem *>(outraEnt));
    }
    else if (outraEnt->getID() == IDs::IDs::Uraniano || outraEnt->getID() == IDs::IDs::Verme || outraEnt->getID() == IDs::IDs::Venusiano)
    {
        colisaoObstaculo(ds, static_cast<Personagem *>(outraEnt));
    }
}

/*void Rochas::colisaoObstaculo(sf::Vector2f ds, Personagem *pPersonagem)
{
    sf::Vector2f posOutro = pPersonagem->getPos();
    sf::Vector2f tamOutro = pPersonagem->getTam();
    sf::Vector2f velFinal = pPersonagem->getVelFinal();
    // int vidaEnt = pPersonagem->getVida();

    if (ds.x < 0.0f && ds.y < 0.0f)
    {
        if (ds.x > ds.y)
        {
            if (posOutro.x < pos.x)
            {
                posOutro.x -= ds.x;
                // vida -= dano;
            }
            else
            {
                posOutro.x += ds.x;
                // vida -= dano;
            }
            velFinal.x = 0.0f;
        }
        else
        {
            if (posOutro.y < pos.y)
            {
                posOutro.y += ds.y;
                if (pPersonagem->getID() == IDs::IDs::jogador)
                {
                    Jogador *pJogador = static_cast<Jogador *>(pPersonagem);
                    pJogador->podePular();
                }
                // vida -= dano;
            }
            else
            {
                posOutro.y -= ds.y;
                // vida -= dano;
            }
        }
    }
    pPersonagem->setPos(posOutro);
    pPersonagem->setVelFinal(velFinal);
    // pPersonagem->setVida(vidaEnt);
}*/