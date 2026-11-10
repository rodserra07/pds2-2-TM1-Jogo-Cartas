#ifndef CARTA_HPP
#define CARTA_HPP

#include <string>

/**
 * @brief Os naipes do baralho.
 *
 *A ordem é usada como indice na fundação entao nao pode ser alterada
 */
enum class Naipe {
    COPAS,
    OUROS,
    ESPADAS,
    PAUS
};

/**
 * @brief cor das cartas.
 */
enum class Cor {
    VERMELHO,
    PRETO
};

/**
 * @brief Classe que cria os objetos carta, formando as 52 cartas do baralho.
 *
 * O baralho tem 52 cartas, 13 de cada naipe
 */
class Carta {
private:
    int _valor;      
    Naipe _naipe;    
    Cor _cor;         
    bool _visivel;   

public:
    /**
     * @brief Construtor da carta.
     * @param Valor numérico de 1 a 13.
     * @param Naipe da carta.
     * @throws std::invalid_argument se o valor nao estiver entre 1-13
     */
    Carta(int valor, Naipe naipe);

     /**
     * @brief retorna o valor da carta
     * @return Valor de 1 a 13
     */
    int get_valor() const;

    /**
     * @brief retorna o naipe da carta
     * @return naipe da carta
     */
    Naipe get_naipe() const;

    /**
     * @brief retorna acor da carta
     * @return cor da carta
     */
    Cor get_cor() const;

    /**
     * @brief olha se a carta esta virada pra cima o nao
     * @return True se estiver virada pra cima
     */
    bool get_visivel() const;

    /**
     * @brief Vira a carta de cima para baixo e vice versa
     * @param visivel True se tiver pra cima False se tiver pra baixo
     */
    void set_visivel(bool visivel);

    /**
     * @brief Compara a cor de duas cartas
     * @param outra Carta para comparação.
     * @return true se forem cores diferentes, false caso contrário.
     */
    bool cor_diff(const Carta& outra) const;
};

#endif