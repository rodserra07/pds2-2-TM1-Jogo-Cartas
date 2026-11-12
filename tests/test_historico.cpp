#include "doctest.h"
#include "Historico.hpp"
#include <stdexcept>

TEST_CASE("testando o botao de voltar a jogada")
{
  Historico g;
  Carta c1{5, Naipe::PAUS};
  Carta c2(6, Naipe::COPAS);
  Carta c3{7, Naipe::OUROS};

  AcaoMovimento a1{0, 1, c1, false};
  AcaoMovimento a2{1, 2, c2, true};
  AcaoMovimento a3{2, 3, c3, false};

  g.registre_acao(a1);
  g.registre_acao(a2);
  g.registre_acao(a3);

  CHECK(g.desfaca());
  CHECK(g.desfaca());
  CHECK(g.desfaca());
  CHECK_FALSE(g.desfaca());
}

TEST_CASE("zerando o historico de movimentos")
{
  Historico g;
  Carta c(10, Naipe::OUROS);
  AcaoMovimento a{0, 1, c, false};

  g.registre_acao(a);
  g.limpe();
  CHECK(!g.desfaca());
}
TEST_CASE("ver historico vazio")
{
  Historico g;
  CHECK_THROWS_AS(g.ver_ultima_acao(), std::out_of_range);

  Carta c(5, Naipe::PAUS);
  g.registre_acao(AcaoMovimento{0, 1, c, false, 1, 0});
  CHECK_NOTHROW(g.ver_ultima_acao());
}