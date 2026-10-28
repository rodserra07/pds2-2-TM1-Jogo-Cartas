#include "Pilha.hpp"
#include <stdexcept>

//adicina a carta no topo 
void Pilha::add_carta(const Carta& c) { _cartas.push_back(c);}

//devolve a carta do topo
Carta Pilha::remover_topo(){
    if(_cartas.empty()){

     throw std::out_of_range("pilha vazia, nem tem o que remover");
    } Carta topo = _cartas.back(); _cartas.pop_back(); return topo; }

// da uma bisoiada na carta do topo sem mexer
const Carta& Pilha::ver_topo() const{
if(_cartas.empty()){

     throw std::out_of_range("pilha vazia, nem tem o que remover");
    } return _cartas.back(); }

bool Pilha::esta_vazia() const {return _cartas.empty();}
int Pilha::get_quantidade() const {return static_cast<int>(_cartas.size());}

const Carta& Pilha::get_carta(int indice) const {
    if(indice < 0 || indice >= get_quantidade()){
         throw std::out_of_range("indice de carta invalido");
    }
    return _cartas[indice];
}

void Pilha::limpar() { _cartas.clear(); }

//move as cartas do topo para outra pilha
void Pilha::transfira_para(Pilha& destino, int qtd) {
    if (&destino == this){
        throw std::invalid_argument("origem e destino sao a mesma pilha");
    }

    //retira as cartas de forma inversa e as coloca de traz pra frente
   std::vector<Carta> temporarias;
    for (int i = 0; i < qtd; i++){
        temporarias.push_back(remover_topo());
    } 
     for (int i = qtd - 1; i >= 0; i--){
        destino.add_carta(temporarias[i]);
     }
}

//desvira a carta do topo
void Pilha::esconda_topo() {
    if (!_cartas.empty()){
        _cartas.back().set_visivel(false);
    }
}

//pilha aceita qualquer coisa
bool Pilha::pdp_receba(const Carta& c) const { return true;
}

std::string Pilha::satisfacao() const {
        return "Essa pilha nao aceita essa carta.";
}

//tira so uma carta virada para cima
bool Pilha::pdp_retire(int qtd) const {
 return qtd == 1 && !_cartas.empty() && _cartas.back().visivel();
}

int Pilha::receba_pontos() const {


    return 0;
}

//pilha nao pode sair do armario
bool Pilha::revele_topo() {
    return false;
}
