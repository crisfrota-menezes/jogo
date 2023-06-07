
#include "principal.hpp"

Jogo::Jogo() : pGrafico(pGrafico->getGerenciadorGrafico()), listaPersonagem(), listaObstaculo(), colisor(&listaPersonagem, &listaObstaculo), pEvento(pEvento->getGerenciadorEvento())
{
    if (pGrafico == nullptr)
    {
        cout << "Erro ao criar o gerenciador grafico" << endl;
        exit(1);
    }

    if (pEvento == nullptr)
    {
        cout << "Erro ao criar o gerenciador de eventos" << endl;
        exit(1);
    }

    instanciaEntidades();

    run();
}

Jogo::~Jogo()
{
    listaObstaculo.limpar();
    listaPersonagem.limpar();
}

void Jogo::instanciaEntidades()
{
    // bool coop = true;
    Jogador *jogador = new Jogador(sf::Vector2f(100.0f, 100.0f));
    /*if (coop == true)
    {
        Jogador2 *jogador = new Jogador2(sf::Vector2f(200.0f, 100.0f));
        listaPersonagem.inserir(static_cast<Entidades::Entidade *>(jogador));
    }*/
    Alien1 *alien1 = new Alien1(sf::Vector2f(100.0f, 100.0f), jogador);
    Alien2 *alien2 = new Alien2(sf::Vector2f(200.0f, 200.0f), jogador);
    Alien3 *alien3 = new Alien3(sf::Vector2f(300.0f, 300.0f), jogador);
    Plataforma *p1 = new Plataforma(sf::Vector2f(1100.0f, 800.0f));
    Arvore *a1 = new Arvore(sf::Vector2f(300.0f, 800.0f));
    Rochas *r1 = new Rochas(sf::Vector2f(800.0f, 900.0f));

    Entidade *e1 = static_cast<Entidades::Entidade *>(jogador);
    Entidade *e2 = static_cast<Entidades::Entidade *>(alien1);
    Entidade *e3 = static_cast<Entidades::Entidade *>(alien2);
    Entidade *e4 = static_cast<Entidades::Entidade *>(alien3);
    Entidade *e5 = static_cast<Entidades::Entidade *>(p1);
    Entidade *e6 = static_cast<Entidades::Entidade *>(a1);
    Entidade *e7 = static_cast<Entidades::Entidade *>(r1);

    listaPersonagem.inserir(e1);
    listaPersonagem.inserir(e2);
    listaPersonagem.inserir(e3);
    listaPersonagem.inserir(e4);

    listaObstaculo.inserir(e5);
    listaObstaculo.inserir(e6);
    listaObstaculo.inserir(e7);

    // cria chão com plataformas
    for (int i = 0; i < 10; i++)
    {
        Plataforma *chao = new Plataforma(sf::Vector2f(300.0f * i, 1000.0f));
        listaObstaculo.inserir(static_cast<Entidades::Entidade *>(chao));
    }

    pEvento->setJogador(jogador);
}

void Jogo::run()
{
    while (pGrafico->janelaAberta())
    {
        pEvento->executar();
        pGrafico->limpar();
        pGrafico->carregarBackground();
        listaPersonagem.executar();
        listaObstaculo.executar();
        colisor.executar();
        pGrafico->mostraElementos();
    }
}