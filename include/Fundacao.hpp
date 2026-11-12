#ifndef FUNDACAO_HPP
#define FUNDACAO_HPP

#include "PilhaFundacao.hpp"
#include <vector>

/**
 * @brief Gerencia as 4 pilhas organizadas por naipe e em ordem crescente.
 */
class Fundacao
{
private:
    std::vector<PilhaFundacao> _pilhas_naipe; ///< vetor de pilhas de fundação, uma para cada naipe

public:
    /**
     * @brief Construtor da fundaçao
     */
    Fundacao();
    
    /**
     * @brief Verifica se as 4 fundações foram completa.
     * @return true se as 4 pilhas tem 13 cartas do naipe
     */
    bool gg() const;

    /**
     * @brief Acessa a pilha de fundação de um naipe
     * @param naipe Naipe desejado.
     * @return referencia para a pilha do naipe
     */
    Pilha &get_pilha(Naipe naipe);

    /**
     * @brief Acessa a pilha de fundação de um naipe, mas sem possibilidade de alterar
     * @param naipe Naipe desejado.
     * @return referencia para a pilah do naipe
     */
    const Pilha &get_pilha(Naipe naipe) const;
};
#endif