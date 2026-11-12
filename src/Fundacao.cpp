#include "Fundacao.hpp"
#include <stdexcept>

// uma pilha por naipe(tive que mudar a ordem que elas tavam sendo criadas pra nao dar erro)
Fundacao::Fundacao()
{
    _pilhas_naipe.push_back(PilhaFundacao(Naipe::COPAS));
    _pilhas_naipe.push_back(PilhaFundacao(Naipe::OUROS));
    _pilhas_naipe.push_back(PilhaFundacao(Naipe::ESPADAS));
    _pilhas_naipe.push_back(PilhaFundacao(Naipe::PAUS));
}
Pilha &Fundacao::get_pilha(Naipe naipe) { return _pilhas_naipe[static_cast<int>(naipe)]; }

const Pilha &Fundacao::get_pilha(Naipe naipe) const { return _pilhas_naipe[static_cast<int>(naipe)]; }

// verifica se as pilah tao completa e declara a win
bool Fundacao::gg() const
{
    for (int i = 0; i < 4; i++)
    {
        if (_pilhas_naipe[i].get_quantidade() != 13)
        {
            return false;
        }
    }
    return true;
}