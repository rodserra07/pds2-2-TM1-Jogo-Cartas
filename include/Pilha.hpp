#ifndef PILHA_HPP
#define PILHA_HPP

#include "Carta.hpp"
#include <string>
#include <vector>

/**
 * @brief Manipular as pilhas de cartas.
 */
class Pilha {
protected:
    std::vector<Carta> _cartas; 

public:
    Pilha() = default;
    virtual ~Pilha() = default;

    /**
     * @brief Coloca uma carta no topo da pilha.
     * @param c Carta a ser inserida.
     */
    virtual void add_carta(const Carta& c);

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
     * @brief Retorna a carta de uma posição da pilha
     * @param indice Posição da carta.
     * @return Referência para a carta.
     */
    const Carta& get_carta(int indice) const;

    /**
     * @brief Remove todas as cartas da pilha.
     */
    void limpar();

    /**
     * @brief Move as qtd cartas do topo para outra pilha
     * @param destino Pilha que vai receber as cartas
     * @param qtd Quantidade de cartas a mover
     */
    void transfira_para(Pilha& destino, int qtd);

    /**
     * @brief Desvira a carta do topo
     */
    void esconda_topo();

    /**
     * @brief Diz se a carta pode ser colocada nessa pilha 
     */
    virtual bool pdp_receba(const Carta& c) const;

    /**
     * @brief Mensagem explicando por que a carta foi recusada.
     */
    virtual std::string satisfacao() const;

    /**
     * @brief Diz se o jogador pode tirar qtd cartas do topo dessa pilha.
     * Na Pilha comum só dá pra tirar 1 carta, e ela precisa estar virada pra cima.
     */
    virtual bool pdp_retire(int qtd) const;

    /**
     * @brief Pontos que o jogador ganha
     */
    virtual int receba_pontos() const;

    /**
     * @brief Vira a carta do topo pra cima, se for a regra dessa pilha.
     * @return true se alguma carta foi virada.
     */
    virtual bool revele_topo();
};

#endif
