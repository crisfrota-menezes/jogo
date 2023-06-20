#include "menuPrincipal.hpp"

MenuPrincipal::MenuPrincipal() : Menu(IDs::IDs::menuPrincipal, sf::Vector2f(TAM_BOTAO_X, TAM_BOTAO_Y)), sair(false), obsMenuPrincipal(new ObservadorMenuPrincipal(this))
{
    if (obsMenuPrincipal == nullptr)
    {
        cout << "nao foi possivel criar o observador do menu principal" << endl;
    }
    criarFundo();
    criarBotoes();
    it = botoes.begin();
    (*it)->setSelecionado(true);
}

MenuPrincipal::~MenuPrincipal()
{
    if (obsMenuPrincipal)
    {
        delete obsMenuPrincipal;
        obsMenuPrincipal = nullptr;
    }
}

void MenuPrincipal::criarFundo()
{
    textura = pGrafico->carregarTextura(CAMINHO_TEXTURA_MP);
    fundo.setTexture(&textura);
}

void MenuPrincipal::criarBotoes()
{
    const float posBotaoX = tamJanela.x / 2.0f - tamBotao.x / 2.0f;
    addBotao("Novo", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f), IDs::IDs::novo_jogo);
    addBotao("Carregar", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 1.2f), IDs::IDs::carregar_jogo);
    addBotao("Ranking", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 2.4f), IDs::IDs::ranking);
    addBotao("Opcoes", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 3.6f), IDs::IDs::opcoes);
    addBotao("Sair", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 4.8f), IDs::IDs::sair);
}

void MenuPrincipal::setSair(const bool sair)
{
    this->sair = sair;
}

const bool MenuPrincipal::getSair() const
{
    return sair;
}

void MenuPrincipal::selecionaUp()
{
    Botao *botao = *it;
    botao->setSelecionado(false);
    if (it == botoes.begin())
    {
        it = botoes.end();
    }
    it--;
    botao = *it;
    botao->setSelecionado(true);
}

void MenuPrincipal::selecionaDown()
{
    Botao *botao = *it;
    botao->setSelecionado(false);
    it++;
    if (it == botoes.end())
    {
        it = botoes.begin();
    }
    botao = *it;
    botao->setSelecionado(true);
}

const IDs::IDs MenuPrincipal::getBotaoSelecionado() const
{
    std::list<Botao *>::const_iterator aux;
    for (aux = botoes.begin(); aux != botoes.end(); aux++)
    {
        Botao *botao = *aux;
        if (botao->getSelecionado())
        {
            return botao->getID();
        }
    }
    return IDs::IDs::vazio;
}

void MenuPrincipal::executar()
{
    desenhar();
}
