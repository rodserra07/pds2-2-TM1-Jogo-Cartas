#include "Fundacao.hpp"
#include <stdexcept>

//uma pilha por naipe
Fundacao::Fundacao() {
    _pilhas_naipe.push_back(PilhaFundacao(Naipe::PAUS));
    _pilhas_naipe.push_back(PilhaFundacao(Naipe::COPAS));
    _pilhas_naipe.push_back(PilhaFundacao(Naipe::ESPADAS));
    _pilhas_naipe.push_back(PilhaFundacao(Naipe::OUROS));
}
Pilha& Fundacao::get_pilha(Naipe naipe) { return _pilhas_naipe[static_cast<int>(naipe)]; }

const Pilha& Fundacao::get_pilha(Naipe naipe) const { return _pilhas_naipe[static_cast<int>(naipe)]; }

//retorna se a a carta entra ou nao na pilha
bool Fundacao::valide_insira(const Carta& c) const {
    return get_pilha(c.get_naipe()).pdp_receba(c);
}

void Fundacao::insira_carta(const Carta& c) {if (!valide_insira(c)){
    throw std::invalid_argument("essa carta nao encaixa aqui nao galego");
}
    get_pilha(c.get_naipe()).add_carta(c);
}

//verifica se as pilah tao completa e declara a win
bool Fundacao::gg() const {
    for (int i = 0; i < 4; i++) {
        if (_pilhas_naipe[i].get_quantidade() != 13) {
            return false;
        }
    }
    return true;
}