#include "doctest.h"
#include "Paciencia.hpp"
#include <cstdio> 

TEST_CASE("startando a partida do zero") {
    Paciencia j;
  j.iniciar_nova_partida();
   j.comprar_carta_estoque();
}

TEST_CASE("salvando e recarregando o progresso pra nao perder o jogo") {
    Paciencia j1;
  j1.iniciar_nova_partida();
   CHECK_NOTHROW(j1.save("data/teste.csv"));


    Paciencia j2;
      CHECK_NOTHROW(j2.load("data/teste.csv"));


    std::remove("data/teste.csv");
}