#include "Coluna.hpp"

//verifica se carta pode ser colocada na coluna
bool Coluna::pdp_receba(const Carta& c) const {
    if (_cartas.empty()){ return c.get_valor() == 13; }
// verifica se o valor da carta é -1 a do topo e se a cor é diferente, pra validar a entrada
const Carta& topo = _cartas.back(); 
return c.get_valor() == topo.get_valor() - 1 && c.cor_diff(topo); }

std::string Coluna::satisfacao() const{
    if(_cartas.empty()){ return "A coluna esta vazia, precisa de um rei para inicia-la"; }
    return "A carta precisa de um valor uma unidade inferior ao topo e de cor oposta";
}

//verifica se a quantidade de cartas a serem retiradas é coerente com a quantidade disponivel
bool Coluna::pdp_retire(int qtd) const{
    int total = get_quantidade();
    if (qtd < 1 || qtd > total){
        return false;
    }

    int primeiro = total - qtd;

    //verifica se as cartas estao visiveis antes de retirar
    for (int i = primeiro; i < total; i++){
        if (!_cartas[i].visivel()){
    return false;
        }
    }
    //verifica se as cartas estao em sequencia alternada de cor e numericamente decrescnete
    for(int i = primeiro; i < total - 1; i++){
        if(_cartas[i].get_valor() != _cartas[i + 1].get_valor() + 1 || !_cartas[i].cor_diff(_cartas[i + 1])){
            return false;
        }
        if (!_cartas[i].cor_diff(_cartas[i + 1])){
            return false;
        }
    }
    return true;
}

// revela a carta do topo da coluna
bool Coluna::revele_topo() {
    if (!_cartas.empty() && !_cartas.back().visivel()) {
        _cartas.back().set_visivel(true);
        return true;
    }
    return false;
}
