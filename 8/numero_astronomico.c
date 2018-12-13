#include "numero_astronomico.h"
#include <stdio.h>
#include <stdlib.h>

listinha criar_calculadora(){
  listinha calculadora;
  calculadora = malloc(sizeof(lista));
  if(calculadora == NULL){
    exit(1);
  }
  calculadora->ini = calculadora->fim = NULL;
  return calculadora;
}

void insere_ini(listinha calculadora, int x){
  p_no digito;
  digito = malloc(sizeof(No));
  if(digito == NULL){
    exit(1);
  }
  digito->numero = x;
  digito->ant = NULL;
  digito->prox = calculadora->ini;
  calculadora->ini->ant = digito;
  calculadora->ini = digito;
}

void insere_fim(char num, listinha calculadora){
  p_no digito;
  int valor = num - '0';
  digito = malloc(sizeof(No));
  if(digito == NULL){
    exit(1);
  }
  digito->numero = valor;
  digito->prox = NULL;
  if(calculadora->ini == NULL){
    digito->ant = NULL;
    calculadora->ini = calculadora->fim = digito;
  }else{
    digito->ant = calculadora->fim;
    calculadora->fim->prox = digito;
    calculadora->fim = digito;
  }
}

void soma(listinha calculadora, listinha calculadora2){
  p_no atual = calculadora->fim;/*começa da menor casal decimal*/
  p_no atual2 = calculadora2->fim;
  int valor, valor2;
  while(atual != NULL && atual2 != NULL){
    valor = atual->numero;
    valor2 = atual2->numero;
    atual->numero = valor+valor2;/*emparelha os valores de mesma posição nos dois números*/
    atual = atual->ant;
    atual2 = atual2->ant;
  }
  if(atual2 != NULL){
    while(atual2 != NULL){
      insere_ini(calculadora, atual2->numero);
      atual2 = atual2->ant;
    }
  }
}

void confere(listinha calculadora){
  p_no atual = calculadora->fim;
  int adicionar;
  while(atual != NULL){
    if(atual->numero > 9){/*verifica se o número é entre 0 e 9*/
      adicionar = atual->numero / 10;
      atual->numero = atual->numero % 10;
      if(atual->ant == NULL){
        insere_ini(calculadora, adicionar);
      }else{
        atual->ant->numero += adicionar;
      }
    }
    atual = atual->ant;
  }
}

void imprimir(listinha calculadora){
  p_no atual = calculadora->ini;
  while(atual->numero == 0){/*não imprimir as casas de maior valor vazias*/
    atual = atual->prox;
  }
  while(atual != NULL){/*imprime na ordem da maior pra menor casa decimal*/
    if(atual->prox == NULL){
      printf("%d\n", atual->numero);
    }else{
      printf("%d", atual->numero);
    }
    atual = atual->prox;
  }
}

void destruir_calculadora(listinha calculadora){
  p_no atual = calculadora->ini;
  p_no prox;
  if(calculadora->ini == NULL){/*verifica se a calculadora já está vazia*/
    return;
  }
  while(atual != NULL){
    prox = atual->prox;
    free(atual);
    atual = prox;
  }
  calculadora->ini = calculadora->fim = NULL;
}
