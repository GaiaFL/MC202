#ifndef FILA_H
#define FILA_H

typedef struct No{
  int play;
  int as;
  int mao;
  struct No *prox;
}No;
typedef No *p_no;

typedef struct Fila{
  int tam;
  No *ini, *fim;
}Fila;
typedef Fila *p_fila;

/*
  Cria a fila usada para a rodada

  Saída: fila vazia e pronta pra ser armazenada
*/
p_fila criarfila();

/*
  Armazena em ordem de chegada a primeira carta de cada jogador

  Entrada: f: fila da rodada;
          x: valor da carta;
*/
void enfileira(p_fila f, int x);

/*
  Retira da fila o jogador da posição inicial

  Entrada: f: fila com os jogadores;
*/
void desenfileira(p_fila f);

/*
  Coloca no final o jogador do começo da fila

  Entrada: f: fila com os jogadores;
*/
void troca(p_fila f);

/*
  Retorna os pontos do jogador após a aquisição de uma nova carta

  Entrada: f: fila com os jogadores;
*/
int soma(int nova_mao, int x);

/*
  Destrói a fila

  Entrada: f: fila
*/  
void liberar_fila(p_fila f);

#endif
