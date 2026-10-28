#include "Estoque.hpp"

//coloca a carta no estoque
void Estoque::add_carta(const Carta& c) {
Carta copia = c;
copia.set_visivel(false);
Pilha::add_carta(copia);
}

//estoque nao recebe cartas de forma convencional
bool Estoque::pdp_receba(const Carta& c) const {
    return false;

} std::string Estoque::satisfacao() const {
    return "Nao é possivel colocar cartas no estoque";
}

//jogado so cxompra
bool Estoque::pdp_retire(int qtd) const {
    return false;
}