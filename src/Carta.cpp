#include "Carta.hpp"
#include <stdexcept>

//verifica se o valor da carta esta coerente com o baralho
Carta::Carta(int valor, Naipe naipe){
    if (valor < 1 || valor > 13){
        throw std::invalid_argument("valor da carta tem que ser coerente com o baralho(1 a 13)");
    }
    _valor = valor;
    _naipe = naipe;
    _visivel = false;

    //separa as cores vendo os naipe
    if(naipe == Naipe::COPAS || naipe == Naipe::OUROS){
        _cor = Cor::VERMELHO;
    } else{
        _cor = Cor::PRETO;
    }
}

//gets dos elementos da carta
int Carta::get_valor() const { return _valor; }
int Carta::get_naipe() const { return _naipe; }
int Carta::get_cor() const { return _cor; }
int Carta::get_visivel() const { return _visivel; }
void Carta::set_visivel(bool visivel) { _visivel = visivel; }
bool Carta::cor_diff(const Carta& outra) const { return _cor != outra._cor; }