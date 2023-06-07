#include "fase2.hpp"

Fase2::Fase2():
    Fase(IDs::IDs::fase_Fase2)
{

}

Fase2::~Fase2(){

}

void Fase2::criarMapa(){
    std::ifstream arquivo;
    std::string linha;
    arquivo.open("C:/Users/crisn/Desktop/SpaceHunt/Fases/mapa_fase2.txt");
    if(!arquivo.is_open()){
        std::cout << "Fase2::nao foi possivel abrir o arquivo" << std::endl;
        exit(1);
    }
    int j = 0;
    while(std::getline(arquivo, linha)){
        for(int i = 0; i < linha.size(); i++){
            if(linha[i] != ' '){
                criarEntidade(linha[i], sf::Vector2i(i, j));
            }
        }
        j++;
    }
    arquivo.close();
}