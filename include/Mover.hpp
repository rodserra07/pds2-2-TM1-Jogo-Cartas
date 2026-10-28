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
    int quantidade;
    int pontos;
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
    void registre_acao(const AcaoMovimento& acao);

    /**
     * @brief Faz o undo, revertendo a ultima ação feita.
     * @return true se havia movimento para desfazer.
     */
    bool desfaca();

    void limpe();

      /**
     * @brief Vê se tem algo no historico
     * @return true se tiver algo no historico é isso ou nao é
     */
    bool tem_historico() const;

    /**
     * @brief Olha a última ação registrada sem desfazer.
     * @pre tem_historico() == true
     */
    const AcaoMovimento& ver_ultima_acao() const;
};

#endif