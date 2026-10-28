#include "Mover.hpp"

void GerenciadorMovimento::registre_acao(const AcaoMovimento& acao) {
    _historico.push(acao);
}

//isso so retira a ação do historico quiando acontece o undo
bool GerenciadorMovimento::desfaca(){
    if(_historico.empty()){
        return false;
    }
    _historico.pop();
    return true;
}
void GerenciadorMovimento::limpe() {
    while(!_historico.empty()){
        _historico.pop();
    }
}

bool GerenciadorMovimento::tem_historico() const{
    return !_historico.empty(); }

const    GerenciadorMovimento::ver_ultima_acao() const {
    return _historico.top();
}
