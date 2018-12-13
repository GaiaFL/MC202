#ifndef JOGADOR_H
#define JOGADOR_H
#include "fila.h"
#include "pilha.h"

/*
  Cria o vetor de armazenamento dos resultados

  Entrada: tam: número de jogadores da rodada;

  Saída: vetor de armazenamento
*/
int *criarvetor(int tam);

/*
  Transforma a carta de tipo char para tipo int

  Entrada: carta: string da carta dada ao jogadores;

  Saída: A carta no tipo int
*/
int numera_carta(char *carta);

/*
  Armazena e destrói os jogadores que não pediram stand da fila

  Entrada: f: fila de n_jogadores;
          v: vetor de armazenamento dos resultados;
*/
void resto(p_fila f, int *v);

/*
  Imprime os resultados finais de cada jogador

  Entrada: v: vetor dos resultados;
          tam: a quantidade de jogadores da rodada;
*/
void imprimir(int *v, int tam);

/*
  Destrói o vetor de armazenamento de resultados finais

  Entrada: v: vetor dos resultados;
*/  
void liberar_vetor(int *v);

#endif
