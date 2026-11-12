# Cartões CRC (Jogo Paciência / Solitaire)

## Carta

**Responsabilidades:**
* Guardar valor (1 a 13), naipe e cor
* Definir a cor a partir do naipe
* Recusar valores fora de 1 a 13
* Informar se está virada para cima ou para baixo
* Virar para cima ou para baixo
* Comparar a cor com outra carta

**Colaboradores:**
* Nenhum


## Pilha

**Subclasses:** Coluna, Estoque, Descarte, PilhaFundacao

**Responsabilidades:**
* Guardar uma sequência de cartas
* Colocar uma carta no topo
* Remover e devolver a carta do topo
* Ver a carta do topo sem remover
* Acessar uma carta por posição
* Informar a quantidade de cartas e se está vazia
* Limpar todas as cartas
* Transferir cartas do topo para outra pilha
* Esconder a carta do topo
* Definir as regras padrão de receber e retirar cartas, mensagem de erro, pontos e revelar topo

**Colaboradores:**
* Carta


## Coluna

**Superclasse:** Pilha

**Responsabilidades:**
* Aceitar só Rei quando vazia
* Aceitar carta de valor uma unidade menor e cor oposta ao topo
* Permitir retirar um grupo só se estiver aberto, decrescente e com cores alternadas
* Revelar a carta do topo quando estiver escondida
* Explicar por que recusou uma carta

**Colaboradores:**
* Carta


## Estoque

**Superclasse:** Pilha

**Responsabilidades:**
* Guardar as cartas de compra viradas para baixo
* Recusar receber cartas por movimento comum
* Recusar que o jogador retire cartas diretamente
* Explicar por que recusou uma carta

**Colaboradores:**
* Carta


## Descarte

**Superclasse:** Pilha

**Responsabilidades:**
* Guardar as cartas compradas viradas para cima
* Recusar receber cartas por movimento comum
* Liberar apenas a carta do topo para jogar
* Explicar por que recusou uma carta

**Colaboradores:**
* Carta


## PilhaFundacao

**Superclasse:** Pilha

**Responsabilidades:**
* Guardar o naipe da pilha
* Aceitar o Ás quando vazia
* Aceitar só a próxima carta do mesmo naipe em ordem crescente
* Manter as cartas viradas para cima
* Dar 10 pontos por carta recebida
* Explicar por que recusou uma carta

**Colaboradores:**
* Carta


## Tableau

**Responsabilidades:**
* Criar e gerenciar as 7 colunas
* Dar acesso a uma coluna pelo índice
* Recusar índices de coluna inválidos
* Validar se uma carta pode entrar em uma coluna
* Mover cartas de uma coluna para outra
* Revelar o topo de uma coluna

**Colaboradores:**
* Coluna
* Carta


## Fundacao

**Responsabilidades:**
* Criar e gerenciar as 4 pilhas, uma por naipe
* Dar acesso à pilha de um naipe
* Validar se uma carta pode entrar na sua pilha
* Inserir uma carta na pilha do seu naipe
* Verificar se as 4 pilhas estão completas (vitória)

**Colaboradores:**
* PilhaFundacao
* Carta


## AcaoMovimento

**Responsabilidades:**
* Guardar origem e destino de uma jogada
* Guardar a primeira carta movida e a quantidade
* Guardar se alguma carta foi revelada
* Guardar os pontos ganhos na jogada

**Colaboradores:**
* Carta


## GerenciadorMovimento

**Responsabilidades:**
* Guardar o histórico de jogadas
* Registrar uma nova jogada
* Devolver a última jogada feita
* Remover a última jogada do histórico
* Informar se ainda há jogadas no histórico
* Apagar o histórico

**Colaboradores:**
* AcaoMovimento


## Paciencia

**Responsabilidades:**
* Criar o baralho de 52 cartas e embaralhar
* Distribuir as cartas nas 7 colunas e no estoque
* Comprar carta do estoque para o descarte
* Devolver o descarte para o estoque quando a compra acabar
* Validar e executar movimentos entre colunas, descarte e fundação
* Revelar a carta da coluna depois de um movimento
* Desfazer jogadas restaurando cartas e pontuação
* Controlar a pontuação e o tempo decorrido
* Exibir o jogo na tela
* Gerar mensagens de erro e de status para o jogador
* Verificar se o jogador venceu
* Salvar e carregar a partida em arquivo csv

**Colaboradores:**
* Tableau
* Fundacao
* Estoque
* Descarte
* Pilha
* GerenciadorMovimento
* AcaoMovimento
* Carta
