#include "projetil.hpp"

Projetil::Projetil(const sf::Vector2f pos, Jogador *jogador)
    : Entidade(pos, sf::Vector2f(20.0f, 20.0f), IDs::IDs::Projetil),
      velocidade(5.0f),
      jogador(jogador),
      dano(4)
{
    corpo.setFillColor(sf::Color::Yellow);
}

void Projetil::atualizar()
{
    // Update projectile position based on velocity
    corpo.move(velocidade, 0.0f);

    desenhar();

    // Destroy projectile if necessary
    if (corpo.getPosition().x > 1920.0f)
    {
        cout << "sai da tela" << endl;
        velocidade = 0.0f;
        corpo.setFillColor(sf::Color::Transparent);
        //delete this;
    }
}

void Projetil::colisao(Entidade *outraEnt, sf::Vector2f ds)
{
    sf::Vector2f posOutro = outraEnt->getPos();
    // Check for collision with jogador or venusiano
    switch (outraEnt->getID())
    {
    case (IDs::IDs::jogador):
    {
        cout << "Jogador atingido" << endl;
        outraEnt->vida -= dano;
        outraEnt->setPos(sf::Vector2f(posOutro.x - 75.0f, posOutro.y - 25.0f));
        delete this;
    }
    break;
    }
}