#include "fase.hpp"

Fase::Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo) : Ente(ID_Fase),
                                                              fundo(ID_Fundo),
                                                              listaPersonagens(),
                                                              listaObstaculos(),
                                                              pColisao(new GerenciadorColisao(&listaPersonagens, &listaObstaculos)),
                                                              construtor()
{
    if (pColisao == nullptr)
    {
        std::cout << "nao foi possivel criar um Gerenciador de Colisao" << std::endl;
        exit(1);
    }
}

Fase::~Fase()
{
    if (pColisao)
    {
        delete (pColisao);
        pColisao = nullptr;
    }
    listaObstaculos.limpar();
    listaPersonagens.limpar();
}

void Fase::criarEntidade(char letra, const sf::Vector2i pos)
{
    sf::Vector2f posAux = sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f);
    switch (letra)
    {
    case ('u'):
    {
        listaPersonagens.inserir(construtor->criarUraniano(posAux));
    }
    break;
    /*case ('k'):
    {
        criaVerme(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
    }
    break;*/
    case ('V'):
    {
        listaPersonagens.inserir(construtor->criarVenusiano(posAux));
    }
    break;
    case ('a'):
    {
        listaPersonagens.inserir(construtor->criarArvore(posAux));
    }
    break;
    case ('#'):
    {
        listaPersonagens.inserir(construtor->criarPlataforma(posAux));
    }
    break;
    case ('j'):
    {
        listaPersonagens.inserir(construtor->criarJogador(posAux));
    }
    break;
    case ('r'):
    {
        listaObstaculos.inserir(construtor->criarRocha(posAux));
    }
    break;
    /*case ('p'):
    {
        criarProjetil(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
    }
    break;*/
    }
}

bool Fase::concluida()
{
    return listaPersonagens.vazia();
}

void Fase::desenhar()
{
    listaPersonagens.executar();
    listaObstaculos.executar();
}

void Fase::executar()
{
    fundo.executar();

    // atualiza entidade e desenha
    desenhar();

    // verifica colisão
    pColisao->executar();
}