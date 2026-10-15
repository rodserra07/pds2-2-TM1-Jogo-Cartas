#include "doctest.h"
#include "Pilha.hpp"

TEST_CASE("veirificar pilha zerada e empilhando os trem") {
 Pilha p;
  CHECK(p.esta_vazia());
   CHECK(p.get_quantidade() == 0);

Carta c1{1, Naipe::OUROS};
  p.adicionar_carta(c1);
    CHECK_FALSE(p.esta_vazia());
 CHECK(p.get_quantidade() == 1);
  CHECK(p.ver_topo().get_valor() == 1);
}

TEST_CASE("arrancando carta do topo e dando um limpa no monte") {
  Pilha p;
    Carta c1(1, Naipe::OUROS);
  Carta c2{2, Naipe::ESPADAS};
 Carta c3(10, Naipe::COPAS);

 p.adicionar_carta(c1);
   p.adicionar_carta(c2);
 p.adicionar_carta(c3);
CHECK(p.get_quantidade() == 3);

   Carta topo1 = p.remover_topo();
  CHECK(topo1.get_valor() == 10);
   Carta topo2 = p.remover_topo();
  CHECK(topo2.get_valor() == 2);
 CHECK(p.get_quantidade() == 1);

    p.limpar();
  CHECK(p.esta_vazia());
CHECK(p.get_quantidade() == 0);
}