#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arvore.h"
#define MAX 21


p_no criar_arvore(p_no esq, p_no dir){/*Aloca novo nó*/
  p_no r = malloc(sizeof(No));
  if(r == NULL){
    exit(1);
  }
  r->valor = malloc(MAX * sizeof(char));
  if(r->valor == NULL){
    exit(1);
  }
  r->esq = esq;
  r->dir = dir;
  return r;
}

p_no montagem(p_no no){/*Coloca valores nos nós*/
  char buf[MAX];
  scanf("%s", buf);
  if(buf[0] == '('){
    no->esq = criar_arvore(NULL, NULL);
    no->esq = montagem(no->esq);
    no = montagem(no);
    no->dir = criar_arvore(NULL, NULL);
    no->dir = montagem(no->dir);
    scanf("%s", buf);/*Pegar o ')'*/
  }else{
    strcpy(no->valor, &buf[0]);
    return no;
  }
  return no;
}

int n_eh_vazio(p_no no){/*Verifica se o nó não é vazio*/
  if(no == NULL){
    return 0;
  }
  return 1;
}

int eh_numero(char *x){/*Verifica se o valor do nó é um número*/
  if(x[0] >= '0' && x[0] <= '9'){
    return 1;
  }else if( x[0] == '-' && x[1] >= '0' && x[1] <= '9'){
    return 1;
  }else{
    return 0;
  }
  return 0;
}

char *operacao(int x, int y, char operador){/*Realiza a operação entre dois nós*/
  int soma;
  char *final = malloc(MAX * sizeof(char));/*vetor do resultado final*/
  if(operador == '+'){
    soma = y + x;
  }else if(operador == '-'){
    soma = y-x;
  }else if(operador == '/'){
    soma = y / x;
  }else{
    soma = y * x;
  }
  sprintf(final, "%d", soma);/*copia para o vetor o novo valor*/
  return final;
}

void inordem(p_no no){/*Otimiza as expressões matemáticas da árvore*/
  int n1, n2;
  char *resultado;
  if(no != NULL){
    inordem(no->esq);
    inordem(no->dir);
    if(n_eh_vazio(no->dir) && n_eh_vazio(no->esq)){
      if(eh_numero(no->dir->valor) && eh_numero(no->esq->valor)){
        n1 = atoi(no->dir->valor);
        n2 = atoi(no->esq->valor);
        resultado = operacao(n1, n2, no->valor[0]);
        strcpy(no->valor, resultado);
        free(no->dir->valor);
        free(no->dir);
        no->dir = NULL;
        free(no->esq->valor);
        free(no->esq);
        no->esq = NULL;
        free(resultado);
      }
    }
  }
}

void imprime_inordem(p_no no){/*Imprime nova árvore*/
  if(no->esq == NULL && no->dir == NULL){
    printf("%s", no->valor);
    return;
  }
  printf("( ");
  imprime_inordem(no->esq);
  printf(" ");
  printf("%s", no->valor);
  printf(" ");
  imprime_inordem(no->dir);
  printf(" )");
}

p_no liberar_arvore(p_no no){/*Destrói árvore*/
  if(no == NULL){
    return NULL;
  }
  no->esq = liberar_arvore(no->esq);
  no->dir = liberar_arvore(no->dir);
  if(no->esq == NULL && no->dir == NULL){
    free(no->valor);
    free(no);
    no = NULL;
  }
  return no;
}
