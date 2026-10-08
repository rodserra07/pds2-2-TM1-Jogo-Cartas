#ifndef FUNDACAO_HPP
#define FUNDACAO_HPP

#include "PilhaCartas.hpp"
#include <vector>

/**
 * @brief Gerencia as 4 pilhas organizadas por naipe e fiacam em ordem crescnete
 */
class Fundacao {
private:
    std::vector<PilhaCartas> _pilhas_naipe; 

public:
    Fundacao();

    /**
     * @brief Verifica se a carta é valida para entrar na pulha.
     * @param c Carta a ser inserida.
     * @return true se a pilha for vazia e for um Ás ou se a carta tiver mesmo naipe e valor maior que a do topo
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