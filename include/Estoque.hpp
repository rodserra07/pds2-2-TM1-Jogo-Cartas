#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP 
#include "Pilha.hpp"

/**
 * @brief Pilha de compra
 */
class Estoque : public Pilha {
    public:
    void add_carta(const Carta& c) override;
    bool pdp_receba(const Carta& c) const override;
    std::string satisfacao() const override;
    bool pdp_retire(int qtd) const override;
};
#endif