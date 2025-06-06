# 1 Caso de Uso: Ativar carta

## 1.1 Objetivo

Permitir que um ator (Jogador ou Sistema/Inimigo) selecione uma carta, valide as condições de uso, escolha um ou mais alvos (se necessário), pague seus custos e aplique seus efeitos no jogo.

## 1.2 Requisitos

* O sistema deve verificar se o jogador ou sistema tem mana suficiente para utilizar a carta.
* O sistema deve validar o alvo do efeito da carta.
* O sistema deve deduzir mana de acordo com o efeito da carta.
* O sistema deve aplicar o efeito da carta nos alvos selecionados.
* O sistema deve mover a carta da mão do jogador para a pilha de descarte.
* O sistema deve verificar se um personagem foi derrotado como resultado do efeito da carta.
* O sistema deve fornecer feedback ao jogador em caso de falha na ativação da carta (ex: mana insuficiente, alvo inválido).

## 1.3 Atores

- Jogador.
- Sistema (agindo como oponentes/inimigos).

## 1.4 Prioridade

Alta (principal caso de uso dentro de um turno de combate).

## 1.5 Pré-condições

* Um jogo está em andamento e o **Caso de Uso 2: Jogar Turno** está ativo.
* É o turno do ator (jogador ou inimigo) em uma rodada de combate.
* O ator está na sua "Fase de Ações" (conforme definido no Fluxo Principal do UC2).
* O ator possui pelo menos uma carta na mão.

## 1.6 Frequência de Uso

Muito alta.

## 1.7 Criticalidade

Alta (Falhas durante esse caso de uso impedem a jogabilidade e progressão).

## 1.8 Condição de Entrada

O ator (jogador ou inimigo) seleciona uma carta de sua mão com a intenção de ativá-la.

## 1.9 Fluxo Principal

1. O ator seleciona uma das cartas de sua mão.

2. O sistema verifica se o ator possui mana suficiente para o custo da carta. (Se não tiver, o fluxo desvia para **FA1: Mana Insuficiente**).

3. O sistema identifica que a carta requer um alvo. (Caso a carta não necessite de alvo, o fluxo desvia para **FA2: Carta Sem Alvo**).

4. O ator seleciona um alvo para a carta.

5. O sistema valida o alvo selecionado. (Se alvo for inválido, o fluxo desvia para **FA3: Alvo Inválido**).

6. O sistema deduz o custo de mana do ator.

7. O sistema move a carta da mão do ator para o descarte.

8. O sistema aplica o efeito da carta no alvo (ex: calcula dano, cura, etc.).

9. O sistema atualiza a interface para refletir as mudanças (pontos de vida, mana, etc.).

10. O sistema verifica se o alvo foi derrotado. (Esta verificação é importante para o Caso de Uso 2: Jogar Turno, que determinará o fim do combate).

11. O caso de uso é concluído com sucesso.

## 1.10 Fluxo Alternativo

### FA1: Mana Insuficiente

1. No Fluxo Principal (passo 2), o sistema detecta que o ator não possui mana suficiente.

2. O sistema exibe uma mensagem de feedback (ex: Mana Insuficiente).

3. A carta não é ativada e permanece na mão do ator.

4. O caso de uso termina e o controle retorna ao **Caso de Uso 2**, onde o ator pode escolher outra ação.

### FA2: Carta Sem Alvo (Efeito em Área ou Autoaplicada)

1. O ator seleciona uma carta que não requer um alvo específico (ex: comprar cartas, ataque em área, buff).

2. O sistema verifica os recursos (passo 2 do Fluxo Principal).

3. Como a carta não requer um alvo, os passos 3, 4 e 5 do Fluxo Principal são pulados.

4. O fluxo continua a partir do passo 7 do Fluxo Principal, aplicando os efeitos aos alvos pré-definidos.

### FA3: Alvo Inválido

1. No Fluxo Principal (passo 5), o sistema detecta que o alvo selecionado não é válido (ex: tentar curar um inimigo).

2. O sistema exibe uma mensagem de feedback (ex: Alvo Inválido).

3. O sistema permite que o ator escolha outro alvo(retornando ao passo 4 do Fluxo Principal) ou cancele a ativação da carta (ver FA4).

### FA4: Ator Cancela a Ativação

1. A qualquer momento antes da confirmação da ação, o ator decide cancelar a ativação (ex: clicando com o botão direito).

2. A carta retorna ao seu estado normal na mão do ator.

3. O caso de uso termina sem que nenhuma alteração de estado (mana, descarte) tenha ocorrido. O controle retorna ao **Caso de Uso 2**.


## 1.11 Pós-condições

* **Carta ativada**: A carta foi retirada da mão do ator. Sua mana foi deduzida. O efeito da carta foi realizado sobre os alvos. O estado do jogo está atualizado (pontos de vida, mana, etc.).

* **Falha ou Cancelamento**: Nenhuma alteração de estado do jogo ocorre (mana e carta permanecem com o ator). O controle retorna ao UC2, e o ator está livre para escolher outra ação.

## 1.12 Regras de Negócio

* Uma carta só pode ser ativada se o ator possuir mana em quantidade igual ou superior ao seu custo.

* Uma carta ativada é movida ao descarte.