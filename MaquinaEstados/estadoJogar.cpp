#include "estadoJogar.hpp"

EstadoJogar::EstadoJogar(Fase *fase) : Estado(fase->getID()), fase(fase)
{
}

EstadoJogar::~EstadoJogar()
{
}

/*
void EstadoJogar::desenhar(){
    fase->desenhar();
}
*/

void EstadoJogar::executar()
{
    fase->executar();
    // desenhar();
}