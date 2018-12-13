#include "treap.h"

int main(){
  int n_conjuntos, n_elementos, elemento, i, j;
  p_no raiz1, raiz2, raiz3;
  raiz1 = raiz2 = raiz3 = NULL;
  scanf("%d", &n_conjuntos);
  for(i = 0; i<n_conjuntos; i++){
    if(raiz1 == NULL){/*Primeiro conjunto*/
      scanf("%d", &n_elementos);
      for(j=0; j<n_elementos; j++){
        scanf("%d", &elemento);
        raiz1 = inserir(raiz1, elemento);/*Adiciona elemento na árvore*/
      }
    }else{/*Segundo conjunto*/
      scanf("%d", &n_elementos);
      for(j=0; j<n_elementos; j++){
        scanf("%d", &elemento);
        raiz2 = inserir(raiz2, elemento);/*Adiciona elemento na árvore*/
      }
      raiz3 = comparar(raiz1, raiz2, raiz3);/*Árvore da diferença simétrica*/
      raiz3 = comparar(raiz2, raiz1, raiz3);
      raiz1 = liberar_arvore(raiz1);/*Libera primeiro conjunto*/
      raiz2 = liberar_arvore(raiz2);/*Libera segundo conjunto*/
      free(raiz2);
      raiz2 = NULL;
      raiz1 = clonar(raiz3);/*primeiro conjunto passa a ser a diferença simétrica*/
      raiz3 = liberar_arvore(raiz3);/*Libera a árvore temporária*/
      free(raiz3);
      raiz3 = NULL;
    }
  }
  imprime(raiz1);/*Imprime a diferença simétrica em ordem descrescente*/
  printf("\n");
  raiz1 = liberar_arvore(raiz1);/*Libera árvore da diferença simétrica*/
  free(raiz1);
  raiz1 = NULL;
  return 0;
}
