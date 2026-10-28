#include "paciencia.hpp"

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <string>

#ifdef _WIN32
#include <conio.h>
#endif

//limpa a tela 
void limpe_tela() {
#ifdef _WIN32
    system("cls");  
#else
    system("clear");
#endif
}

//limpa entrada quando o usuaria digita alguma gafe
void limpe_entrada() {
  std::cin.clear();
  std::cin.ignore(1000, '\n');
}

//espera o jogado apertar uma tecla pra passar o turno/texto

void espere_tecla() {
    std::cout << "\nAperte qualquer tecla para continuar...";
    #ifdef _WIN32
    _getch();
#else
    std::cin.get();
#endif
    std::cout << "\n";
}

void mostre_ajuda() {
     std::cout << "\nComandos:\n";
    std::cout << "  c            comprar carta do estoque (ou devolver o descarte pro estoque)\n";
    std::cout << "  m O D        mover 1 carta da coluna O para a coluna D\n";
    std::cout << "  mm O D N     mover N cartas da coluna O para a coluna D\n";
    std::cout << "  d N          mover o topo do descarte para a coluna N\n";
    std::cout << "  f N          mover o topo da coluna N para a fundacao\n";
    std::cout << "  df           mover o topo do descarte para a fundacao\n";
    std::cout << "  u            desfazer a ultima jogada\n";
    std::cout << "  s            salvar a partida (data/partida.csv)\n";
    std::cout << "  l            carregar a partida (data/partida.csv)\n";
    std::cout << "  n            nova partida\n";
    std::cout << "  h            mostrar esta ajuda\n";
    std::cout << "  q            voltar pro menu\n";
    std::cout << "\nAs colunas vao de 1 a 7.\n";
    std::cout << "Naipes: C = copas, O = ouros, E = espadas, P = paus. ## = carta virada pra baixo.\n";
}

//menu inciial
void mostre_menu() {
     std::cout << "=========================================\n";
    std::cout << "               PACIENCIA\n";
    std::cout << "=========================================\n\n";
    std::cout << "   1 - Novo jogo\n";
    std::cout << "   2 - Carregar jogo\n";
    std::cout << "   3 - Sair\n\n";
    std::cout << "Escolha uma opcao: ";

}

//explicação assim que se inicia um jogo novo
void mostre_explicacao() {
    limpe_tela();
    std::cout << "=============== COMO JOGAR ===============\n\n";
    std::cout << "Objetivo: levar as 52 cartas para as 4 fundacoes,\n";
    std::cout << "uma fundacao pra cada naipe, em ordem crescente (do As ate o Rei).\n\n";
    std::cout << "O jogo tem:\n";
    std::cout << "  - 7 colunas: voce monta sequencias em ordem decrescente\n";
    std::cout << "    alternando as cores. Ex.: um 7 vermelho vai em cima de um 8 preto.\n";
    std::cout << "    Copas e ouros sao vermelhos, espadas e paus sao pretos.\n";
    std::cout << "    Coluna vazia so aceita Rei.\n";
    std::cout << "  - Estoque: voce compra uma carta de cada vez e ela vai pro descarte.\n";
    std::cout << "    Quando o estoque acaba, o descarte volta pro estoque.\n";
    std::cout << "  - Descarte: so a carta de cima pode ser jogada.\n";
    std::cout << "  - Fundacoes: comecam com o As e sobem uma carta de cada vez.\n\n";
    std::cout << "Pontos: +10 por carta na fundacao e +5 por carta virada na coluna.\n";
    espere_tecla(); limpe_tela(); 
    std::cout <<"================ COMANDOS ================\n";
    mostre_ajuda(); espere_tecla(); limpe_tela(); }


    //A paciencia 
    void jogar(Paciencia& jogo) {
        jogo.exiba();
        std::cout << jogo.get_mensagem() << "\n";

        std::string comando;
        while (true) {
            std::cout << "> ";
            if (!(std::cin >> comando)){ 
                return; // sem entrada

            }
try{
    if (comando == "q"){
        return;
    } else if( comando == "h"){
        mostre_ajuda(); continue; }
            else if (comando == "c"){
                jogo.comprar_carta_estoque(); }
                else if (comando == "m"){
                    int origem, destino;
                    std::cin  >> origem >> destino; 
                    if(std::cin.fail())
                    { limpe_entrada(); std::cout << "para usar corretamente coloque no formato m origem destino, tipo 'm 6 7'\n";
                        continue;
                    }
                    //descresce um da origem e coluna, pro 1 a 7 ser lido como 0 a 6 pelo compiuter
                    jogo.mover_coluna_para_coluna(origem - 1, destino - 1, 1);
                    } else if(comando == "mm"){
                        int origem, destino, quantidade;
                        std::cin >> origem >> destino >> quantidade;
                        if (std::cin.fail()){ limpe_entrada();
                            std::cout << "a forma correta é mm origem destino quantidade, por exemplo 'mm 6 7 8'\n";
                            continue;
                        }
jogo.mover_coluna_para_coluna(origem - 1, destino - 1, quantidade);
        }
    else if (comando == "d")
    {int coluna;
std::cin >> coluna;
if (std::cin.fail()){
    limpe_entrada();
    std::cout << "A forma correta de usar é d coluna, tipo 'd 6' \n";
    continue;
} jogo.mover_descarte_para_coluna(coluna - 1);
} else if (comando == "f"){
    int coluna; std::cin >> coluna;
    if(std::cin.fail()){ limpe_entrada();
    std::cout << "A forma correta de usar é f coluna, tipo 'f 7'\n";
    continue;
}
jogo.mover_coluna_para_fundacao(coluna - 1);
} else if (comando == "df"){
                jogo.mover_descarte_para_fundacao();

            } else if (comando == "u"){
                jogo.desfaca();

            } else if (comando == "s"){
                jogo.save("data/partida.csv");

            } else if (comando == "l"){
                jogo.load("data/partida.csv");

            } else if (comando == "n"){
                jogo.iniciar_nova_partida();

            } else{
                std::cout << "Comando invalido, Digite h para ver a ajuda.\n";
                continue;
            }

            jogo.exiba();
            std::cout << jogo.get_mensagem() << "\n";

            if (jogo.gg()) {
                std::cout << "\n*** EBA voce ganhou oba! ***\n";
                std::cout << "Pontuacao final: " << jogo.get_pontuacao() << "\n";
           limpe_entrada(); espere_tecla();
        return;
     } } catch (const std::exception& erro){
            std::cout << "Erro inesperado: " << erro.what() << "\n";
        }
        }
    }

    int main() {
        //embaralha o baralho toda vez que um jogo começa
        std::srand(std::time(nullptr));

        Paciencia jogo;

        while(true){ mostre_menu();
        
        int opcao;
    if(!(std::cin >> opcao)){
        if(std::cin.eof()){
        break;
    }limpe_entrada();
continue;
}
limpe_entrada();

if(opcao == 1){
    mostre_explicacao();
    jogo.iniciar_nova_partida(); jogar(jogo);
} else if (opcao == 2){
    jogo.load("data/partida.csv");
    if(jogo.get_mensagem().find("Erro") == 0){
        std::cout << "\n" << jogo.get_mensagem() << "\n";
        espere_tecla();
    } else {
        limpe_tela(); jogar(jogo);
    }
} else if (opcao == 3){ break;} 
else{ std::cout << "\nOpcao invalida, escolha os respectivos numeros de 1 a 3.\n";
espere_tecla();}
    }
    std::cout << "\n gg, ate mais\n";
    return 0;
}