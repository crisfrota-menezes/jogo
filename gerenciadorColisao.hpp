#pragma once

#include "Personagem.hpp"
#include <vector>

class GerenciadorColisao
{
private:
    std::vector<Entidades::Personagem::Personagem *> personagens;
    
public:
    GerenciadorColisao();
    ~GerenciadorColisao();
    void adicionarPersonagem(Entidades::Personagem::Personagem *personagem);
    void checarColisao();
};