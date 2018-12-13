#include "heap.h"

int main(){
  int n_caixas, i, peso, med;
  char nome[MAX];
  p_fp Max, Min;
  Item caixa;
  scanf("%d", &n_caixas);
  Max = criar_heap(n_caixas);/*heap de máximo*/
  Min = criar_heap(n_caixas);/*heap de mínimo*/
  for(i=0; i<n_caixas; i++){
    scanf("%s %d", nome, &peso);
    caixa = criar_item(peso, nome);
    if(i==0){
      insere_min(Min, caixa);
    }else{
      if(peso >= med)
        insere_min(Min, caixa);
      else
        insere_max(Max, caixa);
    }
    tamanhos(Min, Max);/*Compara tamanho de heaps*/
    med = pegarmediana(Min, Max);/*Acha a mediana entre dois heaps*/
    imprime(Max, Min);
  }
  destruir(Min);/*Libera memḿoria dos heaps*/
  destruir(Max);
  return 0;
}
