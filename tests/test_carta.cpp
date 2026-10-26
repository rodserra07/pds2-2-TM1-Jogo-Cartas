#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Carta.hpp"

TEST_CASE("ve se os getter tao suave") {
Carta c1{1, Naipe::COPAS};
  CHECK(c1.get_valor() == 1);
CHECK(c1.get_naipe() == Naipe::COPAS);
  CHECK(c1.get_cor() == Cor::VERMELHO);

 Carta c2(13, Naipe::ESPADAS);
   CHECK(c2.get_valor() == 13);
  CHECK(c2.get_naipe() == Naipe::ESPADAS);
CHECK(c2.get_cor() == Cor::PRETO);
}

TEST_CASE("virando a carta pra ver se ela vira") {
  Carta c{7, Naipe::OUROS};
CHECK(!c.visivel());

  c.set_visivel(true);
    CHECK(c.visivel());

  c.set_visivel(false);
   CHECK_FALSE(c.visivel());
}

TEST_CASE("checa se as cores tao tipo é tipo ham tipo na-da-ve") {
  Carta vermelho(5, Naipe::COPAS);
    Carta preto{5, Naipe::PAUS};
  Carta outro_vermelho(8, Naipe::OUROS);

  CHECK(vermelho.cor_diff(preto));
 CHECK(!vermelho.cor_diff(outro_vermelho));
}