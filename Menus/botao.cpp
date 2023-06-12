#include "botao.hpp"

Botao::Botao(const std::string texto) : Ente(IDs::IDs::botao), caixaTexto(pGrafico->carregarFonte(CAMINHO_FONTE), texto)
{
}

Botao::~Botao()
{
}

void Botao::desenhar()
{
    pGrafico->desenhaElemento(caixa);
    pGrafico->desenhaElemento(caixaTexto.getTexto());
}
