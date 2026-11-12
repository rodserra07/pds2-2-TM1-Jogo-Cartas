#ifndef TABLEAU_HPP
#define TABLEAU_HPP

#include "Coluna.hpp"
#include <vector>

/**
 * @brief Gerencia as 7 colunas principais do tabuleiro
 */
class Tableau
{
private:
    std::vector<Coluna> _colunas; ///< vetor das 7 colunas do tabuleiro

public:
    /**
     * @brief Construtor do tableau
     */
    Tableau();

    /**
     * @brief Acessa uma coluna do tabuleiro
     * @param idx indice da coluna
     * @return referencia da coluna
     * @throws std::out_of_range se o indice for invalide
     */
    Pilha &get_coluna(int idx);

    /**
     * @brief Acessa uma coluna do tabuleiro sem possibilidade de alterar
     * @param idx indice da coluna
     * @return referencia da coluna
     * @throws std::out_of_range se o indice for invalide
     */
    const Pilha &get_coluna(int idx) const;
};

#endif