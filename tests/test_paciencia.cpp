#include "doctest.h"
#include "Paciencia.hpp"
#include <cstdio>
#include <fstream>
#include <string>

TEST_CASE("salvando e recarregando o progresso pra nao perder o jogo")
{
  Paciencia j1;
  j1.iniciar_nova_partida();
  CHECK_NOTHROW(j1.save("data/teste.csv"));

  Paciencia j2;
  CHECK_NOTHROW(j2.load("data/teste.csv"));

  std::remove("data/teste.csv");
}

TEST_CASE("load com duas cartas iguais no save")
{
  const std::string arq = "data/teste_paciencia.csv";

  Paciencia base;
  base.iniciar_nova_partida();
  base.save(arq);
  std::string resto;
  {
    std::ifstream in(arq);
    std::string linha;
    std::getline(in, linha);
    while (std::getline(in, linha))
    {
      resto += linha + "\n";
    }
  }
  {
    std::ofstream out(arq);
    out << "67,0\n"
        << resto;
  }

  Paciencia j;
  j.load(arq);
  CHECK(j.get_pontuacao() == 67);

  {
    std::ofstream out(arq);
    out << "5,0\n"
        << "0\n"
        << "1,1,0,1\n"
        << "1,1,0,1\n"
        << "0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n";
  }
  j.load(arq);
  CHECK(j.get_mensagem().find("Erro") == 0);
  CHECK(j.get_mensagem().find("carta repetida") != std::string::npos);
  CHECK(j.get_pontuacao() == 67);

  {
    std::ofstream out(arq);
    out << "5,0\n"
        << "0\n0\n0\n0\n0\n0\n"
        << "1,5,2,1\n"
        << "0\n0\n0\n0\n0\n"
        << "1,5,2,1\n";
  }
  j.load(arq);
  CHECK(j.get_mensagem().find("carta repetida") != std::string::npos);
  CHECK(j.get_pontuacao() == 67);

  std::remove(arq.c_str());
}
