#include "doctest.h"
#include "Fundacao.hpp"

TEST_CASE("testando se a proteção da funtação ta funfando")
{
  Fundacao f;
  Carta as(1, Naipe::COPAS);
  Carta dois{2, Naipe::COPAS};
  Carta tres(3, Naipe::ESPADAS);
  Carta as_outronaipe{1, Naipe::OUROS};

  CHECK_FALSE(f.get_pilha(Naipe::COPAS).pdp_receba(dois));
  CHECK(!f.get_pilha(Naipe::ESPADAS).pdp_receba(tres));
  CHECK(f.get_pilha(Naipe::COPAS).pdp_receba(as));

  f.get_pilha(Naipe::COPAS).add_carta(as);
  CHECK(f.get_pilha(Naipe::COPAS).pdp_receba(dois));
  CHECK_FALSE(f.get_pilha(Naipe::ESPADAS).pdp_receba(tres));
  CHECK(f.get_pilha(Naipe::OUROS).pdp_receba(as_outronaipe));
}

TEST_CASE("checando booyah e o jogo acabou")
{
  Fundacao f;
  CHECK(!f.gg());
}