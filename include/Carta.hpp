#ifndef CARTA_HPP
#define CARTA_HPP

#include <string>

/**
 * @brief Tipos de naipe.
 */
enum class Naipe {
    COPAS,
    OUROS,
    ESPADAS,
    PAUS
};

/**
 * @brief Tipos de cor.
 */
enum class Cor {
    VERMELHO,
    PRETO
};

/**
 * @brief Classe que cria os objetos carta, formando as 52 cartas do baralho.
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
     * @param valor Valor numérico de 1 a 13.
     * @param naipe Naipe da carta.
     */
    Carta(int valor, Naipe naipe);

    int get_valor() const;
    Naipe get_naipe() const;
    Cor get_cor() const;
    bool visivel() const;

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