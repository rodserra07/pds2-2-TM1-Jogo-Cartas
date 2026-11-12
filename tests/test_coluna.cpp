#include "doctest.h"
#include "Coluna.hpp"

TEST_CASE("mensagem quando a coluna recusa a carta")
{
    Coluna c;
    CHECK(c.satisfacao() == "A coluna esta vazia, precisa de um rei para inicia-la");

    Carta rei(13, Naipe::PAUS);
    c.add_carta(rei);
    CHECK(c.satisfacao() == "A carta precisa de um valor uma unidade inferior ao topo e de cor oposta");
}

TEST_CASE("virando a carta de cima da coluna")
{
    Coluna c;
    Carta carta(5, Naipe::COPAS);
    c.add_carta(carta);

    CHECK(c.revele_topo());
    CHECK(c.pdp_retire(1));
}