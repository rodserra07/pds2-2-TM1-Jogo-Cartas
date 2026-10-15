#ifndef FUNDACAO_HPP
#define FUNDACAO_HPP

#include "Pilha.hpp"
#include <vector>

/**
 * @brief Gerencia as 4 pilhas organizadas por naipe e fiacam em ordem crescnete
 */
class Fundacao {
private:
    std::vector<Pilha> _pilhas_naipe; 

public:
    Fundacao();

    /**
     * @brief Verifica se a carta é valida para entrar na pulha.
     * @param c Carta a ser inserida.
     * @return  @return true se a pilha estiver vazia e a carta for um Ás, ou se tiver o mesmo naipe e valor igual ao do topo + 1.
     */
    bool validar_insercao(const Carta& c) const;

    /**
     * @brief Insere a carta na pilha correspondente.
     * @param c Carta a ser inserida.
     */
    void inserir_carta(const Carta& c);

    /**
     * @brief Verifica se as 4 fundações foram completa.
     * @return true em caso de vitória.
     */
    bool jogo_ganho() const;
};

#endif