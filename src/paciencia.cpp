#include "paciencia.hpp"

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

//correspondente em codigo das pilhas
const int ESTOQUE = 7;
const int DESCARTE = 8;
const int FUNDACAO = 9;

//transforma os valores que nao tem numero no baralho em sua correspondencia
static std::string carta_para_texto(const Carta& c) {
    if (!c.visivel()){
        return "##";
    }

    std::string valor;
    if (c.get_valor() == 1){
        valor = "A";
    } else if (c.get_valor() == 11){
        valor = "J";
    } else if (c.get_valor() == 12){
        valor = "Q";
    } else if (c.get_valor() == 13){
        valor = "K";
    } else{
        valor = std::to_string(c.get_valor());
    }
std::string naipe;
if (c.get_naipe() == Naipe::COPAS){
    naipe = "C";
} else if (c.get_naipe() == Naipe::OUROS){
    naipe = "O";} else if (c.get_naipe() == Naipe::ESPADAS){
    naipe = "E";} else { naipe = "P"; }
    return valor + naipe; }


    //escreve uma pilha na linha do arquivo
    static void escrever_pilha(std::ofstream& arquivo, const Pilha& pilha) {
    arquivo << pilha.get_quantidade();
    for (int i = 0; i < pilha.get_quantidade(); i++){
        const Carta& c = pilha.get_carta(i);
        arquivo << "," << c.get_valor();
        arquivo << "," << static_cast<int>(c.get_naipe());
        if (c.visivel()){
            arquivo << ",1";
        } else{
            arquivo << ",0";
        }
    }
    arquivo << "\n";
}

//troca virgula por espaço pra leitura ser feita com cin >>
static void trocar_virgulas(std::string& linha) {
    for (char& letra : linha){
        if (letra == ','){
            letra = ' ';
        }
    }
}
    // le a linha do arquivo e coloca as cartas de acordo
    static void ler_pilha(std::ifstream& arquivo, Pilha& pilha, int& total) {
    std::string linha;
    if (!std::getline(arquivo, linha)){
        throw std::runtime_error("Linhas do arquivo incoerentes");
    }
    trocar_virgulas(linha);
//verifica se tem 52 cartas certinho
std::istringstream leitor(linha);
    int quantidade;
    leitor >> quantidade;
    if (leitor.fail() || quantidade < 0 || quantidade > 52){
        throw std::runtime_error("quantidade de cartas incoerente com o baralho");
    }
            //verifica se as cartas foram criadas corretamente e tem todos os elementos
          for (int i = 0; i < quantidade; i++){
        int valor, naipe, visivel;
        leitor >> valor >> naipe >> visivel;
        if (leitor.fail()){
            throw std::runtime_error("carta incompleta");
        }
        // verifica se os elemntos da carta estao dentro do coerente
         if (valor < 1 || valor > 13 || naipe < 0 || naipe > 3){
            throw std::runtime_error("carta com valor ou naipe incoerente");
        } Carta c(valor, static_cast<Naipe>(naipe));
        c.set_visivel(visivel == 1);
        pilha.add_carta(c); 
    }
        total = total + quantidade;
    }



//A PACIENCIA 

//inicia as variavel
Paciencia::Paciencia() {
    _pontuacao = 0;
    _tempo_decorrido = 0;
    _inicio = std::time(nullptr);
    _mensagem = "";
}

//atualiza o tempo decorrido
void Paciencia::att_tempo() {
    _tempo_decorrido = std::time(nullptr) - _inicio;
}

//retorna a pilha correspondente a cada codigo
Pilha& Paciencia::pilha_por_codigo(int codigo, Naipe naipe) {
    if (codigo == ESTOQUE){ return _estoque; }
    if (codigo == DESCARTE){
        return _descarte;}
    if (codigo == FUNDACAO)
    {
        return _fundacao.get_pilha(naipe);
    }
    return _tableau.get_coluna(codigo);
}
//faz a limpa pra começar o novo jogo sem riscos
void Paciencia::iniciar_nova_partida() {
    _tableau = Tableau(); _fundacao = Fundacao();
    _estoque.limpar(); _descarte.limpar();
    _gerenciador_undo.limpe(); _pontuacao = 0;
    _tempo_decorrido = 0;  _inicio = std::time(nullptr);


    //cria as carta
    std::vector<Carta> baralho;
    for(int naipe = 0;  naipe < 4; naipe++)
    { for(int valor = 1; valor <= 13; valor++)
    { baralho.push_back(Carta(valor, static_cast<Naipe>(naipe)));}}

    //embaralha
    for (int i = 51; i > 0; i--){
        int j = std::rand() % (i+1);
        Carta temp = baralho[i];
        baralho[i] = baralho [j];
        baralho[j] = temp;
    }

    //distribui as carta nas coluna
    int proxima = 0;
    for (int coluna = 0; coluna < 7; coluna++){
        for (int i = 0; i <= coluna; i++){
            Carta c = baralho[proxima];
            proxima++;
            if (i == coluna){
                c.set_visivel(true);
            }
            _tableau.get_coluna(coluna).add_carta(c);
        }
    }

    // o resot das cartas vai pro estoque
    while (proxima < 52){
        _estoque.add_carta(baralho[proxima]);
        proxima++;
    }

    _mensagem = "Um novo jogo começou, paciencia e bora pra cima!";
}
//se tem carta no estoque vai pro descarte
    void Paciencia::comprar_carta_estoque() {
    if (!_estoque.esta_vazia()){
        Carta c = _estoque.ver_topo();
        _estoque.transfira_para(_descarte, 1);

        AcaoMovimento acao{ESTOQUE, DESCARTE, c, false, 1, 0};
        _gerenciador_undo.registre_acao(acao);

        _mensagem = "Carta comprada: " + carta_para_texto(_descarte.ver_topo());
        return;
    }

    if (_descarte.esta_vazia()){
        _mensagem = "Nao ha cartas no estoque nem no descarte.";
        return;
    }

    //se o estoque estiver vazio e o descarte nao passa tudo pro estoque
    int quantidade = _descarte.get_quantidade();
    Carta ultima = _descarte.ver_topo();
    while (!_descarte.esta_vazia()){
        _estoque.add_carta(_descarte.remover_topo());
    }
    AcaoMovimento acao{DESCARTE, ESTOQUE, ultima, false, quantidade, 0};
    _gerenciador_undo.registre_acao(acao);

    _mensagem = "Descarte devolvido para o estoque.";
}

