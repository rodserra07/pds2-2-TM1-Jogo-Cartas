#ifndef TABLEAU_HPP
#define TABLEAU_HPP

#include "Pilha.hpp"
#include <vector>

/**
 * @brief Gerencia as 7 colunas principais do tabuleiro.
 */
class Tableau {
private:
    std::vector<PilhaCartas> _colunas;

public:
    Tableau();

    /**
     * @brief Valida se a carta pode ser movida para a coluna desejada.
     * @param c Carta a ser movida.
     * @param id_coluna Indica o endereço da coluna onde a carta vai.
     * @return true se o movimento respeitar as regras de validade.
     */
    bool validar_movimento(const Carta& c, int id_coluna) const;

    /**
     * @brief Move uma carta ou mais de uma coluna pra outra.
     * @param og Coluna de origem.
     * @param id Coluna de destino.
     * @param nu Quantidade de cartas a mover.
     */
    void mover_cartas(int og, int id, int nu);

    /**
     * @brief Vira a carta do topo da coluna para cima se estiver oculta.
     * @param id_coluna Índice da coluna.
     */
    void revelar_topo(int idx_coluna);

    PilhaCartas& get_coluna(int idx);
};

#endif