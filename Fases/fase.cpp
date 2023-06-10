#include "fase.hpp"

Fase::Fase(const IDs::IDs ID_Fase) : Ente(ID_Fase), listaPersonagens(), listaObstaculos(),
                                     pColisao(new GerenciadorColisao(&listaPersonagens, &listaObstaculos))
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

void Fase::criarPlataforma(const sf::Vector2f pos)
{
    Plataforma *plataforma = new Plataforma(pos);
    if (plataforma == nullptr)
    {
        std::cout << "nao foi possivel criar uma plataforma" << std::endl;
        exit(1);
    }
    listaObstaculos.inserir(static_cast<Entidade *>(plataforma));
}

void Fase::criarArvore(const sf::Vector2f pos)
{
    Arvore *arvore = new Arvore(pos);
    if (arvore == nullptr)
    {
        std::cout << "nao foi possivel criar uma Arvore" << std::endl;
        exit(1);
    }
    listaObstaculos.inserir(static_cast<Entidade *>(arvore));
}

void Fase::criarRochas(const sf::Vector2f pos)
{
    Rochas *rochas = new Rochas(pos);
    if (rochas == nullptr)
    {
        std::cout << "nao foi possivel criar uma Rochas" << std::endl;
        exit(1);
    }
    listaObstaculos.inserir(static_cast<Entidade *>(rochas));
}

void Fase::criaUraniano(const sf::Vector2f pos)
{
    GerenciadorEvento *pEvento = pEvento->getGerenciadorEvento();
    Jogador *pJogador = pEvento->getJogador();
    Uraniano *uraniano = new Uraniano(pos, pJogador);
    if (uraniano == nullptr)
    {
        std::cout << "nao foi possivel criar um Uraniano" << std::endl;
        exit(1);
    }
    listaPersonagens.inserir(static_cast<Entidade *>(uraniano));
}

void Fase::criaVerme(const sf::Vector2f pos)
{
    GerenciadorEvento *pEvento = pEvento->getGerenciadorEvento();
    Jogador *pJogador = pEvento->getJogador();
    Verme *verme = new Verme(pos, pJogador);
    if (verme == nullptr)
    {
        std::cout << "nao foi possivel criar um Verme" << std::endl;
        exit(1);
    }
    listaPersonagens.inserir(static_cast<Entidade *>(verme));
}

void Fase::criaVenusiano(const sf::Vector2f pos)
{
    GerenciadorEvento *pEvento = pEvento->getGerenciadorEvento();
    Jogador *pJogador = pEvento->getJogador();
    Venusiano *venusiano = new Venusiano(pos, pJogador);
    if (venusiano == nullptr)
    {
        std::cout << "nao foi possivel criar um Venusiano" << std::endl;
        exit(1);
    }
    listaPersonagens.inserir(static_cast<Entidade *>(venusiano));
}

void Fase::criarJogador(const sf::Vector2f pos)
{
    Jogador *jogador = new Jogador(pos);
    if (jogador == nullptr)
    {
        std::cout << "nao foi possivel criar um Jogador" << std::endl;
        exit(1);
    }
    GerenciadorEvento *pEvento = pEvento->getGerenciadorEvento();
    pEvento->setJogador(jogador);
    listaPersonagens.inserir(static_cast<Entidade *>(jogador));
}

void Fase::criarProjetil(const sf::Vector2f pos)
{
    GerenciadorEvento *pEvento = pEvento->getGerenciadorEvento();
    Jogador *pJogador = pEvento->getJogador();
    Projetil *projetil = new Projetil(pos, pJogador);
    if (projetil == nullptr)
    {
        std::cout << "nao foi possivel criar um Venusiano" << std::endl;
        exit(1);
    }
    listaPersonagens.inserir(static_cast<Entidade *>(projetil));
}

void Fase::criarEntidade(char letra, const sf::Vector2i pos)
{
    switch (letra)
    {
    case ('i'):
    {
        criaUraniano(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
    }
    break;
    case ('k'):
    {
        criaVerme(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
    }
    break;
    case ('l'):
    {
        criaVenusiano(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
    }
    break;
    case ('c'):
    {
        criarArvore(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
    }
    break;
    case ('#'):
    {
        criarPlataforma(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
    }
    break;
    case ('j'):
    {
        criarJogador(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
    }
    break;
    case ('r'):
    {
        criarRochas(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
    }
    break;
    case ('p'):
    {
        criarProjetil(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
    }
    break;
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
    // atualiza entidade e desenha
    desenhar();

    // verifica colisão
    pColisao->executar();
}