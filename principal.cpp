
#include "principal.hpp"

Jogo::Jogo() : pGrafico(pGrafico->getGerenciadorGrafico()), pEvento(pEvento->getGerenciadorEvento()), fase(nullptr)
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

    //criarMenu();
    criarFase();
    run();
}

Jogo::~Jogo()
{
    if (fase)
    {
        delete fase;
        fase = nullptr;
    }
}

void Jogo::criarMenu()
{
    MenuPrincipal *aux = new MenuPrincipal();
    if (aux == nullptr)
    {
        cout << "Erro ao criar o menu" << endl;
        exit(1);
    }
    menu = static_cast<MenuPrincipal *>(aux);
}

void Jogo::criarFase()
{
    Fase1 *aux = new Fase1();
    if (aux == nullptr)
    {
        cout << "Erro ao criar a fase" << endl;
        exit(1);
    }
    fase = static_cast<Fase *>(aux);
    fase->criarFundo();
    fase->criarMapa();
}

void Jogo::run()
{
    try
    {
        //bool controle = false;
        while (pGrafico->janelaAberta())
        {
            //controle = menu->run();
            //if (controle)
            //{
                //delete menu;
                //menu = nullptr;
                pEvento->executar();
                pGrafico->limpar();
                fase->executar();
                pGrafico->mostraElementos();
            //}
            /*if(fase->concluida())
            {
                cout << "Fase concluida" << endl;
                exit(1);
            }*/
        }
    }
    catch (const char *msg)
    {
        cout << "SUPER ERRO" << endl;
    }
}