//realiza o movimento entra duas pilhas
bool Paciencia::mover(int cod_origem, int cod_destino, int qtd) {
    Pilha& origem = pilha_por_codigo(cod_origem);
    int total = origem.get_quantidade();

    if (total == 0){
        _mensagem = "A pilha de origem ta vazia.";
        return false;
    }
    if (qtd < 1 || qtd > total){
        _mensagem = "Quantidade de cartas incoerente.";
        return false;
    }
    if (!origem.pdp_retire(qtd)){
        _mensagem = "Nao da pra mover essas cartas: elas precisam estar viradas pra cima e formar uma sequencia.";
        return false;
    }

        Carta primeira = origem.get_carta(total - qtd);
    Pilha& destino = pilha_por_codigo(cod_destino, primeira.get_naipe());


        if (!destino.pdp_receba(primeira)){
        _mensagem = destino.satisfacao();
        return false;
    }

    //quando a jogada é valia
      origem.transfira_para(destino, qtd);

       bool revelou = origem.revele_topo();

       int pontos = destino.receba_pontos();
    if (revelou){
        pontos = pontos + 5;
    }
    _pontuacao = _pontuacao + pontos;

    AcaoMovimento acao{cod_origem, cod_destino, primeira, revelou, qtd, pontos};
    _gerenciador_undo.registre_acao(acao);

    _mensagem = "Movimento feito.";
    return true;
}

//filtra as entradas de movimentos
bool Paciencia::mover_coluna_para_coluna(int origem, int destino, int qtd) {
    if (origem < 0 || origem > 6 || destino < 0 || destino > 6){
        _mensagem = "Coluna invalida: use numeros de 1 a 7.";
        return false;
    }
    if (origem == destino){
        _mensagem = "A origem e o destino sao iguais.";
        return false;
    }
    return mover(origem, destino, qtd);
}

bool Paciencia::mover_descarte_para_coluna(int coluna) {
    if (coluna < 0 || coluna > 6){
        _mensagem = "Coluna invalida: use numeros de 1 a 7.";
        return false;
    }
    return mover(DESCARTE, coluna, 1);
}

bool Paciencia::mover_coluna_para_fundacao(int coluna) {
    if (coluna < 0 || coluna > 6){
        _mensagem = "Coluna invalida: use numeros de 1 a 7.";
        return false;
    }
    return mover(coluna, FUNDACAO, 1);
}

bool Paciencia::mover_descarte_para_fundacao() {
    return mover(DESCARTE, FUNDACAO, 1);
}


bool Paciencia::desfaca() {
    if (!_gerenciador_undo.tem_historico()){
        _mensagem = "Nao ha jogadas para desfazer.";
        return false;
    }

    AcaoMovimento acao = _gerenciador_undo.ver_ultima_acao();
    _gerenciador_undo.desfaca();

    Naipe naipe = acao.carta_movida.get_naipe();
    Pilha& origem = pilha_por_codigo(acao.origem, naipe);
    Pilha& destino = pilha_por_codigo(acao.destino, naipe);

    if (acao.origem == DESCARTE && acao.destino == ESTOQUE){
       //compra as cartas denovo
        for (int i = 0; i < acao.quantidade; i++){
            origem.add_carta(destino.remover_topo());
        }
    } else{
        if (acao.carta_revelada){
            origem.esconda_topo();
        }
        destino.transfira_para(origem, acao.quantidade);
    }

    _pontuacao = _pontuacao - acao.pontos;
    _mensagem = "Jogada desfeita.";
    return true;
}

