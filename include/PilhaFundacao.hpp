#ifndef PILHA_FUNDACAO_HPP
#define PILHA_FUNDACAO_HPP

#include "Pilha.hpp"

/**
 * @brief Pilha de fundação.
 */
class PilhaFundacao : public Pilha{
    private:
    Naipe _naipe;
public:
/**
* @brief Pilha de fundação de um naipe
*/
PilhaFundacao(Naipe naipe);

/**
* @brief Retorna o naipe da pilha 
* @return naipe da pulha
*/
Naipe get_naipe() const;

    /**
     * @brief coloca a carta no topo da fundacao
     * @param c Carta que se quer colocar.
     */
    void add_carta(const Carta& c) override;
/**
     * @brief Diz se a carta pode ser colocada na fundacao
     * @param c Carta que se quer colocar.
     * @return true se c é do naipe e é o Ás ou tem valor +1 que o topo 
     */
    virtual bool pdp_receba(const Carta& c) const override;

    /**
     * @brief Mensagem que explica porque a carta foi recusada.
     * @return Texto com regra da fundacao
     */
    virtual std::string satisfacao() const override;
    /**
     * @brief Pontos que o jogador ganha
     * @return Pontos ganhos
     */
    int receba_pontos() const override;
};
#endif
