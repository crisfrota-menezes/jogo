
#include "principal.hpp"

Jogo::Jogo() : pGrafico(pGrafico->getGerenciadorGrafico())
{
    if (pGrafico == nullptr)
    {
        cout << "Erro ao criar o gerenciador grafico" << endl;
        exit(1);
    }

    image = new sf::Texture();
    bg = new sf::Sprite();
}

Jogo::~Jogo()
{
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
        listaEntidade.executar(pGrafico->getWindow());
        pGrafico->mostraElementos();
    }
}

void Jogo::instanciaEntidades()
{
    Jogador *jogador = new Jogador(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(100.0f, 100.0f));
    Inimigo *inimigo = new Inimigo(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(100.0f, 100.0f), jogador);

    Personagem *p1 = static_cast<Entidades::Personagens::Personagem *>(jogador);
    Personagem *p2 = static_cast<Entidades::Personagens::Personagem *>(inimigo);

    /*Entidade *e1 = static_cast<Entidades::Entidade *>(jogador);
    Entidade *e2 = static_cast<Entidades::Entidade *>(inimigo);

    listaEntidade.inserir(jogador);
    listaEntidade.inserir(inimigo);*/
}