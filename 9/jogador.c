#include "jogador.h"
#include <stdlib.h>
#include <stdio.h>

int *criarvetor(int tam){
  int *vetor;
  vetor = calloc(tam, sizeof(int));
  if(vetor == NULL){
    exit(1);
  }
  return vetor;
}

int numera_carta(char *carta){
  int valor;
  if((carta[0] >= '0' && carta[0] <= '9') || (carta[0] == 1 && carta[1] == 0)){
    valor = atoi(carta);
  }else if(carta[0] >= 'D' && carta[0] <= 'V'){
    valor = 10;
  }else{
    valor = 11;
  }
  return valor;
}

void resto(p_fila f, int *v){
  int pos, deck;
  if(f != NULL){
    while(f->ini != NULL){
      deck = f->ini->mao;
      pos = f->ini->play;
      v[pos] = deck;
      desenfileira(f);
    }
  }
}

void imprimir(int *v, int tam){
  int i;
  for(i=0; i<tam; i++){
    printf("%d\n", v[i]);
  }
}

void liberar_vetor(int *v){
  free(v);
}
