#include "doctest.h"
#include "Fundacao.hpp"

TEST_CASE("testando se a proteção da funtação ta funfando") {
    Fundacao f;
   Carta as(1, Naipe::COPAS);
 Carta dois{2, Naipe::COPAS};
  Carta tres(3, Naipe::ESPADAS);
 Carta as_outronaipe{1, Naipe::OUROS};

  CHECK_FALSE(f.valide_insira(dois));
   CHECK(!f.valide_insira(tres));
  CHECK(f.valide_insira(as));

    f.insira_carta(as);
  CHECK(f.valide_insira(dois));
 CHECK_FALSE(f.valide_insira(tres));
   CHECK(f.valide_insira(as_outronaipe));
}

TEST_CASE("checando booyah e o jogo acabou") {
  Fundacao f;
   CHECK(!f.gg());
}