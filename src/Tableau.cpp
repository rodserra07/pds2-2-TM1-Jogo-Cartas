#include "Tableau.hpp"
#include <stdexcept>

//incia as 7 colunas vazia
Tableau::Tableau() {
    for (int i = 0; i < 7; i++){ _colunas.push_back(Coluna*());} }

Pilha& Tableau::get_coluna(int idx) {
    if (idx < 0 || idx >= 7){
        throw std::out_of_range("coluna invalida");
    }
    return _colunas[idx];
}
const Pilha& Tableau::get_coluna(int idx) const {
    if (idx < 0 || idx >= 7){
        throw std::out_of_range("coluna invalida");
    }
    return _colunas[idx];
} bool Tableau::valide_movimento(const Carta& c, int id_coluna) const {
    return get_coluna(id_coluna).pdp_receba(c);
}

void Tableau::mova_cartas(int og, int id, int nu) {
    get_coluna(og).transfira_para(get_coluna(id), nu);
}

void Tableau::revele_topo(int idx_coluna) {
    get_coluna(idx_coluna).revele_topo();
}