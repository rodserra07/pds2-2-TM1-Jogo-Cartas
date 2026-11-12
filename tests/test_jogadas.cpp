#include "doctest.h"
#include "paciencia.hpp"

TEST_CASE("comprando todo o estoque") {
    Paciencia j;
    j.iniciar_nova_partida();

    for (int i = 0; i < 24; i++) {
        j.comprar_carta_estoque();
    }
    j.comprar_carta_estoque(); // o descarte volta pro estoque
    CHECK(j.get_mensagem() == "Descarte devolvido para o estoque.");
}

TEST_CASE("desfazendo a compra") {
    Paciencia j;
    j.iniciar_nova_partida();
    j.comprar_carta_estoque();

    CHECK(j.desfaca());
    CHECK_FALSE(j.desfaca()); // nao tem mais nada pra desfazer
}

TEST_CASE("jogadas invalidas") {
    Paciencia j;
    j.iniciar_nova_partida();

    CHECK_FALSE(j.mover_coluna_para_coluna(-1, 1, 1)); // coluna nao existe
    CHECK_FALSE(j.mover_coluna_para_coluna(0, 0, 1));  // mesma coluna
    CHECK_FALSE(j.mover_descarte_para_coluna(8));      // coluna nao existe
    CHECK_FALSE(j.mover_coluna_para_fundacao(9));      // coluna nao existe
    CHECK_FALSE(j.mover_descarte_para_fundacao());     // descarte vazio
    CHECK(j.get_pontuacao() == 0);
}

TEST_CASE("carregando save que nao existe") {
    Paciencia j;
    j.load("data/nao_existe.csv");
    CHECK(j.get_mensagem().find("Erro") == 0);
}