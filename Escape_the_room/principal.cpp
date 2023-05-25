
#include "principal.hpp"

Jogo::Jogo() : pGrafico(pGrafico->getGerenciadorGrafico()), listaPersonagem(), listaObstaculo(), colisor(&listaPersonagem, &listaObstaculo)
{
    if (pGrafico == nullptr)
    {
        cout << "Erro ao criar o gerenciador grafico" << endl;
        exit(1);
    }

    instanciaEntidades();

    image = new sf::Texture();
    bg = new sf::Sprite();
}

Jogo::~Jogo()
{
    listaObstaculo.limpar();
    listaPersonagem.limpar();
    delete image;
    delete bg;
}

void Jogo::instanciaEntidades()
{
    Jogador *jogador = new Jogador(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(100.0f, 100.0f));
    Inimigo *inimigo = new Inimigo(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(100.0f, 100.0f), jogador);
    ObsGenerico *obstaculo = new ObsGenerico(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(100.0f, 100.0f));

    // Personagem *p1 = static_cast<Entidades::Personagens::Personagem *>(jogador);
    // Personagem *p2 = static_cast<Entidades::Personagens::Personagem *>(inimigo);

    Entidade *e1 = static_cast<Entidades::Entidade *>(jogador);
    Entidade *e2 = static_cast<Entidades::Entidade *>(inimigo);
    Entidade *e3 = static_cast<Entidades::Entidade *>(obstaculo);

    listaPersonagem.inserir(e1);
    listaPersonagem.inserir(e2);

    listaObstaculo.inserir(e3);
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
        listaPersonagem.executar(pGrafico->getWindow());
        listaObstaculo.executar(pGrafico->getWindow());
        colisor.executar();
        pGrafico->mostraElementos();
    }
}