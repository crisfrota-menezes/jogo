
#include "principal.hpp"

Jogo::Jogo() : pGrafico(pGrafico->getGerenciadorGrafico()), pEvento(pEvento->getGerenciadorEvento()), pGerenciadorEstado(pGerenciadorEstado->getGerenciadorEstado())
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

    //criarFase();
    if(pGerenciadorEstado == nullptr){
        cout << "nao foi possivel criar um GerenciadorEstado" << endl;
        exit(1);
    }
    pGerenciadorEstado->addEstado(IDs::IDs::jogar_Fase1);
    run();
}

Jogo::~Jogo()
{
    /*if (fase)
    {
        delete fase;
        fase = nullptr;
    }*/
}

/*void Jogo::criarMenu()
{
    MenuPrincipal *aux = new MenuPrincipal(pGrafico, this);
    if (aux == nullptr)
    {
        cout << "Erro ao criar o menu" << endl;
        exit(1);
    }
}*/

/*void Jogo::criarFase()
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
}*/

void Jogo::run()
{
    try
    {
       //bool controle = true;
       //criarMenu();
        while (pGrafico->janelaAberta())
        {
            //controle = 
            //menu->run();
            //if (controle)
            //{
                pEvento->executar();
                pGrafico->limpar();
                //fase->executar();
                pGerenciadorEstado->executar();
                pGrafico->mostraElementos();
            //}
            /*if(fase->concluida())
            {
                cout << "Fase concluida" << endl;
                exit(1);
            }*/
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}