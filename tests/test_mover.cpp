#include "doctest.h"
#include "Mover.hpp"

TEST_CASE("testando o botao de voltar a jogada") {
  GerenciadorMovimento g;
 Carta c1{5, Naipe::PAUS};
   Carta c2(6, Naipe::COPAS);
  Carta c3{7, Naipe::OUROS};

   AcaoMovimento a1{0, 1, c1, false};
 AcaoMovimento a2{1, 2, c2, true};
   AcaoMovimento a3{2, 3, c3, false};

  g.registrar_acao(a1);
    g.registrar_acao(a2);
  g.registrar_acao(a3);

   CHECK(g.desfazer_ultimo_movimento());
  CHECK(g.desfazer_ultimo_movimento());
   CHECK(g.desfazer_ultimo_movimento());
CHECK_FALSE(g.desfazer_ultimo_movimento());
}

TEST_CASE("zerando o historico de movimentos") {
   GerenciadorMovimento g;
  Carta c(10, Naipe::OUROS);
    AcaoMovimento a{0, 1, c, false};

 g.registrar_acao(a);
   g.limpar_historico();
  CHECK(!g.desfazer_ultimo_movimento());
}