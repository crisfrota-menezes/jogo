#include "construtorEntidade.hpp"
#include "../Fases/fase.hpp"

ConstrutorEntidade::ConstrutorEntidade(Jogador *pJogador) : pJogador(pJogador)
{
}

ConstrutorEntidade::ConstrutorEntidade() : pJogador(nullptr)
{
}

ConstrutorEntidade::~ConstrutorEntidade()
{
}

void ConstrutorEntidade::verificaJogador()
{
    if (pJogador == nullptr)
    {
        throw "pJogador eh nullptr";
    }
}

Entidade *ConstrutorEntidade::criarPlataforma(const sf::Vector2f pos)
{
    Plataforma *plataforma = new Plataforma(pos);
    if (plataforma == nullptr)
    {
        cout << "Jungle::Construtor::ConstrutorFase::nao foi possivel criar uma plataforma" << endl;
        exit(1);
    }
    return static_cast<Entidade *>(plataforma);
}

Entidade *ConstrutorEntidade::criarRocha(const sf::Vector2f pos)
{
    Rochas *rocha = new Rochas(pos);
    if (rocha == nullptr)
    {
        cout << "nao foi possivel criar uma Rocha" << endl;
        exit(1);
    }
    return static_cast<Entidade *>(rocha);
}

Entidade *ConstrutorEntidade::criarUraniano(const sf::Vector2f pos)
{
    verificaJogador();
    Uraniano *uraniano = new Uraniano(pos, pJogador);
    if (uraniano == nullptr)
    {
        cout << "nao foi possivel criar um Uraniano" << endl;
        exit(1);
    }
    return static_cast<Entidade *>(uraniano);
}

Entidade *ConstrutorEntidade::criarJogador(const sf::Vector2f pos)
{
    Jogador *jogador = new Jogador(pos);
    if (jogador == nullptr)
    {
        cout << "nao foi possivel criar um Jogador" << endl;
        exit(1);
    }
    if (pJogador == nullptr)
    {
        pJogador = jogador;
    }
    return static_cast<Entidade *>(jogador);
}

Entidade *ConstrutorEntidade::criarVenusiano(const sf::Vector2f pos)
{
    verificaJogador();
    Venusiano *venusiano = new Venusiano(pos, pJogador);
    if (venusiano == nullptr)
    {
        cout << "nao foi possivel criar um Venusiano" << endl;
        exit(1);
    }
    return static_cast<Entidade *>(venusiano);
}
