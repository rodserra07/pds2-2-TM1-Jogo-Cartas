#ifndef PILHA_HPP
#define PILHA_HPP

#include "Carta.hpp"
#include <vector>

/**
 * @brief Manipular as pilhas de cartas.
 */
class PilhaCartas {
protected:
    std::vector<Carta> _cartas; 

public:
    PilhaCartas() = default;
    virtual ~PilhaCartas() = default;

    /**
     * @brief Coloca uma carta no topo da pilha.
     * @param c Carta a ser inserida.
     */
    virtual void adicionar_carta(const Carta& c);

    /**
     * @brief Tira a carta do topo da pilha.
     * @return Carta removida do topo.
     */
    Carta remover_topo();

    /**
     * @brief Retorna uma referência para a carta do topo sem removê-la.
     * @return Referência da carta do topo.
     */
    const Carta& ver_topo() const;

    /**
     * @brief Verifica se a pilha está vazia.
     * @return true se não houver cartas na pilha, false caso contrário.
     */
    bool esta_vazia() const;

    /**
     * @brief Retorna a quantidade de cartas atualmente na pilha.
     * @return Número total de cartas.
     */
    int get_quantidade() const;

    /**
     * @brief Remove todas as cartas da pilha.
     */
    void limpar();
};

#endif