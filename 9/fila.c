#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

p_fila criarfila(){
  p_fila f;
  f = malloc(sizeof(Fila));
  if(f == NULL){
    exit(1);
  }
  f->ini = f->fim = NULL;
  f->tam = 0;
  return f;
}

void enfileira(p_fila f, int x){
  p_no novo;
  novo = malloc(sizeof(No));
  if(novo == NULL){
    exit(1);
  }
  novo->as =  0;
  novo->mao = x;
  if(x == 11){
    novo->as++;
  }
  novo->play = f->tam;
  f->tam++;
  novo->prox = NULL;
  if(f->ini == NULL){
    f->ini = novo;
  }else{
    f->fim->prox = novo;
  }
  f->fim = novo;
}

void desenfileira(p_fila f){
  p_no primeiro;
  primeiro = f->ini;
  f->ini = f->ini->prox;
  free(primeiro);
}

void troca(p_fila f){
  f->fim->prox = f->ini;
  f->fim = f->ini;
  f->ini = f->ini->prox;
  f->fim->prox = NULL;
}

int soma(int nova_mao, int x){
  return nova_mao + x;
}

void liberar_fila(p_fila f){
  free(f);
}
