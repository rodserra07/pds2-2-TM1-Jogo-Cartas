#ifndef PILHA_FUNDACAO_HPP
#define PILHA_FUNDACAO_HPP

#include "Pilha.hpp"

/**
 * @brief Pilha de fundação.
 */
class PilhaFundacao : public Pilha{
    private:
    Naipe _naipe;
public:
PilhaFundacao(Naipe naipe);

Naipe get_naipe() const;

void add_carta(const Carta& c) override;
bool pdp_receba(const Carta& c) const override;
std::string satisfacao() const override;
int receba_pontos() const override;
};
#endif
