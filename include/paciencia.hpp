#ifndef PACIENCIA_HPP
#define PACIENCIA_HPP

#include "Tableau.hpp"
#include "Fundacao.hpp"
#include "Mover.hpp"
#include "Estoque.hpp"
#include "Descarte.hpp"
#include <string>
#include <ctime>

/**
 * @brief Classe que vai sustentar todo o fluxo da paciencia 
 */
class Paciencia {
private:
    Tableau _tableau;
    Fundacao _fundacao;
    Estoque _estoque;
    Descarte _descarte;
    GerenciadorMovimento _gerenciador_undo;
    int _pontuacao;
    int _tempo_decorrido;
    std::time_t _inicio;
    std::string _mensagem; 

    void att_tempo();

    /**
     * Devolve a pilha em um codigo simplificado
     */
    Pilha& pilha_por_codigo(int codigo, Naipe naipe = Naipe::COPAS);

    /**
     * Move as carta eu acho
     */
    bool mover(int cod_origem, int cod_destino, int qtd);
public:
    Paciencia();

    /**
     * @brief Inicia o baralho, embaralha ele e distribui as cartinha
     */
    void iniciar_nova_partida();

    /**
     * @brief Compra a carta do estoque e coloca no descarte
     */
    void comprar_carta_estoque();


     /**
     * @brief Move carta de um tableau pra outro tableau
     * @return true se o movimento for valido
     */
    bool mover_coluna_para_coluna(int origem, int destino, int qtd);

    /**
     * @brief Move a carta do topo do descarte para uma coluna.
     */
    bool mover_descarte_para_coluna(int coluna);

    /**
     * @brief Move a carta do topo de uma coluna para a fundação.
     */
    bool mover_coluna_para_fundacao(int coluna);

    /**
     * @brief Move a carta do topo do descarte para a fundação.
     */
    bool mover_descarte_para_fundacao();

    /**
     * @brief Desfaz a última jogada.
     * @return true se tinha jogada para desfazer.
     */
    bool desfaca();

    /**
     * @brief Desenha o jogo na tela
     */
    void exiba();

    /**
     * @return true se as 4 fundações estão completas.
     */
    bool gg() const;

    int get_pontuacao() const;
    int get_tempo();
    const std::string& get_mensagem() const;

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