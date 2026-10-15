#include "doctest.h"
#include "Fundacao.hpp"

TEST_CASE("testando se a proteção da funtação ta funfando") {
    Fundacao f;
   Carta as(1, Naipe::COPAS);
 Carta dois{2, Naipe::COPAS};
  Carta tres(3, Naipe::ESPADAS);
 Carta as_outronaipe{1, Naipe::OUROS};

  CHECK_FALSE(f.validar_insercao(dois));
   CHECK(!f.validar_insercao(tres));
  CHECK(f.validar_insercao(as));

    f.inserir_carta(as);
  CHECK(f.validar_insercao(dois));
 CHECK_FALSE(f.validar_insercao(tres));
   CHECK_FALSE(f.validar_insercao(as_outronaipe));
}

TEST_CASE("checando booyah e o jogo acabou") {
  Fundacao f;
   CHECK(!f.jogo_ganho());
}