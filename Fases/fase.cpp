#include "fase.hpp"

Fase::Fase(const IDs::IDs ID_Fase):
    Ente(ID_Fase), listaPersonagens(), listaObstaculos(),
    pColisao(new GerenciadorColisao(&listaPersonagens, &listaObstaculos))
{
    if(pColisao == nullptr){
        std::cout << "nao foi possivel criar um Gerenciador de Colisao" << std::endl;
        exit(1);
    }
}

Fase::~Fase(){
    if(pColisao){
        delete(pColisao);
        pColisao = nullptr;
    }
    listaObstaculos.limpar();
    listaPersonagens.limpar();
}

void Fase::criarPlataforma(const sf::Vector2f pos){
    Plataforma* plataforma = new Plataforma(pos);
    if(plataforma == nullptr){
        std::cout << "nao foi possivel criar uma plataforma" << std::endl;
        exit(1);
    }
    listaObstaculos.inserir(static_cast<Entidade*>(plataforma));
}

void Fase::criarArvore(const sf::Vector2f pos){
    Arvore* arvore = new Arvore(pos);
    if(arvore == nullptr){
        std::cout << "nao foi possivel criar uma Arvore" << std::endl;
        exit(1);
    }
    listaObstaculos.inserir(static_cast<Entidade*>(arvore));
}

void Fase::criarRochas(const sf::Vector2f pos){
    Rochas* rochas = new Rochas(pos);
    if(rochas == nullptr){
        std::cout << "nao foi possivel criar uma Rochas" << std::endl;
        exit(1);
    }
    listaObstaculos.inserir(static_cast<Entidade*>(rochas));
}

void Fase::criaAlien1(const sf::Vector2f pos){
    GerenciadorEvento* pEvento = pEvento->getGerenciadorEvento();
    Jogador* pJogador = pEvento->getJogador();
    Alien1* alien1 = new Alien1(pos, pJogador);
    if(alien1 == nullptr){
        std::cout << "nao foi possivel criar um alien1" << std::endl;
        exit(1);
    }
    listaPersonagens.inserir(static_cast<Entidade*>(alien1));
}

void Fase::criaAlien2(const sf::Vector2f pos){
    GerenciadorEvento* pEvento = pEvento->getGerenciadorEvento();
    Jogador* pJogador = pEvento->getJogador();
    Alien2* alien2 = new Alien2(pos, pJogador);
    if(alien2 == nullptr){
        std::cout << "nao foi possivel criar um alien2" << std::endl;
        exit(1);
    }
    listaPersonagens.inserir(static_cast<Entidade*>(alien2));
}

void Fase::criaAlien3(const sf::Vector2f pos){
    GerenciadorEvento* pEvento = pEvento->getGerenciadorEvento();
    Jogador* pJogador = pEvento->getJogador();
    Alien3* alien3 = new Alien3(pos, pJogador);
    if(alien3 == nullptr){
        std::cout << "nao foi possivel criar um alien3" << std::endl;
        exit(1);
    }
    listaPersonagens.inserir(static_cast<Entidade*>(alien3));
}

void Fase::criarJogador(const sf::Vector2f pos){
    Jogador* jogador = new Jogador(pos);
    if(jogador == nullptr){
        std::cout << "nao foi possivel criar um Jogador" << std::endl;
        exit(1);
    }
    GerenciadorEvento* pEvento = pEvento->getGerenciadorEvento();
    pEvento->setJogador(jogador);
    listaPersonagens.inserir(static_cast<Entidade*>(jogador));
}

void Fase::criarEntidade(char letra, const sf::Vector2i pos){
    switch (letra)
    {
        case ('i'):
        {
            criaAlien1(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
        }
        break;
        case('c'):
        {
            criarArvore(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
        }
        break;
        case('#'):
        {
            criarPlataforma(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
        }
        break;
        case('j'):{
            criarJogador(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
        }
    }
}

void Fase::desenhar(){
    listaPersonagens.executar();
    listaObstaculos.executar();
}

void Fase::executar(){
    //atualiza entidade e desenha
    desenhar();

    //verifica colisão
    pColisao->executar();
}