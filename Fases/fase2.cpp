#include "fase2.hpp"

Fase2::Fase2() : Fase(IDs::IDs::fase_Fase2, IDs::IDs::fundo_Fase2)
{
}

Fase2::~Fase2()
{
}

void Fase2::criarFundo()
{
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada1.png", 0.0f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada2.png", 0.1f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada3.png", 0.2f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada4.png", 0.3f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada5.png", 0.4f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada6.png", 0.5f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada7.png", 0.6f);
    fundo.addCamada("C:/Users/crisn/Desktop/SpaceHunt/Midia/camada8.png", 0.7f);
}

void Fase2::criarMapa()
{
    std::ifstream arquivo;
    std::string linha;
    arquivo.open("C:/Users/crisn/Desktop/SpaceHunt/Fases/mapa_fase2.txt");
    if (!arquivo.is_open())
    {
        std::cout << "Fase2::nao foi possivel abrir o arquivo" << std::endl;
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