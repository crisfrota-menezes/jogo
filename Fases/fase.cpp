#include "fase.hpp"

Fase::Fase(const IDs::IDs ID_Fase, const IDs::IDs ID_Fundo) : Ente(ID_Fase),
                                                              fundo(ID_Fundo),
                                                              listaPersonagens(),
                                                              listaObstaculos(),
                                                              pColisao(new GerenciadorColisao(&listaPersonagens, &listaObstaculos)),
                                                              construtorEnt()
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
        listaPersonagens.inserir(construtorEnt.criarUraniano(posAux));
    }
    break;
    /*case ('k'):
    {
        criaVerme(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
    }
    break;*/
    case ('V'):
    {
        listaPersonagens.inserir(construtorEnt.criarVenusiano(posAux));
    }
    break;
    case ('a'):
    {
        //listaPersonagens.inserir(construtorEnt.criarArvore(posAux));
    }
    break;
    case ('#'):
    {
        listaPersonagens.inserir(construtorEnt.criarPlataforma(posAux));
    }
    break;
    case ('j'):
    {
        listaPersonagens.inserir(construtorEnt.criarJogador(posAux));
    }
    break;
    case ('r'):
    {
        listaObstaculos.inserir(construtorEnt.criarRocha(posAux));
    }
    break;
    /*case ('p'):
    {
        criarProjetil(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
    }
    break;*/
    }
}

Jogador *Fase::getJogador()
{
    for(int i = 0; i < listaPersonagens.getTam(); i++)
    {
        Entidade *entidade = listaPersonagens.operator[](i);
        if(entidade->getID() == IDs::IDs::jogador)
        {
            return static_cast<Jogador *>(entidade);
        }
    }
    return nullptr;
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