void Paciencia::exiba() {
    att_tempo();
    int minutos = _tempo_decorrido / 60;
    int segundos = _tempo_decorrido % 60;
      std::cout << std::left;

      std::cout << "\n=============== PACIENCIA ===============\n";
    std::cout << "Pontos: " << _pontuacao << "   Tempo: ";
    std::cout << std::setfill('0') << std::setw(2) << minutos << ":";
    std::cout << std::setw(2) << segundos << std::setfill(' ') << "\n\n";
    std::cout << "Estoque: [" << _estoque.get_quantidade() << "]   Descarte: ";
    if (_descarte.esta_vazia()){
        std::cout << "--";
    } else{
        std::cout << carta_para_texto(_descarte.ver_topo());
    }
    std::cout << "\n";

    std::string nomes[4] = {"C", "O", "E", "P"};
    std::cout << "Fundacoes: ";
    for (int i = 0; i < 4; i++){
        const Pilha& pilha = _fundacao.get_pilha(static_cast<Naipe>(i));
        std::string texto = "--";
        if (!pilha.esta_vazia()){
            texto = carta_para_texto(pilha.ver_topo());
        }
        std::cout << nomes[i] << ":" << std::setw(5) << texto;
    }
    std::cout << "\n\n";

    for (int col = 0; col < 7; col++){
        std::cout << std::setw(6) << ("  " + std::to_string(col + 1));
    }
    std::cout << "\n";


    //descobre a coluna maior
    int altura = 0;
    for (int col = 0; col < 7; col++){
        if (_tableau.get_coluna(col).get_quantidade() > altura){
            altura = _tableau.get_coluna(col).get_quantidade();
        }
    }

    //imprime o tableau
    for (int linha = 0; linha < altura; linha++){
        for (int col = 0; col < 7; col++){
            const Pilha& coluna = _tableau.get_coluna(col);
            std::string texto = "";
            if (linha < coluna.get_quantidade()){
                texto = " " + carta_para_texto(coluna.get_carta(linha));
            }
            std::cout << std::setw(6) << texto;
        }
        std::cout << "\n";
    }
    std::cout << "=========================================\n";
}

bool Paciencia::gg() const {
    return _fundacao.gg();
}

int Paciencia::get_pontuacao() const {
    return _pontuacao;
}

int Paciencia::get_tempo() {
    att_tempo();
    return _tempo_decorrido;
}

const std::string& Paciencia::get_mensagem() const {
    return _mensagem;
}

void Paciencia::save(const std::string& caminho_arquivo) {
    att_tempo();

    std::ofstream arquivo(caminho_arquivo);
    if (!arquivo.is_open()){
        _mensagem = "Devido a algum erro nao foi possivel criar o arquivo '" + caminho_arquivo + "'.";
        return;
    }

    arquivo << _pontuacao << "," << _tempo_decorrido << "\n";
    escrever_pilha(arquivo, _estoque);
    escrever_pilha(arquivo, _descarte);
    for (int i = 0; i < 4; i++){
        escrever_pilha(arquivo, _fundacao.get_pilha(static_cast<Naipe>(i)));
    }
    for (int i = 0; i < 7; i++){
        escrever_pilha(arquivo, _tableau.get_coluna(i));
    }

    _mensagem = "Partida salva em '" + caminho_arquivo + "'.";
}

void Paciencia::load(const std::string& caminho_arquivo) {
    std::ifstream arquivo(caminho_arquivo);
    if (!arquivo.is_open()){
        _mensagem = "Erro: arquivo '" + caminho_arquivo + "' nao encontrado.";
        return;
    }

    Tableau novo_tableau;
    Fundacao nova_fundacao;
    Estoque novo_estoque;
    Descarte novo_descarte;
    int nova_pontuacao = 0;
    int novo_tempo = 0;
    int total = 0;

    //verifica se esta tudo certo no arquivo a ser lido
    try{
        std::string linha;
        if (!std::getline(arquivo, linha)){
            throw std::runtime_error("arquivo vazio");
        }
        trocar_virgulas(linha);
        std::istringstream leitor(linha);
        leitor >> nova_pontuacao >> novo_tempo;
        if (leitor.fail()){
            throw std::runtime_error("pontuacao ou tempo invalidos");
        }

        ler_pilha(arquivo, novo_estoque, total);
        ler_pilha(arquivo, novo_descarte, total);
        for (int i = 0; i < 4; i++){
            ler_pilha(arquivo, nova_fundacao.get_pilha(static_cast<Naipe>(i)), total);
        }
        for (int i = 0; i < 7; i++){
            ler_pilha(arquivo, novo_tableau.get_coluna(i), total);
        }
         if (total != 52){
            throw std::runtime_error("o baralho nao tem 52 cartas");
        }
    } catch (const std::exception& erro){
        _mensagem = "Erro: o arquivo '" + caminho_arquivo + "' esta com problema (" + erro.what() + ").";
        return;
    }
// troca os antigos pelos do save
        _tableau = novo_tableau;
    _fundacao = nova_fundacao;
    _estoque = novo_estoque;
    _descarte = novo_descarte;
    _pontuacao = nova_pontuacao;
    _tempo_decorrido = novo_tempo;
    _inicio = std::time(nullptr) - novo_tempo;
    _gerenciador_undo.limpe();

    _mensagem = "Obriado pela Paciencia! partida carregada de '" + caminho_arquivo + "'.";
}