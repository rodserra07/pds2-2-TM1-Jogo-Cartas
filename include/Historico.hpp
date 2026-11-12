#ifndef HISTORICO_HPP
#define HISTORICO_HPP

#include "AcaoMovimento.hpp"
#include <stack>


/**
 * @brief Gerenciador do historico
 */
class Historico
{
private:
    std::stack<AcaoMovimento> _historico; ///< historico de ações, permitindo desfazer movimentos

public:
    /**
     * @brief Construtor do historico
     */
    Historico() = default;

    /**
     * @brief Registra a ação feita no historico
     * @param acao Dados do movimento feito.
     */
    void registre_acao(const AcaoMovimento &acao);

    /**
     * @brief Retira a ultima acao do historico
     * @return true se havia movimento para desfazer.
     */
    bool desfaca();

    /**
     * @brief apaga o historico
     */
    void limpe();

    /**
     * @brief Vê se tem algo no historico
     * @return true se tiver algo no historico, false se tiver vazio
     */
    bool tem_historico() const;

    /**
     * @brief Olha a última ação registrada sem desfazer.
     * @throws std::out_of_range se o historico estiver vazio
     * @return referencia para a ultima ação feita
     */
    const AcaoMovimento &ver_ultima_acao() const;
};

#endif