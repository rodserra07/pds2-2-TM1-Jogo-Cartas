#include "doctest.h"
#include "Paciencia.hpp"
#include <cstdio>
#include <fstream>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

const char *ARQ = "data/teste_regras.csv";

struct C
{
    int v, n;
    bool up;
};
typedef std::vector<C> Lista;

static void linha(std::ofstream &o, const Lista &l)
{
    o << l.size();
    for (size_t i = 0; i < l.size(); i++)
        o << "," << l[i].v << "," << l[i].n << "," << l[i].up;
    o << "\n";
}

static void grave(std::vector<Lista> p, int pontos = 0)
{
    p.resize(12);
    std::set<int> usadas;
    for (size_t i = 0; i < p.size(); i++)
        for (size_t k = 0; k < p[i].size(); k++)
            usadas.insert(p[i][k].n * 100 + p[i][k].v);
    Lista estoque;
    for (int n = 0; n < 4; n++)
        for (int v = 1; v <= 13; v++)
            if (!usadas.count(n * 100 + v))
            {
                C c = {v, n, false};
                estoque.push_back(c);
            }
    std::ofstream o(ARQ);
    o << pontos << ",0\n";
    linha(o, estoque);
    for (size_t i = 0; i < p.size(); i++)
        linha(o, p[i]);
}

TEST_CASE("move de uma coluna pra outra e desfaz a jogada")
{
    std::vector<Lista> p(12);
    p[5] = {{2, 3, false}, {7, 0, true}};
    p[6] = {{8, 3, true}};
    grave(p);
    Paciencia j;
    j.load(ARQ);

    CHECK(j.mover_coluna_para_coluna(0, 1, 1));
    CHECK(j.get_pontuacao() == 5);
    CHECK(j.desfaca());
    CHECK(j.get_pontuacao() == 0);
    CHECK_FALSE(j.desfaca());
    std::remove(ARQ);
}

TEST_CASE("mover recusa carta da mesma cor")
{
    std::vector<Lista> p(12);
    p[5] = {{7, 0, true}};
    p[6] = {{8, 1, true}};
    grave(p);
    Paciencia j;
    j.load(ARQ);

    CHECK_FALSE(j.mover_coluna_para_coluna(0, 1, 1));
    CHECK(j.get_mensagem() == "A carta precisa de um valor uma unidade inferior ao topo e de cor oposta");
    CHECK(j.get_pontuacao() == 0);
    std::remove(ARQ);
}

TEST_CASE("fundacao recebe so as")
{
    std::vector<Lista> p(12);
    p[0] = {{2, 0, true}};
    p[5] = {{5, 1, false}, {1, 1, true}};
    grave(p);
    Paciencia j;
    j.load(ARQ);

    CHECK_FALSE(j.mover_descarte_para_fundacao());
    CHECK(j.mover_coluna_para_fundacao(0));
    CHECK(j.get_pontuacao() == 15);
    CHECK(j.desfaca());
    CHECK(j.get_pontuacao() == 0);
    std::remove(ARQ);
}

TEST_CASE("vitoria quando 4 fundacoes completas")
{
    std::vector<Lista> p(12);
    for (int n = 0; n < 4; n++)
        for (int v = 1; v <= 13; v++)
            p[1 + n].push_back(C{v, n, true});
    grave(p);
    Paciencia j;
    j.load(ARQ);
    CHECK(j.gg_ez());

    p[4].pop_back();
    p[5] = {{13, 3, true}};
    grave(p);
    j.load(ARQ);
    CHECK_FALSE(j.gg_ez());
    std::remove(ARQ);
}

TEST_CASE("load nao causa erro")
{
    grave(std::vector<Lista>(12), 77);
    Paciencia j;
    j.load(ARQ);
    CHECK(j.get_pontuacao() == 77);

    const char *ruins[] = {"", "abc\n", "0,0\n3,1,0,1\n", "0,0\n1,14,0,1\n"};
    for (int i = 0; i < 4; i++)
    {
        std::ofstream o(ARQ);
        o << ruins[i];
        o.close();
        j.load(ARQ);
        CHECK(j.get_mensagem().find("Erro") == 0);
        CHECK(j.get_pontuacao() == 77);
    }
    std::remove(ARQ);
}

TEST_CASE("Pilha transfere carta e lança excecao")
{
    Pilha a, b;
    a.add_carta(Carta(1, Naipe::COPAS));
    a.add_carta(Carta(2, Naipe::COPAS));
    a.add_carta(Carta(3, Naipe::COPAS));

    a.transfira_para(b, 2);
    CHECK(b.get_carta(0).get_valor() == 2);
    CHECK(b.get_carta(1).get_valor() == 3);

    CHECK_THROWS_AS(a.transfira_para(a, 1), std::invalid_argument);
    CHECK_THROWS_AS(a.transfira_para(b, 5), std::invalid_argument);
    CHECK_THROWS_AS(a.get_carta(9), std::out_of_range);
}

TEST_CASE("Coluna testando liberacao")
{
    Coluna col;
    Carta a(9, Naipe::PAUS), b(8, Naipe::COPAS), c(7, Naipe::OUROS);
    a.set_visivel(true);
    b.set_visivel(true);
    c.set_visivel(true);
    col.add_carta(a);
    col.add_carta(b);
    col.add_carta(c);

    CHECK(col.pdp_retire(1));
    CHECK_FALSE(col.pdp_retire(2));
    CHECK_FALSE(col.pdp_retire(4));

    Coluna escondida;
    escondida.add_carta(Carta(5, Naipe::COPAS));
    CHECK_FALSE(escondida.pdp_retire(1));
}

TEST_CASE("Fundacao lança excecao se receber carta errada")
{
    Fundacao f;
    CHECK_FALSE(f.get_pilha(Naipe::COPAS).pdp_receba(Carta(5, Naipe::COPAS)));
    for (int n = 0; n < 4; n++)
        for (int v = 1; v <= 13; v++)
        {
            Pilha &pilha = f.get_pilha(static_cast<Naipe>(n));
            Carta c(v, static_cast<Naipe>(n));
            CHECK(pilha.pdp_receba(c));
            pilha.add_carta(c);
        }
    CHECK(f.gg());
}

TEST_CASE("Carta recusa valor fora de 1 a 13")
{
    CHECK_THROWS_AS(Carta(0, Naipe::COPAS), std::invalid_argument);
    CHECK_THROWS_AS(Carta(14, Naipe::PAUS), std::invalid_argument);
}