#include "doctest.h"
#include "Tableau.hpp"

TEST_CASE("vendo se a moderação ta on e verificando a validade dos movimentos do tableau") {
 Tableau t;
   Carta rei{13, Naipe::ESPADAS};
  Carta dama_vermelha(12, Naipe::COPAS);
 Carta dama_preta{12, Naipe::PAUS};
   Carta valete_vermelho(11, Naipe::OUROS);

  CHECK_FALSE(t.validar_movimento(dama_vermelha, 0));
    CHECK(t.validar_movimento(rei, 0));

   t.get_coluna(0).adicionar_carta(rei);
  CHECK(t.validar_movimento(dama_vermelha, 0));
 CHECK(!t.validar_movimento(dama_preta, 0));

  t.get_coluna(0).adicionar_carta(dama_vermelha);
   CHECK(t.validar_movimento(valete_vermelho, 0) == false);
}

TEST_CASE("mexendo nas colunas diretamente") {
  Tableau t;
    Carta c(2, Naipe::OUROS);
 t.get_coluna(1).adicionar_carta(c);

   CHECK(!t.get_coluna(1).esta_vazia());
  CHECK(t.get_coluna(1).get_quantidade() == 1);
}