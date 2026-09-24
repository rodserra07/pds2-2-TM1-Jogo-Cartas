User Stories (Jogo Paciência / Solitaire)



1: Iniciar Nova Partida e Distribuir Tabuleiro

Descrição: Como Jogador, quero iniciar uma nova partida com 52 cartas embaralhadas e distribuídas automaticamente.

Critérios de Aceitação:







* O sistema deve criar um baralho padrão de 52 cartas e embaralhá-lo toda vez que um jogo for iniciado.
* O sistema deve distribuir as cartas nas 7 colunas mantendo apenas a carta do topo virada para cima.
* As 24 cartas que sobrarem devem ser colocadas na pilha de compra.
* As 4 pilhas de fundação devem começar vazias.



2: Movimentar Cartas entre Colunas do Tableau

Descrição: Como Jogador, quero mover de forma intuitiva as cartas abertas entre as colunas para organizar as sequências numéricas e revelar cartas escondidas.

Critérios de Aceitação:



* O sistema deve permitir mover uma carta para outra coluna apenas se a carta de destino for de valor um número maior e de cor oposta.
* Apenas a carta do Rei ou um grupo de cartas começado por Rei pode ser movido para uma coluna vazia.
* Ao tirar a última carta aberta de uma coluna, a carta virada para baixo que estava atrás deve ser virada para cima automaticamente.
* Se a jogada for inválida, o sistema deve impedir o movimento e mostrar uma mensagem avisando o jogador sobre qual foi o erro.





3: Comprar Cartas do Estoque

Descrição: Como Jogador, quero poder tirar cartas do monte de compra para a pilha de descarte quando não houver jogadas na mesa.

Critérios de Aceitação:



* Ao clicar na pilha de compra, o sistema deve mover a carta do topo do Estoque para a pilha de Descarte, mantendo ela virada para cima.
* Apenas a carta do topo da pilha de Descarte pode ser movida para as colunas do jogo ou para a Fundação.
* Quando o Estoque acabar, o jogador pode reiniciar o monte, movendo todas as cartas do Descarte de volta para o Estoque do mesmo jeito que estavam.



4: Enviar Cartas para a Fundação

Descrição: Como Jogador, quero mover cartas organizadas para as pilhas de fundação para avançar no jogo e vencer.

Critérios de Aceitação:



* As fundações devem ser separadas por naipe.
* ma pilha de fundação vazia só pode receber uma carta do tipo Ás do seu naipe.
* O sistema deve avisar a vitória quando todas as 4 fundações tiverem 13 cartas cada.



5: Desfazer Última Jogada (Undo)

Descrição: Como Jogador, quero poder desfazer minhas jogadas para corrigir erros estratégicos.

Critérios de Aceitação:



* O sistema deve ter a opção de "Desfazer" que volta a última ação realizada.
* A volta da jogada deve restaurar o estado das cartas, incluindo se estavam viradas para cima ou para baixo.
* O sistema deve permitir desfazer vários movimentos seguidos guardados no histórico do jogo.
* Caso não haja movimentos no histórico, a opção deve ficar desativada ou avisar que não há o que desfazer.



6: Salvar e Carregar Partida Salva

Descrição: Como Jogador, quero salvar meu progresso em arquivo e recarregá-lo para poder sair e voltar pro jogo sempre que eu quiser.

Critérios de Aceitação:

* O sistema deve permitir salvar o estado atual das pilhas, tempo decorrido e pontuação em um arquivo csv.
* A opção de carregar jogo deve ler o arquivo salvo e recriar exatamente a mesa no ponto onde foi salva.
* Caso o arquivo de salvamento não exista ou esteja com problema, o sistema deve mostrar uma mensagem de erro para o jogador sem fechar o jogo.

