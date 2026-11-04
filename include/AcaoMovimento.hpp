#ifndef ACAO_MOVIMENTO_HPP
#define ACAO_MOVIMENTO_HPP

#include "Carta.hpp"

//criei esse hpp pra deixar o Mover.hpp apenas com uma classe
/**
 * @brief Guarda cada movimento ralizado, permitindo desfazer a ação com um undo
 */
struct AcaoMovimento {
    int origem;
    int destino;
    Carta carta_movida;
    bool carta_revelada;
    int quantidade;
    int pontos;
};

#endif
