# Jogo de Carta Solo: Paciência (Solitaire)

## Integrantes do Grupo
* Rodrigo Alves Serra - Matricula: 2024090693
* Felipe Maia - Matricula: 2025423874

## Descrição do Problema
O projeto consiste no desenvolvimento do famoso jogo de cartas  Paciência em C++. O objetivo principal é organizar um baralho completo de 52 cartas em quatro pilhas de fundação (uma para cada naipe), ordenadas de forma crescente do Ás ao Rei. O jogador precisa manipular as cartas distribuídas em sete colunas no tabuleiro, respeitando regras de ordenação decrescente e alternância de cores, além de utilizar o monte de compra quando necessário.

## Motivação
Nosso grupo se questionou muito sobre qual jogo a gente pegaria pra fazer, primeiro pensamos em fazer de jogos para 2 jogadores ou mais, mas rapidamente percebemos um obstaculo, a privacidade. Ao ver que seria impossivel fazer um jogo de cartas multijogador devido a falta de privacidade nos migramos para um solo, e qual o primeiro jogo de carta que voce pensa ao pensar em "jogo de carta pra jogar sozinho", a resposta é só uma, paciencia, um jogo simples, facil de entender, e mesmo sendo simples tem varias janelas para aplicar os conceitos fundamentais de Programação e Desenvolvimento de Software II.

## Estrutura do Repositório
* `design/`: Documentação de requisitos (User Stories e Cartões CRC).
* `include/`: Arquivos de cabeçalho (`.hpp`) com definições das classes e documentação Doxygen.
* `src/`: Implementação dos métodos das classes (`.cpp`).
* `tests/`: Testes unitários do sistema (doctest).
* `third_party/`: Biblioteca doctest.
* `data/`: Arquivo de salvamento da partida (`partida.csv`).
* `build/`: Executáveis gerados na compilação.
* `makefile`: Regras de compilação, testes e cobertura.

## Como Compilar e Executar
Requisitos: g++ com suporte a C++11 e make (para cobertura, também o gcovr).

* `make`: compila e executa o jogo.
* `make testes`: compila e executa os testes unitários.
* `make coverage`: executa os testes e mostra a cobertura de código.
* `make clean`: apaga os arquivos compilados.

## Como Jogar
| Comando | Ação |
|---|---|
| `c` | Comprar carta do estoque (ou devolver o descarte pro estoque) |
| `m O D` | Mover 1 carta da coluna O para a coluna D |
| `mm O D N` | Mover N cartas da coluna O para a coluna D |
| `d N` | Mover o topo do descarte para a coluna N |
| `f N` | Mover o topo da coluna N para a fundação |
| `df` | Mover o topo do descarte para a fundação |
| `u` | Desfazer a última jogada |
| `s` / `l` | Salvar / carregar a partida |
| `n` | Nova partida |
| `h` | Ajuda |
| `q` | Voltar pro menu |

As colunas vão de 1 a 7.