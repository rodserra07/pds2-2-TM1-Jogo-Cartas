#include "doctest.h"
#include "Tableau.hpp"

TEST_CASE("vendo se a moderação ta on e verificando a validade dos movimentos do tableau")
{
  Tableau t;
  Carta rei{13, Naipe::ESPADAS};
  Carta dama_vermelha(12, Naipe::COPAS);
  Carta dama_preta{12, Naipe::PAUS};
  Carta valete_vermelho(11, Naipe::OUROS);

  CHECK_FALSE(t.get_coluna(0).pdp_receba(dama_vermelha));
  CHECK(t.get_coluna(0).pdp_receba(rei));

  t.get_coluna(0).add_carta(rei);
  CHECK(t.get_coluna(0).pdp_receba(dama_vermelha));
  CHECK(!t.get_coluna(0).pdp_receba(dama_preta));

  t.get_coluna(0).add_carta(dama_vermelha);
  CHECK(t.get_coluna(0).pdp_receba(valete_vermelho) == false);
}

TEST_CASE("mexendo nas colunas diretamente")
{
  Tableau t;
  Carta c(2, Naipe::OUROS);
  t.get_coluna(1).add_carta(c);

  CHECK(!t.get_coluna(1).esta_vazia());
  CHECK(t.get_coluna(1).get_quantidade() == 1);
}

TEST_CASE("passando carta de uma coluna pra outra")
{
  Tableau t;
  Carta rei(13, Naipe::PAUS);
  t.get_coluna(0).add_carta(rei);

  t.get_coluna(0).transfira_para(t.get_coluna(1), 1);
  CHECK(t.get_coluna(0).esta_vazia());
  CHECK(t.get_coluna(1).get_quantidade() == 1);
}

TEST_CASE("coluna que nao existe")
{
  Tableau t;
  CHECK_THROWS(t.get_coluna(7));
}