#ifndef MOVER_HPP
#define MOVER_HPP

#include "AcaoMovimento.hpp"
#include <stack>

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