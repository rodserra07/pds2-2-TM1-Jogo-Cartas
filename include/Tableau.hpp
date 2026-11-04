#ifndef TABLEAU_HPP
#define TABLEAU_HPP

#include "Coluna.hpp"
#include <vector>

/**
 * @brief Gerencia as 7 colunas principais do tabuleiro
 */
class Tableau {
private:
    std::vector<Coluna> _colunas;

public:
    Tableau();

    /**
     * @brief Valida se a carta pode ser movida para a coluna desejada.
     * @param c Carta a ser movida.
     * @param id_coluna Indica o endereço da coluna onde a carta vai.
     * @return true se for valido
     * @throws std::out_of_range se o indice for invalide
     */
    bool valide_movimento(const Carta& c, int id_coluna) const;

    /**
     * @brief Move uma carta ou mais de uma coluna pra outra.
     * @param og Coluna de origem.
     * @param id Coluna de destino.
     * @param nu Quantidade de cartas a mover.
     * @throws std::out_of_range se o indice for invalide
     * @throws std::invalid_argument se qtd invalida ou origem e destino iguais
     */
    void mova_cartas(int og, int id, int nu);

    /**
     * @brief Vira a carta do topo da coluna para cima se estiver oculta.
     * @param id_coluna Índice da coluna.
     * @throws std::out_of_range se o indice for invalide
     */
    void revele_topo(int idx_coluna);

    /**
     * @brief Acessa uma coluna do tabuleiro
     * @param idx indice da coluna
     * @return referencia da coluna
     * @throws std::out_of_range se o indice for invalide
     */
    Pilha& get_coluna(int idx);

    /**
     * @brief Acessa uma coluna do tabuleiro sem possibilidade de alterar
     * @param idx indice da coluna
     * @return referencia da coluna
     * @throws std::out_of_range se o indice for invalide
     */
    const Pilha& get_coluna(int idx) const;
};

#endif