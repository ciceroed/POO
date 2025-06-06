# 1 Caso de Uso: Iniciar Jogo

## 1.1 Objetivo

Permitir ao jogador iniciar uma nova partida ou carregar uma partida salva para começar a jogar.

## 1.2 Requisitos

* O sistema deve permitir ao jogador criar um novo jogo.
* O sistema deve permitir ao jogador carregar um jogo salvo existente.
* O sistema deve exibir informações relevantes sobre os jogos salvos (ex: nome do personagem, fase atual).
* O sistema deve permitir ao jogador deletar um jogo salvo.

## 1.3 Atores

Jogador.

## 1.4 Prioridade

Alta.

## 1.5 Pré-condições

* O jogo está em execução.
* O jogador está na tela inicial.

## 1.6 Frequência de Uso

Alta.

## 1.7 Criticalidade

Alta (Fundamental para a experiência do jogador. Se esse caso de uso falhar, o jogador não consegue interagir com o jogo).

## 1.8 Condição de Entrada

O jogador clica no botão de "start".

## 1.9 Fluxo Principal

1. O sistema abre a tela principal, apresentando os jogos salvos com as informações:

    - Nome do personagem.
    - Fase atual.

2. O jogador seleciona qual save deseja utilizar.

3. O sistema carrega os dados da partida (personagem, progresso, fase atual).

4. O jogo é iniciado e o sistema prepara o primeiro turno do jogador.

## 1.10 Fluxo Alternativo

### FA1: Novo Jogo

1. No Fluxo Principal (passo 1), o jogador seleciona a opção "Novo Jogo". (Pode ser a única opção se não houver jogos salvos).

2. O sistema solicita ao jogador a inserção do nome do personagem.

3. O sistema cria um novo estado de jogo com as configurações iniciais padrão.

4. O sistema salva o novo jogo.

5. O sistema exibe a tela da fase inicial.

6. Segue para o passo 4 do fluxo principal (O jogo é iniciado).

---

### FA2: Deletar Jogo Salvo

1. No Fluxo Principal (passo 1), o sistema exibe a opção de deletar um jogo salvo.
2. O jogador seleciona a opção "Deletar" para um jogo salvo específico.
3. O sistema solicita confirmação ao jogador.
4. O jogador confirma a exclusão.
5. O sistema remove o arquivo de jogo salvo do armazenamento.
6. O sistema atualiza a tela de seleção, removendo o jogo deletado da lista.
7. O caso de uso retorna ao passo 1 do Fluxo Principal (exibição da lista atualizada).

## 1.11 Pós-condições

* Sucesso (Jogo Carregado): O jogador está na tela da fase carregada, e o jogo está pronto para o seu primeiro turno. Iniciando de onde havia parado anteriormente.
* Sucesso (Novo Jogo Iniciado): O jogador está na tela da fase inicial, e o jogo está pronto para seu primeiro turno.
* Sucesso (Jogo Deletado): O jogo salvo selecionado foi removido do armazenamento. O jogador é retornado à tela de seleção de jogos.

## 1.12 Regras de Negócio

* O sistema deve comportar um número de espaços para jogos salvos. Se todos estiverem ocupados, o jogador deve deletar um existente para criar um novo, ou o sistema pode oferecer sobrescrever um existente.
* Cada jogo salvo deve armazenar: nome do personagem, fase atual, recursos do jogador (vida, mana, etc.), cartas no deck.
* Deletar um jogo salvo é uma ação permanente e deve ser confirmada pelo jogador.
