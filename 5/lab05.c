#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char nome[31];
  int telefone;
} pessoa;

pessoa *ordenar(pessoa *vetor, int len){
  int j, k, safe;
  char safe2[30];
  for(j=0;j<len;j++){
    for(k=j;k<len;k++){
      if(vetor[j].telefone>vetor[k].telefone){
        safe = vetor[j].telefone;
        vetor[j].telefone = vetor[k].telefone;
        vetor[k].telefone = safe;
        strcpy(safe2, vetor[j].nome);
        strcpy(vetor[j].nome, vetor[k].nome);
        strcpy(vetor[k].nome, safe2);
      }
    }
  }
 return vetor;
}

pessoa *transpor(pessoa *velho, int len){/*transpõe o conteúdo do vetor para aumentar seu tamanho*/
  pessoa *novo = malloc(len*sizeof(pessoa));
  int i;
  for(i=0;i<len;i++){
    strcpy(novo[i].nome, velho[i].nome);
    novo[i].telefone = velho[i].telefone;
  }
  free(velho);
  velho = malloc(len*2*sizeof(pessoa));
  for(i=0;i<len;i++){
   strcpy(velho[i].nome, novo[i].nome);
   velho[i].telefone = novo[i].telefone;
  }
  return velho;
}

int main(){
  pessoa *premiado = malloc(4*sizeof(pessoa));
  int i = 0, tam = 4, comp, numero;
  while(1){
    scanf("%s %d", premiado[i].nome, &premiado[i].telefone);
    comp = strcmp(premiado[i].nome, "fim");
    if(comp==0){
     numero = premiado[i].telefone;
     premiado = ordenar(premiado, i);/*só compara as casas preenchidas*/
     break;
    }
    i++;
    if(i==tam){
      premiado = transpor(premiado, tam);
      tam = 2*tam;
    }
  }
  printf("%s %d\n", premiado[numero-1].nome, premiado[numero-1].telefone);
  free(premiado);
  return 0;
}
