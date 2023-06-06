
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
    Jogador *jogador = new Jogador(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(100.0f, 100.0f));
    Inimigo *inimigo = new Inimigo(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(100.0f, 100.0f), jogador);
    Plataforma *obstaculo = new Plataforma(sf::Vector2f(300.0f, 900.0f), sf::Vector2f(400.0f, 40.0f));

    Entidade *e1 = static_cast<Entidades::Entidade *>(jogador);
    Entidade *e2 = static_cast<Entidades::Entidade *>(inimigo);
    Entidade *e3 = static_cast<Entidades::Entidade *>(obstaculo);

    listaPersonagem.inserir(e1);
    listaPersonagem.inserir(e2);

    listaObstaculo.inserir(e3);

    pEvento->setJogador(jogador);
}

void Jogo::run()
{
    while (pGrafico->janelaAberta())
    {
        pEvento->executar();
        pGrafico->limpar();
        listaPersonagem.executar();
        listaObstaculo.executar();
        colisor.executar();
        pGrafico->mostraElementos();
    }
}