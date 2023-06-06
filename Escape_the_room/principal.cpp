
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
    Jogador *jogador = new Jogador(sf::Vector2f(100.0f, 100.0f));
    Alien1 *alien1 = new Alien1(sf::Vector2f(100.0f, 100.0f), jogador);
    Alien2 *alien2 = new Alien2(sf::Vector2f(200.0f, 200.0f), jogador);
    Alien3 *alien3 = new Alien3(sf::Vector2f(300.0f, 300.0f), jogador);
    Plataforma *obstaculo = new Plataforma(sf::Vector2f(300.0f, 900.0f));

    Entidade *e1 = static_cast<Entidades::Entidade *>(jogador);
    Entidade *e2 = static_cast<Entidades::Entidade *>(alien1);
    Entidade *e3 = static_cast<Entidades::Entidade *>(alien2);
    Entidade *e4 = static_cast<Entidades::Entidade *>(alien3);
    Entidade *e5 = static_cast<Entidades::Entidade *>(obstaculo);

    listaPersonagem.inserir(e1);
    listaPersonagem.inserir(e2);
    listaPersonagem.inserir(e3);
    listaPersonagem.inserir(e4);

    listaObstaculo.inserir(e5);

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