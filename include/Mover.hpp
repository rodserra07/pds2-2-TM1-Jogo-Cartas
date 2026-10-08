#ifndef MOVER_HPP
#define MOVER_HPP

#include "Carta.hpp"
#include <stack>

/**
 * @brief Guarda cada movimento ralizado, permitindo desfazer a ação com um undo
 */
struct AcaoMovimento {
    int origem;
    int destino;
    Carta carta_movida;
    bool carta_revelada;
};

/**
 * @brief Gerenciador do historico
 */
class GerenciadorMovimento {
private:
    std::stack<AcaoMovimento> _historico; 

public:
    GerenciadorMovimento() = default;

    /**
     * @brief Registra a ação feita no historioc
     * @param acao Dados do movimento feito.
     */
    void registrar_acao(const AcaoMovimento& acao);

    /**
     * @brief Faz o undo, revertendo a ultima ação feita.
     * @return true se havia movimento para desfazer.
     */
    bool desfazer_ultimo_movimento();

    void limpar_historico();
};

#endif