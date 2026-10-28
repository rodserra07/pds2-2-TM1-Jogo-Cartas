#ifndef DESCARTE_HPP
#define DESCARTE_HPP

#include "Pilha.hpp"

/**
 * @brief Pilha de descarte onde vao as cartas compradas pelo estoque
 * Sempre visivel e apenas a carta de cima pode ser jogada
 */
class Descarte : public Pilha {
    public:
    void add_carta(const Carta& c) override;
bool pdp_receba(const Carta& c) const override;
    std::string satisfacao() const override;
};
#endif