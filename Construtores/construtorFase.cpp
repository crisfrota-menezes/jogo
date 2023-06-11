#include "construtorFase.hpp"

ConstrutorFase::ConstrutorFase()
{
}

ConstrutorFase::~ConstrutorFase()
{
}

Entidade *ConstrutorFase::criarPlataforma(const sf::Vector2f pos)
{
    Plataforma *plataforma = new Plataforma(pos);
    if (plataforma == nullptr)
    {
        cout << "nao foi possivel criar uma plataforma" << endl;
        exit(1);
    }
    return static_cast<Entidade *>(plataforma);
}

Entidade *ConstrutorFase::criarRocha(const sf::Vector2f pos)
{
    Rochas *rochas = new Rochas(pos);
    if (rochas == nullptr)
    {
        cout << "nao foi possivel criar uma Rochas" << endl;
        exit(1);
    }
    return static_cast<Entidade *>(rochas);
}

Entidade *ConstrutorFase::criarUraniano(const sf::Vector2f pos)
{
    GerenciadorEvento *pEvento = pEvento->getGerenciadorEvento();
    Jogador *pJogador = pEvento->getJogador();
    Uraniano *uraniano = new Uraniano(pos, pJogador);
    if (uraniano == nullptr)
    {
        cout << "nao foi possivel criar um Uraniano" << endl;
        exit(1);
    }
    return static_cast<Entidade *>(uraniano);
}

Entidade *ConstrutorFase::criarJogador(const sf::Vector2f pos)
{
    Jogador *jogador = new  Jogador(pos);
    if (jogador == nullptr)
    {
        cout << "nao foi possivel criar um Jogador" << endl;
        exit(1);
    }
    GerenciadorEvento *pEvento = pEvento->getGerenciadorEvento();
    pEvento->setJogador(jogador);
    return static_cast<Entidade *>(jogador);
}

Entidade *ConstrutorFase::criarVenusiano(const sf::Vector2f pos)
{
    GerenciadorEvento *pEvento = pEvento->getGerenciadorEvento();
    Jogador *pJogador = pEvento->getJogador();
    Venusiano *venusiano = new Venusiano(pos, pJogador);
    if (venusiano == nullptr)
    {
        cout << "nao foi possivel criar um Venusiano" << endl;
        exit(1);
    }
    return static_cast<Entidade *>(venusiano);
}

Entidade *ConstrutorFase::criarArvore(const sf::Vector2f pos)
{
    Arvore *arvore = new Arvore(pos);
    if (arvore == nullptr)
    {
        cout << "nao foi possivel criar uma plataforma" << endl;
        exit(1);
    }
    return static_cast<Entidade *>(arvore);
}