#include "fase1.hpp"

Fase1::Fase1() : Fase(IDs::IDs::fase_Fase1, IDs::IDs::fundo_Fase1)
{
}

Fase1::~Fase1()
{
}

void Fase1::criarFundo()
{
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada1.png", 0.0f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada2.png", 0.0f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada3.png", 0.1f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada4.png", 0.2f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada5.png", 0.3f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada6.png", 0.5f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada7.png", 0.75f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada8.png", 1.5f);
}

void Fase1::criarMapa()
{
    std::ifstream arquivo;
    std::string linha;
    arquivo.open("C:/Users/crisn/Desktop/SpaceHunt/Fases/mapa_Fase1.txt");
    if (!arquivo.is_open())
    {
        std::cout << "Fase1::nao foi possivel abrir o arquivo" << std::endl;
        exit(1);
    }
    int j = 0;
    while (std::getline(arquivo, linha))
    {
        for (int i = 0; i < linha.size(); i++)
        {
            if (linha[i] != ' ')
            {
                criarEntidade(linha[i], sf::Vector2i(i, j));
            }
        }
        j++;
    }
    arquivo.close();
}