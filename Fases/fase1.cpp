#include "fase1.hpp"

Fase1::Fase1() : Fase(IDs::IDs::fase_Fase1)
{
}

Fase1::~Fase1()
{
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