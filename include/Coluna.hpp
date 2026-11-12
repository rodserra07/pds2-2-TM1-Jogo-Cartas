#ifndef COLUNA_HPP
#define COLUNA_HPP
#include "Pilha.hpp"

/**
 * @brief As colunas do tableau
 *
 * Aceita ou recusa uma carta dependendo se ela cumpre os pre-requisitos
 * Dá pra mover um grupo de cartas.
 */
class Coluna : public Pilha
{
public:
    /**
     * @brief Diz se a carta pode ser colocada nessa pilha
     * @param c Carta que se quer colocar.
     * @return true se coluna ta vazia e c for um rei, ou se c tem valor uma unidade menor que o topo e cor diferente
     */
    virtual bool pdp_receba(const Carta &c) const override;

    /**
     * @brief Mensagem que explica porque a carta foi recusada.
     * @return Texto com a regra da coluna
     */
    virtual std::string satisfacao() const override;

    /**
     * @brief Diz se o jogador pode tirar qtd cartas do topo dessa pilha.
     * @param qtd quantidade de carta
     * @return true se qtd estiver coerente, cartas viradas pra cima em sequencia decrescente e cor alternada
     */
    virtual bool pdp_retire(int qtd) const override;

    /**
     * @brief Vira a carta do topo pra cima, se for a regra dessa pilha.
     * @return true se alguma carta foi virada.
     */
    virtual bool revele_topo() override;
};
#endif