#include "Descarte.hpp"

//coloca a carta no descarte
void Descarte::add_carta(const Carta& c) {
    Carta copia = c;
    copia.set_visivel(true);
    Pilha::add_carta(copia);
}

//descarte nao recebe cartas assim, apenas pelo estoque
bool Descarte::pdp_receba(const Carta& c) const {
    return false;
}

std::string Descarte::satisfacao() const {
    return "Nao é possivel colocar cartas diretamente no descarte colega.";
}