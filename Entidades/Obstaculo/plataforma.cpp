#include "plataforma.hpp"

Plataforma::Plataforma(const sf::Vector2f pos, const sf::Vector2f tam) : Obstaculo(pos, tam, IDs::IDs::plataforma)
{
    corpo.setFillColor(sf::Color::White);
}

Plataforma::~Plataforma()
{
}

void Plataforma::colisao(Entidade *outraEnt, sf::Vector2f ds)
{
    sf::Vector2f posOutro = outraEnt->getPos();
    sf::Vector2f tamOutro = outraEnt->getTam();

    if (outraEnt->getID() == IDs::IDs::jogador || outraEnt->getID() == IDs::IDs::inimigoF || outraEnt->getID() == IDs::IDs::inimigoM || outraEnt->getID() == IDs::IDs::inimigoD)
    {
        colisaoObstaculo(ds, static_cast<Personagem *>(outraEnt));
    }
}

void Plataforma::colisaoObstaculo(sf::Vector2f ds, Personagem *pPersonagem)
{
    sf::Vector2f posOutro = pPersonagem->getPos();
    sf::Vector2f tamOutro = pPersonagem->getTam();
    sf::Vector2f velFinal = pPersonagem->getVelFinal();

    if (ds.x < 0.0f && ds.y < 0.0f)
    {
        if (ds.x > ds.y)
        {
            if (posOutro.x < pos.x)
            {
                posOutro.x += ds.x;
            }
            else
            {
                posOutro.x -= ds.x;
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