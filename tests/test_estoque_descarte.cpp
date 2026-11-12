#include "doctest.h"
#include "Estoque.hpp"
#include "Descarte.hpp"

TEST_CASE("estoque nao deixa colocar nem tirar carta na mao")
{
    Estoque e;
    Carta c(5, Naipe::COPAS);
    e.add_carta(c);

    CHECK_FALSE(e.pdp_receba(c));
    CHECK_FALSE(e.pdp_retire(1));
}

TEST_CASE("descarte so deixa tirar a carta de cima")
{
    Descarte d;
    Carta c(5, Naipe::COPAS);
    d.add_carta(c);

    CHECK_FALSE(d.pdp_receba(c));
    CHECK(d.pdp_retire(1));
    CHECK_FALSE(d.pdp_retire(2));
}