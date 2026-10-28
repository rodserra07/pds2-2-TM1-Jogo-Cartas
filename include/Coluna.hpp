#ifndef COLUNA_HPP
#define COLUNA_HPP
#include "Pilha.hpp"

/**
 * @brief As colunas do tableau
 *
 * Aceita ou recusa uma carta dependendo se ela cumpre os pre-requisitos
 * Dá pra mover um grupo de cartas.
 */
class Coluna : public Pilha {
    public:
    bool pdp_receba(const Carta& c) const override; 
    std::string satisfacao() const override;


/**
 * @brief Permite retirar as cartas da pilha caso cumpra as restrições
 * Pode tirar as cartas em sequencia
 */
bool pdp_retire(int qtd) const override;

/**
 * @brief Revela a carta do topo caso esteja pra baixo
 */
bool revele_topo() override;
};
#endif