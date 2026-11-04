#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP 
#include "Pilha.hpp"

/**
 * @brief Pilha de compra
 */
class Estoque : public Pilha {
    public:
    /**
     * @brief coloca a carta no topo do estoque
     * @param c Carta que se quer colocar.
     */
    void add_carta(const Carta& c) override;
/**
     * @brief Diz se a carta pode ser colocada nessa pilha 
     * @param c Carta que se quer colocar.
     * @return sempre false
     */
    virtual bool pdp_receba(const Carta& c) const override;

    /**
     * @brief Mensagem que explica porque a carta foi recusada.
     * @return Texto que avisa que nao se pode colocar cartas no estoque
     */
    virtual std::string satisfacao() const override;

    /**
     * @brief Diz se o jogador pode tirar qtd cartas do topo dessa pilha.
     * @param qtd quantidade de carta
     * @return sempre false
     */
    virtual bool pdp_retire(int qtd) const override;
};
#endif