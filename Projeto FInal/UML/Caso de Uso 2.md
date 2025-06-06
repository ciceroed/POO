# 1 Caso de Uso: Jogar turno

## 1.1 Objetivo

Gerenciar o ciclo completo de ações do jogador e as respostas dos inimigos dentro de uma rodada de combate, atualizando o estado do jogo e verificando condições de vitória ou derrota.

## 1.2 Requisitos

* O sistema deve permitir ao jogador ativar uma carta.
* O sistema deve processar as ações dos inimigos de acordo com as lógicas pré-definidas.
* O sistema deve atualizar informações relevantes sobre o estado atual da partida (ex: vida, mana, cartas em jogo) após cada ação.
* O sistema deve determinar o resultado do combate ao final de uma ação ou turno (vitória ou derrota do jogador).
* O sistema deve permitir ao jogador encerrar seu turno, permitindo aos inimigos agirem em seus respectivos turnos.
* O sistema deve exbir informações relevantes sobre o estado atual da partida (ex: vida, mana, cartas na mão do jogador) após cada ação.
* O sistema deve permitir ao jogador salvar e sair do jogo.


## 1.3 Atores

- Jogador.
- Sistema (agindo como oponentes e gerenciador de regras).

## 1.4 Prioridade

Alta.

## 1.5 Pré-condições

* Um jogo está em andamento (Conforme estabelecido pelo Caso de Uso 1: Iniciar Jogo)
* É o início de uma nova rodada de combate ou a rodada anterior foi concluída e o combate ainda não foi encerrado.
* A interface de combate da fase atual está carregada e visível para o jogador.

## 1.6 Frequência de Uso

Muito alta.

## 1.7 Criticalidade

Alta (Falhas durante esse caso de uso impedem a jogabilidade e progressão).

## 1.8 Condição de Entrada

O sistema determina que é o início do turno do jogador (seja no começo da fase ou após o término do turno dos inimigos na rodada anterior).

## 1.9 Fluxo Principal

1. **Inicio do Turno do Jogador:**

    a. O sistema aplica os efeitos de "início de turno" para o jogador (ex: restaura mana, jogador compra uma carta)

    b. O sistema atualiza a interface do usuário exibindo:

    - Sprite e status (vida e mana) do personagem do jogador.

    - Cartas na "mão" do jogador.

    - Sprites e status (vida) dos inimigos.

    - Informações da fase atual.

2. **Fase de Ações do Jogador:**

    a. O sistema aguarda a ação do jogador.

    b. O jogador avalia o estado do jogo e opta por uma ação:

    - **Ativar uma Carta:** O jogador seleciona uma carta da mão. O sistema executa o Caso de Uso 3: Ativar Carta. Se a ativação for bem sucedida (mana suficiente, alvo válido, etc.), os efeitos são resolvidos, mana é deduzida, e a carta é movida ao descarte.

    - **Encerrar o Turno:** O jogador seleciona a opção "Encerrar Turno". O fluxo prossegue para o passo 3.

    c. Após a resolução da ação do jogador:

    - O sistema verifica se todos os inimigos foram derrotados. Se sim, o fluxo desvia para **FA1: Vitória na Fase.**

    d. Se o jogador ainda não encerrou o turno e ainda pode/deseja realizar mais ações (ex: possui mana e cartas jogáveis), o fluxo retorna ao passo 2.b.

3. **Fim do Turno do Jogador / Início do Turno dos Inimigos:**
    
    a. O jogador selecionou "Encerrar Turno".
    
    b. O sistema aplica quaisquer efeitos de "fim de turno" para o jogador.

4. **Fase de Ações dos Inimigos**:

    a. Para cada inimigo ativo (que não foi derrotado), em uma ordem definida:

    - O sistema determina e executa a ação do inimigo (ativar uma carta).

    - O sistema resolve os efeitos da ação do inimigo (ex: deduz vida do jogador).

    - O sistema atualiza a interface com o resultado da ação do inimigo.

    - O sistema verifica se o jogador foi derrotado (Vida do jogador <= 0). Se sim, o fluxo desvia para **FA2: Derrota do jogador.**

    b. Se houver mais inimigos para agir durante a rodada e o jogador não foi derrotado, retorna ao passo 4.a para o próximo inimigo.

5. **Fim da Rodada**:

    a. Se o combate não terminou (nem vitória nem derrota), o caso de uso se prepara para uma nova rodada, retornando ao passo 1 (Inicio do Turno do Jogador).

## 1.10 Fluxo Alternativo

### FA1: Vitória na Fase

1. No Fluxo Principal (Passo 2.c), o sistema detecta que todos os inimigos foram derrotados como resultado de uma ação do jogador.

2. O sistema exibe uma mensagem de "Vitória na Fase!".

3. O sistema concede recompensas ao jogador. (Experiência, novas cartas etc.)

4. O sistema salva o progresso atual do jogo.

5. O sistema prepara e carrega a próxima fase (novos inimigos, ambiente).

6. O caso de uso "Jogar Turno" é encerrado para esta fase.

---

### FA2: Derrota do Jogador (Fim de Jogo)

1. No Fluxo Principal (passo 4.a), o sistema detecta que a vida do jogador é menor ou igual a zero como resultado de uma ação inimiga.

2. O sistema exibe uma mensagem de "Fim de Jogo"

3. O sistema apresenta opções ao jogador(ex: "Tentar Novamente", "Voltar ao Menu Principal").

4. O caso de uso "Jogar Turno" é encerrado.

---

### FA3: Jogador Salva e Sai do Jogo

1. A qualquer momento durante o Fluxo Principal, o jogador aciona uma opção de menu "Salvar e Sair".

2. O sistema pausa a execução do turno atual.

3. O sistema salva o jogo atual.

4. Após o salvamento bem-sucedido, o sistema encerra a partida e retorna o jogador ao Menu Principal.

5. O caso de uso "Jogar Turno" é encerrado abruptamente.

## 1.11 Pós-condições

* **Rodada Concluída (Combate Continua)**: O turno do jogador e dos inimigos foram processados. O estado do jogo (Vida, Mana, Cartas, etc.) está atualizado. O sistema está pronto para iniciar a próxima rodada (novo turno do jogador).

* **Vitória na Fase**: Todos os inimigos foram derrotados. O progresso foi salvo. O jogador recebeu recompensas. O sistema está pronto para a próxima fase.

* **Derrota do Jogador**: O jogo terminou para a sessão atual. O jogador é apresentado com opções de "Fim de Jogo".

* **Jogo Salvo e Encerrado**: O estado atual do jogo foi salvo e o jogador retornou ao menu principal.

## 1.12 Regras de Negócio

* O jogador sempre inicia a rodada.
* O jogador compra 1 carta no início do seu turno, não excedendo o limite de 6 cartas na mão.
* Uma carta só pode ser ativada se o jogador possuir mana igual ou superior ao seu custo e se as condições de alvo da carta forem satisfeitas.
* A ordem de ação dos inimigos é definida por posição.
* Se a Vida do jogador chegar a 0 ou menos, o jogo termina em derrota.
* Se todos os inimigos forem derrotados, a fase é concluída com vitória para o jogador.
* O progresso do jogo é salvo automaticamente ao concluir uma fase com vitória.
* O jogador pode jogar múltiplas cartas em seu turno, desde que tenha mana e cartas válidas.