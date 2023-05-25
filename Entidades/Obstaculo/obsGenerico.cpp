#include "obsGenerico.hpp"

ObsGenerico::ObsGenerico(const sf::Vector2f pos, const sf::Vector2f tam) : Obstaculo(pos, tam, IDs::IDs::obsGenerico)
{
    corpo.setFillColor(sf::Color::Blue);
}

ObsGenerico::~ObsGenerico()
{
}

void ObsGenerico::colisao(Entidade *outraEnt, sf::Vector2f ds)
{
    /*sf::Vector2f posOutro = outraEnt->getPos();
    sf::Vector2f tamOutro = outraEnt->getTam();

    if (outraEnt->getID() == IDs::IDs::jogador || outraEnt->getID() == IDs::IDs::inimigo)
    {
        colisaoObstaculo(ds, static_cast<Personagem *>(outraEnt));
    }*/
}

/*void ObsGenerico::colisaoObstaculo(sf::Vector2f ds, Personagem *pPersonagem)
{
    sf::Vector2f posOutro = pPersonagem->getPos();
    sf::Vector2f tamOutro = pPersonagem->getTam();

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
        }
    }
    pPersonagem->setPos(posOutro);
}*/

void ObsGenerico::atualizar()
{
}