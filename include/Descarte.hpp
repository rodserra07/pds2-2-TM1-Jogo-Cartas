#ifndef DESCARTE_HPP
#define DESCARTE_HPP

#include "Pilha.hpp"

/**
 * @brief Pilha de descarte onde vao as cartas compradas pelo estoque
 * Sempre visivel e apenas a carta de cima pode ser jogada
 */
class Descarte : public Pilha
{
public:
    /**
     * @brief coloca a carta no topo do descarte
     * @param c Carta que se quer colocar.
     */
    void add_carta(const Carta &c) override;
    /**
     * @brief Diz se a carta pode ser colocada nessa pilha
     * @param c Carta que se quer colocar.
     * @return sempre falso
     */
    virtual bool pdp_receba(const Carta &c) const override;

    /**
     * @brief Mensagem que explica porque a carta foi recusada.
     * @return Texto que fala que nao da pra colocar cartas no descarte
     */
    virtual std::string satisfacao() const override;
};
#endif