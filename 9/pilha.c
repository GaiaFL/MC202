#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

p_pilha criarpilha(int tamanho){
  p_pilha p = malloc(sizeof(Pilha));
  if(p == NULL){
    exit(1);
  }
  p->v = malloc(tamanho*sizeof(int));
  if(p->v == NULL){
    exit(1);
  }
  p->topo = 0;
  return p;
}

void empilhar(p_pilha p, int x){
  p->v[p->topo] = x;
  p->topo++;
}

int desempilhar(p_pilha p){
    p->topo--;
    return p->v[p->topo];
}

void liberar_pilha(p_pilha p){
  free(p->v);
  free(p);
}
