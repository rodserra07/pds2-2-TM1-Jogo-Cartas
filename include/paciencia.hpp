#ifndef PACIENCIA_HPP
#define PACIENCIA_HPP

#include "Tableau.hpp"
#include "Fundacao.hpp"
#include "Mover.hpp"
#include "Pilha.hpp"
#include <string>

/**
 * @brief Classe que vai sustentar todo o fluxo da paciencia 
 */
class JogoPaciencia {
private:
    Tableau _tableau;
    Fundacao _fundacao;
    PilhaCartas _estoque;
    PilhaCartas _descarte;
    GerenciadorMovimento _gerenciador_undo;
    int _pontuacao;
    int _tempo_decorrido;

public:
    JogoPaciencia();

    /**
     * @brief Inicia o baralho, embaralha ele e distribui as cartinha
     */
    void iniciar_nova_partida();

    /**
     * @brief Compra a carta do estoque e coloca no descarte
     */
    void comprar_carta_estoque();

    /**
     * @brief Salva todos os elementos necessarios para retomar o jogo em um arquivo .csv
     * @param caminho_arquivo (padrão: "data/partida.csv").
     */
    void save(const std::string& caminho_arquivo);

    /**
     * @brief Carrega todas as informações do .csv retomando a partida de onde parou.
     * @param caminho_arquivo (padrão: "data/partida.csv").
     */
    void load(const std::string& caminho_arquivo);
};

#endif