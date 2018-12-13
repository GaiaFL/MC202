#include "grafo.h"

p_grafo criar_grafo(int tam){
  p_grafo g;
  int i;
  g = malloc(sizeof(Grafo));
  if(g  == NULL)
    exit(1);
  g->adjacencia = malloc(tam * sizeof(No));
  if(g->adjacencia == NULL)
    exit(1);
  g->n = tam;
  for(i=0; i<tam; i++){
    g->adjacencia[i] = NULL;/*Seta todas as posições, da lista ligada, voltadas pra 'NULL'*/

  }
  return g;
}

void libera_lista(p_no lista){/*Desaloca a lista ligada de cada posição de maneira recursiva*/
  if (lista != NULL) {
    libera_lista(lista ->prox);
    free(lista);
  }
}

void destruir_grafo(p_grafo g){/*Destrói grafo*/
  int i;
  for (i = 0; i < g->n; i++){
    libera_lista(g->adjacencia[i]);/*Libera a lista ligada de cada posição*/
  }
  free(g->adjacencia);/*Libera vetor do grafo*/
  free(g);/*Libera grafo*/
}

p_no insere_na_lista(p_no lista , int v){/*Insere nova relação entre pessoas*/
  p_no novo = malloc(sizeof(No));
  if(novo == NULL)
    exit(1);
  novo->v = v;
  novo->prox = lista;/*Aponta para elemento inicial da lista*/
  novo->flag = 0;/*Seta situação como não entediado*/
  return novo;
}

void insere_aresta(p_grafo g, int u, int v){/*Insere nova relação entre duas pessoas*/
  g->adjacencia[v] = insere_na_lista(g->adjacencia[v], u);
  g->adjacencia[u] = insere_na_lista(g->adjacencia[u], v);
}

int tem_aresta(p_grafo g, int u, int v){/*Verifica se há alguma ligação entre duas pessoas*/
  p_no temp;
  for(temp = g->adjacencia[u]; temp != NULL; temp = temp->prox){
    if(temp->v == v){/*Se tiver*/
      return 1;/*Retorna 'True'*/
    }
  }
  return 0;/*Retorna 'False'*/
}

void imprime_arestas(p_grafo g){/*Imprime posição das pessoas entediadas*/
  int u;
  for(u=0; u<g->n; u++){
    if(g->adjacencia[u]->flag == 1)/*Verifica se a pessoa está entediada*/
      printf("%d\n", u);/*Se tiver, imprime sua posição*/
  }
}
