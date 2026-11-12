#include "Historico.hpp"
#include <stdexcept>
void Historico::registre_acao(const AcaoMovimento &acao)
{
    _historico.push(acao);
}

// retira a ultima ação do historico
bool Historico::desfaca()
{
    if (_historico.empty())
    {
        return false;
    }
    _historico.pop();
    return true;
}
void Historico::limpe()
{
    while (!_historico.empty())
    {
        _historico.pop();
    }
}

bool Historico::tem_historico() const
{
    return !_historico.empty();
}

const AcaoMovimento &Historico::ver_ultima_acao() const
{
    if (_historico.empty())
    {
        throw std::out_of_range("historico vazio, nao ha acao");
    }
    return _historico.top();
}