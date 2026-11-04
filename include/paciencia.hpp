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

    /**
     * @brief atualiza o empo que passou
     */
    void att_tempo();

    /**
     * @brief Devolve a pilha em um codigo simplificado
     * @param codide 0 a 6 pras colunas, e de 7 a 9 pra estoque descarte ou fundacao
     * @param naipa da fundaçaão
     * @return referencia pra pilha
     * @throws std::out_of_range se o codigo estiver incoerenete
     */
    Pilha& pilha_por_codigo(int codigo, Naipe naipe = Naipe::COPAS);

    /**
     * @brief Move as carta eu acho
     * @param cod_origem codigo pilha origem
     * @param cod_destino codigo pilha destino
     * @param qtd quantidade de cartas a mover
     * @return True se o o movimento foi feito
     */
    bool mover(int cod_origem, int cod_destino, int qtd);
public:
    Paciencia();

    /**
     * @brief Inicia o baralho, embaralha ele e distribui as cartinha, reseta os ponto e o tempo
     */
    void iniciar_nova_partida();

    /**
     * @brief Compra a carta do estoque e coloca no descarte
     */
    void comprar_carta_estoque();


     /**
     * @brief Move carta de um tableau pra outro tableau
     * @param origem coluna de origem
     * @param destino coluna de destino
     * @param qtd quantidade de cartas a mover
     * @return true se o movimento for valido
     */
    bool mover_coluna_para_coluna(int origem, int destino, int qtd);

    /**
     * @brief Move a carta do topo do descarte para uma coluna.
     * @param coluna Coluna de destino
     * @return true se foi feito o movimento
     */
    bool mover_descarte_para_coluna(int coluna);

    /**
     * @brief Move a carta do topo do descarte para a fundação
     * @param coluna Coluna de origem
     * @return true se foi feito o movimento
     */
    bool mover_coluna_para_fundacao(int coluna);

    /**
     * @brief Move a carta do topo do descarte para a fundação.
     * @return true se foi feito o movimento
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
     * @brief true se as 4 fundações estão completas.
     * @return true se as 4 fundação tao completas
     */
    bool gg_ez() const;


    /**
     * @brief retorna a pontuação
     * @return pontos da partida
     */
    int get_pontuacao() const;

    /**
     * @brief atualiza e retona o tempo
     * @return tempo passado
     */
    int get_tempo();

        /**
     * @brief retorna a mensagem da ultima jogada
     * @return texto da mensgem
     */
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