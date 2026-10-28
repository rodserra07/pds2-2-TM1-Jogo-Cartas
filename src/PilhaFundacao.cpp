#include "PilhaFundacao.hpp"

PilhaFundacao::PilhaFundacao(Naipe naipe) : _naipe(naipe){

}
//aqui cartas sempre reveladas
void PilhaFundacao::add_carta(const Carta& c){
    Carta copia = c;
    copia.set_visivel(true);
    Pilha::add_carta(copia);
}

//primeiro o AS e depois crescente do Naipe
bool PilhaFundacao::pdp_receba(const Carta& c) const {
    if (c.get_naipe() != _naipe){ return false;
    } if(_cartas.empty()){ return c.get_valor() == 1;}
    return c.get_valor() == _cartas.back().get_valor() + 1;
}
 std::string PilhaFundacao::satisfacao() const {
    return "A fundacao so aceita o As e depois as cartas do mesmo naipe em ordem crescente";
}

int PilhaFundacao::receba_pontos() const {
    return 10;
}