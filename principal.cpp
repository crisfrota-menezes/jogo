
#include "principal.hpp"

Jogo::Jogo() : personagens(),
               pGrafico(pGrafico->getGerenciadorGrafico())
{
    if (pGrafico == nullptr)
    {
        cout << "Erro ao criar o gerenciador grafico" << endl;
        exit(1);
    }

    Jogador *jogador = new Jogador(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(100.0f, 100.0f));
    Inimigo *inimigo = new Inimigo(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(100.0f, 100.0f), jogador);

    Personagem *p1 = static_cast<Entidades::Personagens::Personagem *>(jogador);
    Personagem *p2 = static_cast<Entidades::Personagens::Personagem *>(inimigo);

    personagens.push_back(jogador);
    personagens.push_back(inimigo);

    image = new sf::Texture();
    bg = new sf::Sprite();
}

Jogo::~Jogo()
{
    for (int i = 0; i < personagens.size(); i++)
    {
        delete personagens[i];
    }
    delete image;
    delete bg;
}

void Jogo::run()
{
    image->loadFromFile("./Midia/background.png");
    bg->setTexture(*image);
    while (pGrafico->janelaAberta())
    {
        sf::Event event;
        while (pGrafico->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                pGrafico->fechaJanela();
        }
        pGrafico->limpar();
        pGrafico->getWindow()->draw(*bg);
        for (int i = 0; i < personagens.size(); i++)
        {
            personagens.at(i)->move();
            pGrafico->desenhaElemento(personagens.at(i)->getCorpo());
        }
        pGrafico->mostraElementos();
    }
    personagens.clear();
}