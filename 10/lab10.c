#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){
  p_no raiz = criar_arvore(NULL, NULL);/*Inicializa nova árvore*/
  raiz = montagem(raiz);/*Coloca os valores pra cada nó, bem como cria eles*/
  inordem(raiz);/*otimização das expressões da árvore*/
  imprime_inordem(raiz);/*Imprime nova árvore*/
  printf(" ");/*Espaço final*/
  printf("\n");/*Quebra de linha final*/
  raiz = liberar_arvore(raiz);/*Destrói árvore*/
  free(raiz);/*Destrói raiz*/
  return 0;
}
