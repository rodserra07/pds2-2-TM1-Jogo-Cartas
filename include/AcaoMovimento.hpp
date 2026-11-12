#ifndef GERENCIAR_HISTORICO
#define GERENCIAR_HISTORICO

#include "Carta.hpp"

// criei esse hpp pra deixar o Historico.hpp apenas com uma classe
/**
 * @brief Guarda cada movimento realizado, permitindo desfazer a ação com um undo
 */
struct AcaoMovimento
{
    int origem;          ///< Código da pilha de origem
    int destino;         ///< Código da pilha de destino
    Carta carta_movida;  ///< Carta que foi movida
    bool carta_revelada; ///< Indica se a carta foi virada ou nao
    int quantidade;      ///< Quantidade de cartas movidas
    int pontos;          ///< Pontos obtidos com o movimento
};

#endif
