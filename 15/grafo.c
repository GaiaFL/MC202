#include "grafo.h"

p_grafo criar_grafo(int tam){/*Aloca grafo na memória*/
  p_grafo g;
  int i;
  g = malloc(sizeof(Grafo));/*Aloca grafo*/
  if(g == NULL)
    exit(1);
  g->adjacencia = malloc(tam * sizeof(No));/*Aloca vetor do grafo*/
  if(g->adjacencia == NULL)
    exit(1);
  g->n = tam;
  for(i=0; i<tam; i++){
    g->adjacencia[i] = NULL;/*Seta todas as posições, da lista ligada, voltadas pra 'NULL'*/
  }
  return g;
}

p_no insere_na_lista(p_no lista , int v){/*Insere nova relação entre pessoas*/
  p_no novo = malloc(sizeof(No));
  if(novo == NULL)
    exit(1);
  novo->v = v;
  novo->prox = lista;/*Aponta para elemento inicial da lista*/
  return novo;
}

void insere_aresta(p_grafo g, int u, int v){/*Insere nova relação entre duas pessoas*/
  g->adjacencia[v] = insere_na_lista(g->adjacencia[v], u);
  g->adjacencia[u] = insere_na_lista(g->adjacencia[u], v);
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
