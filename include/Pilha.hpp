#ifndef PILHA_HPP
#define PILHA_HPP

#include "Carta.hpp"
#include <string>
#include <vector>

/**
 * @brief Manipular as pilhas de cartas.
 *
 * por padrão acerta qualquer carta e so deixa retirar uma carta
 * Coluna, Estoque, Descarte e PilhaFundacao sobrescrevem os metodos virtuais(polimorfismo)
 */
class Pilha {
protected:
    std::vector<Carta> _cartas; 

public:
    Pilha() = default;
    virtual ~Pilha() = default;

    /**
     * @brief Coloca uma carta no topo da pilha.
     * pode(spoiler:vai) ser sobreescrita pelas classes filhas
     * @param c Carta a ser inserida.
     */
    virtual void add_carta(const Carta& c);

    /**
     * @brief Tira a carta do topo da pilha.
     * @return Carta removida do topo.
     * @throws std::out_of_range se a pilha ta fazia
     */
    Carta remover_topo();

    /**
     * @brief Retorna uma referência para a carta do topo sem removê-la.
     * @return Referência da carta do topo.
     * @throws std::out_of_range se a pilha ta fazia
     */
    const Carta& ver_topo() const;

    /**
     * @brief Verifica se a pilha está vazia.
     * @return true se não houver cartas na pilha false caso contrário.
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
     * @throws std::out_of_range se o indice tiver errado
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
     * @throws std::invalid_argument se destino for a própria pilha, ou se qtd  for menor que 1 ou maior que a quantidade de cartas da pilha.
     *        
     */
    void transfira_para(Pilha& destino, int qtd);

    /**
     * @brief Desvira a carta do topo
     */
    void esconda_topo();

    /**
     * @brief Diz se a carta pode ser colocada nessa pilha 
     * @param c Carta que se quer colocar.
     * @return true se a pilha aceita a carta
     */
    virtual bool pdp_receba(const Carta& c) const;

    /**
     * @brief Mensagem que explica porque a carta foi recusada.
     * @return Texto com a regra da pilha
     */
    virtual std::string satisfacao() const;

    /**
     * @brief Diz se o jogador pode tirar qtd cartas do topo dessa pilha.
     * @param qtd quantidade de carta
     * @return true se ta podendo retira
     */
    virtual bool pdp_retire(int qtd) const;

    /**
     * @brief Pontos que o jogador ganha
     * @return Pontos ganhos
     */
    virtual int receba_pontos() const;

    /**
     * @brief Vira a carta do topo pra cima, se for a regra dessa pilha.
     * @return true se alguma carta foi virada.
     */
    virtual bool revele_topo();
};

#endif
