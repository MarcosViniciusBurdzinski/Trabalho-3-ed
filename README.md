# Lista 3 da disciplina de Estrutura de dados

## Autores
Marcos Vinicius Burdzinski e Pedro Henrique de Abreu Duailibe

## Descrição

Este projeto implementa um sistema de Matchmaking para o pareamento de grupos de jogadores com base no score. O sistema mantém uma lista de espera e tem as seguintes funcionalidades:

- Adiciona jogadores à fila de espera
- Remove jogadores da lista de espera
- Forma grupos de tamanho solicitado respeitando um delta de score
- Exibe os jogadores na lista de espera
- Permite fazer uma cópia dos jogadores na lista de espera

## Instruções de compilação

O main pode ser executado com uma única linha de código:
``` bash
g++ main.cpp Matchmaking.cpp Player.cpp -o matchmaking
./matchmaking
```
Ou da forma menos enxuta, porém ainda funcional: 
``` bash
g++ -c Player.cpp -o Player.o
g++ -c Matchmaking.cpp -o Matchmaking.o
g++ -c main.cpp -o main.o
g++ Matchmaking.o Player.o main.o -o matchmaking
./matchmaking
```

## Organização do projeto

O projeto foi modularizado de forma a dividi-lo em partes menores, cada uma com seu propósito, facilitando o entendimento e extensão do código:

### Player.hpp 
Define a classe Player, seus atributos e métodos, enquanto o Player.cpp implementa tais métodos. 

### Matchmaking.hpp
Estrutura o sistema de matchmaking para o pareamento de players com habilidades semelhantes para jogarem, enquanto o Matchmaking.cpp contém a implementação das funcionalidades.

### main.cpp
Driver code que demonstra o funcionamento do programa. Simula um matchmaking de damas e outro de xadrez, fazendo vários testes, como inserir, remover, parear, exibir jogadores.

## Como executar os testes

Para demonstrar o funcionamento do programa, o main.cpp contém um exemplo real de um matchmaking de xadrez e outro de damas. Simulando uma situação real onde jogadores entram e saem da fila de espera, são pareados e jogam, vários testes em sequência são executados. Dado as instruções de compilação, execute o programa:
``` bash 
./matchmaking
```
Para cada teste a ser realizado, temos a mensagem:
``` bash
Deseja prosseguir?
Sim (1) \\ Não (0)
Sua resposta:
```
Digitando 1, você parte para o próximo teste. Digitando 0, você finaliza o programa. Para ter a experiência completa, prossiga até o final. 